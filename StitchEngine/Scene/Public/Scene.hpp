#pragma once

#include "ComponentRegistry.hpp"
#include "ECS.hpp"
#include "ECSTypes.hpp"
#include "ResourceManager.hpp"
#include "nlohmann/json_utils.hpp"

#include <filesystem>
#include <fstream>
#include <string>

struct Scene {

private:
  json sceneData{};
  EntityVec entities{};
  ECS &gECS = ECS::Instance();
  ResourceManager &g_resourceManager = GetResourceManager();
  ComponentRegistry &componentRegistry = ComponentRegistry::Instance();

  void CreateEntities() {
    if (!sceneData.contains("entities") || sceneData["entities"].empty())
      return;

    for (const auto &entityJson : sceneData["entities"]) {
      std::string name = entityJson.value("name", "Unnamed");
      Entity entity = gECS.AddEntity();
      entities.push_back(entity);

      if (!entityJson.contains("components") ||
          entityJson["components"].empty())
        continue;
      for (const auto &[componentName, componentData] :
           entityJson["components"].items()) {
        if (componentName == "CSprite") {
          std::string path = componentData["sprite"];
          SpriteId spriteId = g_resourceManager.LoadSprite(path);
        } else {
          componentRegistry.AddComponent(entity, componentName, componentData);
        }
      }
    }
  }

  void DeleteEntities() {
    for (auto &entity : entities) {
      gECS.RemoveEntity(entity);
    }
  }

public:
  Scene(const std::filesystem::path &scenePath) {
    std::ifstream inputFile(scenePath);
    if (!inputFile.is_open()) {
      throw std::runtime_error("Failed to open scene file: " +
                               scenePath.string());
    }

    inputFile >> sceneData;
    inputFile.close();

    CreateEntities();
  }
  void Load() { CreateEntities(); }
  void Unload() { DeleteEntities(); }
};
