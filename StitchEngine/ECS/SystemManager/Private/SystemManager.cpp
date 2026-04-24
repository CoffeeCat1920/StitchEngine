#include "SystemManager.hpp"

SystemManager &GetSystemManager() {
  static SystemManager g_systemManager;
  return g_systemManager;
}
