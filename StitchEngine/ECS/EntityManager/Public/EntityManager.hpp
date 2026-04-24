#pragma once

#include "ECSTypes.hpp"
#include <memory>

class EntityManager {
public:
  virtual Entity CreateEntity() = 0;
  virtual void DestroyEntity(Entity entity) = 0;
  virtual const EntityVec &GetAllEntities() const = 0;

  virtual void EntityDestroyed(Entity entity) = 0;
};

std::unique_ptr<EntityManager> CreateEntityManager();
