#pragma once
#include "ECS.hpp"
#include "ECSTypes.hpp"
#include "nlohmann/json_utils.hpp"
#include <any>
#include <cassert>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <raylib.h>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>

class ComponentRegistry {
private:
  struct string_hash {
    using is_transparent = void;
    size_t operator()(std::string_view sv) const noexcept {
      return std::hash<std::string_view>{}(sv);
    }
    size_t operator()(const std::string &s) const noexcept {
      return std::hash<std::string>{}(s);
    }
  };

  using DeserializeFunc = std::function<std::any(const json &)>;
  using SerializerFunc = std::function<json(const std::any &)>;
  using AdderFunc = std::function<void(Entity, const json &)>;
  using DefaultJsonFunc = std::function<json()>;

  struct ComponentOps {
    DeserializeFunc deserialize;
    SerializerFunc serialize;
    AdderFunc adder;
    DefaultJsonFunc defaultJson;
  };

  std::unordered_map<std::string, ComponentOps, string_hash, std::equal_to<>>
      operations;
  ECS &gEcs = ECS::Instance();

  ComponentRegistry() { operations.reserve(MAX_COMPONENTS); }

public:
  static ComponentRegistry &Instance() noexcept {
    static ComponentRegistry instance;
    return instance;
  }

  ComponentRegistry(const ComponentRegistry &) = delete;
  ComponentRegistry &operator=(const ComponentRegistry &) = delete;
  ComponentRegistry(ComponentRegistry &&) = delete;
  ComponentRegistry &operator=(ComponentRegistry &&) = delete;

  template <typename T> void Register(const std::string &name) {
    gEcs.RegisterComponent<T>();
    ComponentOps ops;
    ops.deserialize = [](const json &j) -> std::any { return j.get<T>(); };
    ops.serialize = [](const std::any &obj) -> json {
      return std::any_cast<const T &>(obj);
    };
    ops.adder = [this](Entity entity, const json &componentJson) {
      gEcs.AddComponent(entity, componentJson.get<T>());
    };
    ops.defaultJson = []() -> json { return T{}; };
    operations.emplace(name, std::move(ops));
  }

  // Overload: add a pre-built component directly (used for CSprite etc.)
  template <typename T>
  void AddComponent(Entity entity, std::string_view name, const T &component) {
    gEcs.AddComponent(entity, component);
  }

  void AddComponent(Entity entity, std::string_view name, const json &j) {
    if (auto it = operations.find(name); it != operations.end()) {
      it->second.adder(entity, j);
    }
  }

  std::any Deserialize(std::string_view name, const json &j) {
    if (auto it = operations.find(name); it != operations.end()) {
      return it->second.deserialize(j);
    }
    throw std::runtime_error(std::string("Component not registered: ") +
                             std::string(name));
  }

  json Serialize(std::string_view name, const std::any &obj) {
    if (auto it = operations.find(name); it != operations.end()) {
      return it->second.serialize(obj);
    }
    throw std::runtime_error(std::string("Component not registered: ") +
                             std::string(name));
  }

  // Returns a json object mapping component name -> default field values
  [[nodiscard]] json DumpSchema() const {
    json schema;
    for (const auto &[name, ops] : operations) {
      schema[name] = ops.defaultJson();
    }
    return schema;
  }

  // Writes the schema to a file, pretty-printed
  void DumpSchemaToFile(const std::filesystem::path &path) const {
    std::ofstream file(path);
    if (!file.is_open())
      throw std::runtime_error("Failed to open schema file: " + path.string());
    file << std::setw(4) << DumpSchema();
  }

  [[nodiscard]] bool IsRegistered(std::string_view name) const noexcept {
    return operations.find(name) != operations.end();
  }

  [[nodiscard]] size_t GetRegisteredCount() const noexcept {
    return operations.size();
  }
};

#define REFLECTION(Type)                                                       \
  namespace {                                                                  \
  struct Type##_Registrar {                                                    \
    Type##_Registrar() {                                                       \
      ComponentRegistry::Instance().Register<Type>(#Type);                     \
    }                                                                          \
  };                                                                           \
  static Type##_Registrar Type##_registrar_;                                   \
  }

#define COMPONENT(Type, ...)                                                   \
  NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Type, __VA_ARGS__)
