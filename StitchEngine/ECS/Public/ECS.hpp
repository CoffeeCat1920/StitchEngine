#pragma once
#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include <memory>
#include <utility>

class ECS {
private:
  EntityManager &entityManager;
  ComponentManager &componentManager;
  SystemManager &systemManager;

  explicit ECS()
      : entityManager(GetEntityManager()),
        componentManager(GetComponentManager()),
        systemManager(GetSystemManager()) {}

public:
  ECS(const ECS &) = delete;
  ECS &operator=(const ECS &) = delete;
  ECS(ECS &&) = delete;
  ECS &operator=(ECS &&) = delete;

  static ECS &Instance() {
    static ECS instance;
    return instance;
  }

  Entity AddEntity() { return entityManager.CreateEntity(); }

  void RemoveEntity(Entity entity) {
    entityManager.EntityDestroyed(entity);
    componentManager.EntityDestroyed(entity);
    systemManager.EntityDestroyed(entity);
  }

  template <typename Component> void RegisterComponent() {
    componentManager.RegisterComponent<Component>();
  }

  template <typename Component>
  void AddComponent(Entity entity, Component component) {
    componentManager.AddComponent<Component>(entity, component);
    Signature signature = componentManager.GetSignature(entity);
    systemManager.EntitySignatureChanged(entity, signature);
  }

  template <typename... ComponentsNames>
  void AddComponents(Entity entity, ComponentsNames... components) {
    (componentManager.AddComponent(entity,
                                   std::forward<ComponentsNames>(components)),
     ...);
    const Signature signature = componentManager.GetSignature(entity);
    systemManager.EntitySignatureChanged(entity, signature);
  }

  template <typename... Components> void RemoveComponents(Entity entity) {
    (componentManager.RemoveComponent<Components>(entity), ...);
    const Signature signature = componentManager.GetSignature(entity);
    systemManager.EntitySignatureChanged(entity, signature);
  }

  template <typename Component> bool HasComponent(Entity entity) {
    return componentManager.HasComponent<Component>(entity);
  }

  template <typename Component> Component &GetComponent(Entity entity) {
    return componentManager.GetComponent<Component>(entity);
  }

  template <typename Component> ComponentId GetComponentId() {
    return componentManager.GetComponentId<Component>();
  }

  template <typename System> void SetSystemSignature(Signature signature) {
    systemManager.SetSignature<System>(signature);
  }

  template <typename System> void SetSystemSignature(ComponentId componentId) {
    systemManager.SetSignature<System>(componentId);
  }

  template <typename System> std::shared_ptr<System> GetSystem() {
    return systemManager.GetSystem<System>();
  }

  template <typename System, typename... Components> void SetSystemSignature() {
    systemManager.SetSignature<System>({GetComponentId<Components>()...});
  }

  template <typename System> std::shared_ptr<System> RegisterSystem() {
    return systemManager.RegisterSystem<System>();
  }

  template <typename System, typename... Components>
  std::shared_ptr<System> RegisterSystemWithSignatures() {
    const auto &system = systemManager.RegisterSystem<System>();
    SetSystemSignature<System, Components...>();
    return system;
  }
};
