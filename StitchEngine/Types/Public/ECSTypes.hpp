#pragma once

#include <bitset>
#include <cstdint>
#include <set>
#include <vector>

using Entity = uint32_t;
using EntityVec = std::vector<Entity>;
using EntitySet = std::set<Entity>;

inline const uint32_t MAX_ENTITIES = 1024;
inline constexpr uint8_t MAX_COMPONENTS = 64;

using Signature = std::bitset<MAX_COMPONENTS>;
