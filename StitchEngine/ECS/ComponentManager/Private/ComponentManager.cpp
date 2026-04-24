#include "ComponentManager.hpp"

ComponentManager &GetComponentManager() {
  static ComponentManager g_componentManager;
  return g_componentManager;
}
