# StitchEngine — Project Documentation Report

**Version:** 0.1.0 (Early Development)  
**Repository:** StitchEngine  
**Date:** May 2026

---

## Table of Contents

1. [Executive Summary](#1-executive-summary)
2. [What Is StitchEngine?](#2-what-is-stitchengine)
3. [Key Features](#3-key-features)
4. [Project Status and Roadmap](#4-project-status-and-roadmap)
5. [Architecture Overview](#5-architecture-overview)
6. [Technology Stack](#6-technology-stack)
7. [ECS Core Design](#7-ecs-core-design)
8. [Module Reference](#8-module-reference)
9. [Build System and Development](#9-build-system-and-development)
10. [API Reference](#10-api-reference)
11. [Appendix: JSON Scene Format](#11-appendix-json-scene-format)

---

## 1. Executive Summary

StitchEngine is a 2D game engine built from the ground up in modern C++ (C++20). It uses an **Entity-Component-System (ECS)** architecture — a design pattern that organises game objects (entities) as collections of data (components) that are processed by logic units (systems). This approach is well suited for games because it is modular, cache-friendly, and easy to extend.

The project is in the **early stages of development** and currently provides a working core: entities can be created, components can be attached, systems can run each frame, sprites can be rendered, and scenes can be loaded from JSON files. The engine ships with a sample application (`Game/`) that demonstrates these capabilities.

The engine is being developed by a small team (or individual) and is structured as a collection of static libraries linked together by CMake. It depends on two external libraries: **raylib** (for windowing, input, and 2D rendering) and **nlohmann/json** (for JSON parsing and serialisation).

---

## 2. What Is StitchEngine?

For readers without a technical background, think of a video game as a stage play:

- **Entities** are the actors on stage — characters, props, cameras, lights.
- **Components** are the traits each actor has — their position on stage, their costume (sprite), how fast they can move.
- **Systems** are the stage directions — every frame, the "movement system" reads each actor's position and speed, and moves them accordingly; the "render system" draws each actor to the screen.

StitchEngine provides the backstage infrastructure so that game developers can focus on creating actors, giving them traits, and writing stage directions — without worrying about low-level plumbing like window creation, texture loading, or memory management.

The engine is written entirely in C++ and targets desktop platforms (Linux, Windows, macOS via raylib). It is **not yet ready for commercial game development**, but it provides a solid foundation that can be built upon.

### Who Is This For?

- **Game developers** who want to build 2D games with a clean, modern ECS architecture.
- **Students and educators** learning about game engine architecture, ECS patterns, or C++20.
- **Hobbyists** looking for a lightweight, understandable engine they can modify and extend.

---

## 3. Key Features

### Current (Implemented)

- **Entity-Component-System core** — create and destroy entities, attach/remove typed components, run per-frame logic systems.
- **Sprite rendering** — load textures from disk, draw them to a window via a command queue.
- **Keyboard input** — poll keyboard state per frame (arrow keys for movement).
- **Window management** — create a resizable window with a configurable title and dimensions.
- **JSON scene loading** — define entities and their components in a `.json` file and load them at runtime.
- **Component reflection** — components are self-describing at runtime; their structure can be dumped to JSON (schema generation).
- **Auto-registration** — components and systems register themselves automatically via C++ static initialisation macros.
- **Archetype-based entity matching** — systems automatically track entities whose component signature matches what the system requires.

### Planned / In Progress

- Physics and collision detection (a QuadTree stub exists).
- Audio support.
- More gameplay components and systems.
- Editor/tooling integration.

---

## 4. Project Status and Roadmap

### Current Status

The engine is functional but minimal. The core ECS loop works: entities can be created, components added, and systems ticked each frame. A sample game creates a single sprite that the user can move with arrow keys.

| Area | Status |
|---|---|
| ECS Core | Complete |
| Sprite Rendering | Complete |
| Window & Input | Complete |
| Scene Serialisation | Complete |
| Component Reflection | Complete |
| System Auto-Registration | Complete |
| Physics / Collision | Not started (stub only) |
| Audio | Not started |
| Entity Prefabs | Not started |
| Editor Tooling | Not started |
| Formal Tests | Missing |

### Suggested Roadmap

1. **Short term** — Add unit tests, collision detection, and a more interesting sample game.
2. **Medium term** — Audio engine, particle system, UI components, improved scene format with prefabs.
3. **Long term** — Editor, asset pipeline, scripting language integration.

---

## 5. Architecture Overview

StitchEngine follows a **layered, modular architecture**. Each subsystem lives in its own directory and compiles to a separate static library. This makes the codebase easy to navigate, test, and replace.

```
main()
  └─ GetEngine(WindowConfig)          [Engine factory]
       └─ EngineImpl                  [Engine lifecycle]
            ├─ WindowHandler          [raylib: window, input]
            ├─ RenderHandler          [raylib: sprite draw queue]
            ├─ TextureHandler         [raylib: texture loading]
            ├─ ResourceManager        [Sprite resource abstraction]
            ├─ ECS Facade             [Unified ECS interface]
            │    ├─ EntityManager     [Entity create/destroy]
            │    ├─ ComponentManager  [Component storage, signatures, archetypes]
            │    ├─ ComponentArray<T> [Dense per-component storage]
            │    └─ SystemManager     [System registration, entity matching]
            ├─ ComponentRegistry      [Runtime reflection + JSON schema]
            ├─ SystemRegistry         [Physics/Render system dispatch]
            └─ Scene                  [JSON scene loader]
```

### The Game Loop

The engine runs a single-threaded game loop each frame:

1. **BeginFrame** — Clear the screen, begin drawing.
2. **RenderUpdate** — Tick all render-category systems (e.g., `SSpriteRenderer`), which queue draw commands.
3. **RenderQueue** — Flush all queued draw commands to the screen via raylib.
4. **EndFrame** — Swap the front and back buffers.
5. **PhysicsUpdate** — Tick all physics-category systems (e.g., `SMovement` for keyboard-driven movement).

Components and systems are split into two categories — **Render** (drawing-related, runs before buffer swap) and **Physics** (state-update logic, runs after buffer swap). This separation ensures the frame is fully rendered before state changes occur, preventing visual tearing within a frame.

---

## 6. Technology Stack

| Layer | Technology | Purpose |
|---|---|---|
| **Language** | C++20 | Core implementation language |
| **Build System** | CMake 3.20+ | Cross-platform build configuration |
| **Windowing & Input** | raylib | Window creation, keyboard/mouse input, 2D rendering |
| **JSON** | nlohmann/json (vendored) | Scene files, component serialisation, schema dumps |
| **Memory** | Custom FreeList allocator | O(1) insert/erase for texture handles |
| **Storage** | Dense component arrays | Cache-friendly ECS storage with O(1) lookup |

### Why raylib?

raylib is a simple, header-friendly multimedia library that provides window management, OpenGL-accelerated 2D rendering, and input handling. It is well suited for an engine at this stage because it removes the need to deal directly with GLFW, SDL, or OpenGL boilerplate, while still being fast enough for 2D games.

### Why nlohmann/json?

The nlohmann JSON library is a modern, header-only C++ library that makes JSON parsing and serialisation trivial. It is vendored directly in the repository (under `StitchEngine/vendor/nlohmann/`) so there is no external dependency to install.

---

## 7. ECS Core Design

The Entity-Component-System architecture is the heart of StitchEngine. This section explains the design in detail for developers.

### 7.1 Entities

An **Entity** is simply a `uint32_t` identifier — an integer handle with no behaviour. Entities are pre-allocated in a pool of `MAX_ENTITIES = 1024`. When an entity is created, the smallest free ID is recycled from a queue. When destroyed, the ID is returned to the queue.

```cpp
using Entity = uint32_t;
const uint32_t MAX_ENTITIES = 1024;
```

### 7.2 Components

A **Component** is a plain data struct (no virtual methods, no logic). Components are stored in **dense arrays** (`ComponentArray<T>`) for cache efficiency. Each component type gets its own array.

The dense array uses two maps for O(1) entity-to-index translation:

- `entityToIndex` maps `Entity → slot index`
- `indexToEntity` maps `slot index → Entity`

When a component is removed, the last element in the array is swapped into the vacated slot (swap-and-pop), keeping the array contiguous.

```cpp
template <typename T>
class ComponentArray : public IComponentArray {
    std::unordered_map<Entity, size_t> entityToIndex;
    std::unordered_map<size_t, Entity> indexToEntity;
    std::array<T, MAX_ENTITIES> components;
    size_t size;
};
```

### 7.3 Signatures

Each entity has a **Signature** — a `std::bitset<64>` where each bit represents whether the entity has a given component type. When a component is added or removed, the entity's signature is recalculated.

```cpp
using Signature = std::bitset<MAX_COMPONENTS>;  // MAX_COMPONENTS = 64
```

### 7.4 Archetypes

Entities sharing the same component signature form an **archetype**. The `ComponentManager` maintains a map from `Signature → set<Entity>`. This allows systems to efficiently find all entities that match a required component set.

### 7.5 Systems

A **System** is a struct with a `virtual Update()`, a `Signature` (describing which component combinations it operates on), and a set of matching entities. The `SystemManager` automatically maintains the matching set: whenever an entity's signature changes, every system checks whether the entity now matches or no longer matches.

```cpp
struct System {
    Signature signature;
    EntitySet entities;
    virtual void Update() = 0;
};
```

Systems are registered in two categories:

- **Render systems** — updated before the buffer swap (e.g., sprite rendering).
- **Physics systems** — updated after the buffer swap (e.g., movement, collision).

### 7.6 ECS Facade

The `ECS` class is a singleton facade that wraps `EntityManager`, `ComponentManager`, and `SystemManager`. All ECS operations go through this single entry point, which ensures that signatures are kept in sync across the three managers.

```cpp
auto &ecs = ECS::Instance();
Entity e = ecs.AddEntity();
ecs.AddComponents(e, CTransform{...}, CSprite{...});
```

---

## 8. Module Reference

### 8.1 `Types` (Header-Only)

Shared type definitions used across all modules.

| Type | Definition | Purpose |
|---|---|---|
| `Entity` | `uint32_t` | Entity identifier |
| `Signature` | `std::bitset<64>` | Component presence mask |
| `Vec2` | `struct { long double x, y }` | 2D vector |
| `Sprite` | `struct { SpriteId, Vec2 }` | Drawable sprite |
| `WindowConfig` | `struct { int w, h; string title }` | Window parameters |
| `FreeList<T>` | Template class | O(1) insert/erase pool allocator |
| `SpriteId` | `uint16_t` | Texture handle |

### 8.2 `ECS` (Static Library)

The core ECS subsystem. Four libraries that compose the ECS:

| Library | Key Class / Function | Responsibility |
|---|---|---|
| `EntityManager` | `EntityManager` / `GetEntityManager()` | Entity creation, destruction, lifecycle |
| `ComponentArray` | `ComponentArray<T>` | Dense storage per component type |
| `ComponentManager` | `ComponentManager` / `GetComponentManager()` | Registration, storage, signatures, archetypes |
| `SystemManager` | `SystemManager` / `GetSystemManager()` | System registration, entity matching |
| `ECS` (facade) | `ECS::Instance()` | Unified interface to all ECS operations |

### 8.3 `Platform` (Static Libraries)

Abstraction layer over the hardware/windowing system.

| Library | Key Function | Responsibility |
|---|---|---|
| `WindowHandler` | `GetWindowHandler(config)` | Create/manage window, begin/end frame |
| `RenderHandler` | `GetRenderHandler()` | Queue draw commands, flush to screen |
| `TextureHandler` | `GetTextureHandler()` | Load/unload textures, manage sprite IDs |

All three use a **virtual interface + implementation** pattern: the public header declares a pure virtual class, and the implementation file provides a concrete subclass. Factory functions return `std::unique_ptr` to the interface.

### 8.4 `ResourceManager` (Static Library)

A higher-level facade over `TextureHandler`. Currently provides `LoadSprite(path)` and `UnloadSprite(path)`. Designed to be extended to manage fonts, sounds, and other assets.

### 8.5 `Registry` (Static Libraries)

Runtime reflection, serialisation, and system dispatch.

| Library | Key Class / Macro | Responsibility |
|---|---|---|
| `ComponentRegistry` | `ComponentRegistry::Instance()`, `REFLECTION(T)`, `COMPONENT(T, ...)` | JSON deserialisation, serialisation, schema dumping, ECS integration |
| `SystemRegistry` | `SystemRegistry::Instance()`, `REGISTER_SYSTEM(T, Cat, ...)` | Categorised system dispatch (physics/render), auto-registration |

The `REFLECTION` macro creates a static global object whose constructor runs before `main()`, automatically calling `ComponentRegistry::Instance().Register<T>(#T)`. This means components are always registered without any manual setup.

The `COMPONENT` macro wraps `NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT`, providing automatic JSON serialisation for all listed member fields.

### 8.6 `Gameplay` (Static/Header Libraries)

Pre-built components and systems for immediate use in games.

| Item | Type | Description |
|---|---|---|
| `CTransform` | Component | Position (`Vec2`), scale (`Vec2`), rotation (`float`) |
| `CSprite` | Component | Sprite ID (`SpriteId`) |
| `CMovement` | Component | Movement flag (`int d`) |
| `SSpriteRenderer` | System (Render) | Queues a `RenderCommand` for each entity with `CTransform` + `CSprite` |
| `SMovement` | System (Physics) | Reads arrow keys and updates `CTransform::position` |

### 8.7 `Scene` (Static Library)

The `Scene` class loads a JSON file describing entities and their components, then creates them in the ECS. It handles `CSprite` specially by loading the referenced texture via `ResourceManager`. For all other components, it delegates to `ComponentRegistry::AddComponent`.

### 8.8 `Engine` (Static Library)

The top-level orchestrator. `Engine::Init()` creates the window. `Engine::Run()` runs the game loop. `Engine::LoadScene()` and `Engine::UnloadScene()` manage scene transitions.

### 8.9 `Assertions` (Header-Only)

A single `ASSERT(x)` macro that prints to `stderr` and calls `abort()` when the condition fails (in debug builds). No-ops in release builds.

### 8.10 `Utils` (Header-Only)

Helper functions to construct `Signature` bitsets from component IDs or lists of IDs.

---

## 9. Build System and Development

### Prerequisites

- **CMake** 3.20+
- **C++20 compiler** (GCC 11+, Clang 14+, or MSVC 2022+)
- **raylib** installed system-wide (via package manager or built from source)

### Building

```bash
# Configure
cmake -S . -B Build

# Build
cmake --build Build

# Or, from the Build directory:
cd Build && make
```

### Running

```bash
./Build/Game/Game
```

This launches a 640×320 window titled "Candela" with a movable sprite.

### Build Output

| Artifact | Location |
|---|---|
| Game binary | `Build/Game/Game` |
| Static libraries | `Build/Lib/*.a` (one per module) |
| Component schema | `components.json` (generated at runtime in CWD) |

### Testing

There are currently **no formal tests**. Testing is identified as a priority improvement.

### Code Style Notes

- C++20 standard, no extensions.
- Header files use `#pragma once`.
- Implementation files use `.cpp` extension.
- Public headers under `Public/`, implementation under `Private/`.
- Singletons use the Meyer's singleton pattern (static local variable).
- Platform handlers use virtual interface + impl pattern.
- Macros for auto-registration (`REFLECTION`, `COMPONENT`, `REGISTER_SYSTEM`).
- C++17 fold expressions used for variadic component operations.

---

## 10. API Reference

### Engine Lifecycle

```cpp
// Create the engine
auto engine = GetEngine(WindowConfig{.w = 640, .h = 320, .title = "My Game"});

// Initialise (creates window)
engine->Init();

// Load a scene (optional)
engine->LoadScene(Scene("path/to/scene.json"));

// Run the game loop (blocks until window closes)
engine->Run();
```

### ECS Operations

```cpp
auto &ecs = ECS::Instance();

// Entities
Entity entity = ecs.AddEntity();
ecs.RemoveEntity(entity);

// Components (must register first)
ecs.RegisterComponent<CTransform>();
ecs.AddComponent(entity, CTransform{.position = {0, 0}});
// or multiple at once:
ecs.AddComponents(entity, CTransform{...}, CSprite{...});

// Query
bool has = ecs.HasComponent<CTransform>(entity);
CTransform &t = ecs.GetComponent<CTransform>(entity);

// Systems
ecs.RegisterSystem<SMovement>();
// Set which components the system operates on:
ecs.RegisterSystemWithSignatures<SMovement, CTransform, CMovement>();

// Get a system to access its entities:
auto sys = ecs.GetSystem<SMovement>();
```

### Component Registration

```cpp
// In any header or source file:
struct CMyComponent {
    int health;
    float speed;
};

COMPONENT(CMyComponent, health, speed);  // Enable JSON serialisation
REFLECTION(CMyComponent);                 // Auto-register in ComponentRegistry
```

### System Registration

```cpp
struct SMySystem : public System {
    void Update() override {
        for (auto entity : entities) {
            auto &t = ECS::Instance().GetComponent<CTransform>(entity);
            // game logic here
        }
    }
};

REGISTER_SYSTEM(SMySystem, Physics, CTransform, CMovement);
```

### Scene JSON Format

See [Appendix: JSON Scene Format](#11-appendix-json-scene-format).

---

## 11. Appendix: JSON Scene Format

Scenes are loaded from JSON files with the following structure:

```json
{
  "entities": [
    {
      "name": "Entity_0",
      "components": {
        "CSprite": {
          "sprite": "/path/to/texture.png"
        },
        "CTransform": {
          "position": { "x": 0.0, "y": 0.0 },
          "scale": { "x": 1.0, "y": 1.0 }
        }
      }
    }
  ]
}
```

- The `name` field is metadata (not yet used in engine logic).
- The `sprite` field in `CSprite` is a filesystem path to a PNG image. The `Scene` loader resolves it via `ResourceManager::LoadSprite()`.
- All other components use the `ComponentRegistry`'s JSON deserialisation path, which automatically maps field names to struct members via `NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT`.

The runtime schema of all registered components (including default values) can be dumped with:

```cpp
ComponentRegistry::Instance().DumpSchemaToFile("components.json");
```

This produces output like:

```json
{
    "CMovement": { "d": 0 },
    "CSprite": { "sprite": 0 },
    "CTransform": { "position": { "x": 0.0, "y": 0.0 }, "rotation": 0.0, "scale": { "x": 0.0, "y": 0.0 } }
}
```

---

*This document was generated from analysis of the StitchEngine source tree. It reflects the state of the codebase as of May 2026.*
