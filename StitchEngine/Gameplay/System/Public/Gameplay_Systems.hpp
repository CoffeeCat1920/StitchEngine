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
