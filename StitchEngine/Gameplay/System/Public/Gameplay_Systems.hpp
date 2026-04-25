#pragma once

#include "ECS.hpp"
#include "Gameplay_Components.hpp"
#include "SystemRegistry.hpp"

#include <raylib.h>

struct SPhysics : System {
  ECS &gEcs = ECS::Instance();
  void Update() override {
    for (const auto &entity : System::entities) {
      auto &rigidBody = gEcs.GetComponent<CRigidBody>(entity);
      auto &transform = gEcs.GetComponent<CTransform>(entity);
      auto const &gravity = gEcs.GetComponent<CGravity>(entity);

      transform.position.x += rigidBody.velocity.x;
      transform.position.y += rigidBody.velocity.y;

      rigidBody.velocity.x += gravity.force.x;
      rigidBody.velocity.y += gravity.force.y;
    }
  }
};
