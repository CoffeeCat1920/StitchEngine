#pragma once

#include "ECS.hpp"
#include "Gameplay_Components.hpp"
#include "RenderHandler.hpp"
#include "SystemManager.hpp"
#include "SystemRegistry.hpp"

#include <raylib.h>

struct SSpriteRenderer : System {
  ECS &g_ECS = ECS::Instance();
  RenderHandler &g_renderHandler = GetRenderHandler();
  void Update() override {
    for (const auto &entity : System::entities) {
      auto &transform = g_ECS.GetComponent<CTransform>(entity);
      auto &sprite = g_ECS.GetComponent<CSprite>(entity);
      RenderCommand command = {.textureId = sprite.sprite,
                               .x = transform.position.x,
                               .y = transform.position.y};
      g_renderHandler.QueueCommand(command);
    }
  }
};
REGISTER_SYSTEM(SSpriteRenderer, Physics, CTransform, CSprite);

// struct STest : System {
//   ECS &g_ECS = ECS::Instance();
//   void Update() override {
//     for (const auto &entity : System::entities) {
//       auto &transform = g_ECS.GetComponent<CTransform>(entity);
//       std::cout << transform.position.x << "\n"
//                 << transform.position.y << std::endl;
//     }
//   }
// };
// REGISTER_SYSTEM(STest, Physics, CTransform);

// struct SPhysics : System {
//   ECS &gEcs = ECS::Instance();
//   void Update() override {
//     for (const auto &entity : System::entities) {
//       auto &rigidBody = gEcs.GetComponent<CRigidBody>(entity);
//       auto &transform = gEcs.GetComponent<CTransform>(entity);
//       auto const &gravity = gEcs.GetComponent<CGravity>(entity);
//
//       transform.position.x += rigidBody.velocity.x;
//       transform.position.y += rigidBody.velocity.y;
//
//       rigidBody.velocity.x += gravity.force.x;
//       rigidBody.velocity.y += gravity.force.y;
//     }
//   }
// };
//

struct SMovement : System {
  ECS &g_ECS = ECS::Instance();
  RenderHandler &g_renderHandler = GetRenderHandler();
  void Update() override {
    for (const auto &entity : System::entities) {
      auto &transform = g_ECS.GetComponent<CTransform>(entity);
      Vec2 direction = {.x = 0, .y = 0};
      float speed = 12.0f;
      direction.x = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
      direction.y = IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);
      transform.position.x += direction.x * speed;
      transform.position.y += direction.y * speed;
    }
  }
};
REGISTER_SYSTEM(SMovement, Physics, CTransform, CMovement);
