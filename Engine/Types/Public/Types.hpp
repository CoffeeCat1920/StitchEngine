#pragma once

#include <cstdint>
#include <string>

struct WindowConfig {
  uint16_t w, h;
  std::string title;
  WindowConfig() : w(640), h(480), title("") {}
  WindowConfig(uint16_t w, uint16_t h, std::string title)
      : w(w), h(h), title(title) {}
  WindowConfig(std::string title) : w(640), h(480), title(title) {}
};
