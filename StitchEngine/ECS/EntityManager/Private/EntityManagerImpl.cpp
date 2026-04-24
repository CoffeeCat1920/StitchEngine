#include "ECSTypes.hpp"
#include "EntityManager.hpp"
#include <algorithm>
#include <cstdint>
#include <queue>

class EntityManagerImpl : public EntityManager {
private:
  std::queue<Entity> availableEntites{};

  EntityVec livingEntites{};
  uint32_t livingEntityCount = 0;

public:
  EntityManagerImpl() {
    for (int entity = 0; entity < (int)MAX_ENTITIES; entity++) {
      availableEntites.push(entity);
    }
  }

  Entity CreateEntity() override {
    Entity entity = availableEntites.front();
    livingEntites.push_back(entity);
    livingEntityCount++;
    availableEntites.pop();
    return entity;
  }

  void DestroyEntity(Entity entity) override {
    availableEntites.push(entity);
    livingEntites.erase(
        std::remove(livingEntites.begin(), livingEntites.end(), entity),
        livingEntites.end());
    --livingEntityCount;
  }

  const EntityVec &GetAllEntities() const override { return livingEntites; }

  virtual void EntityDestroyed(Entity entity) override {
    DestroyEntity(entity);
  }
};

std::unique_ptr<EntityManager> CreateEntityManager() {
  return std::make_unique<EntityManagerImpl>();
}
