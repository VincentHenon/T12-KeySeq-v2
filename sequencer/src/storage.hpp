#pragma once
#include "model.hpp"
namespace t12::storage {
void init();
bool available();
bool loadProject(unsigned slot, Project &);
bool saveProject(unsigned slot, const Project &);
bool clearProject(unsigned slot);
bool loadSettings(Settings &);
bool saveSettings(const Settings &);
} // namespace t12::storage
