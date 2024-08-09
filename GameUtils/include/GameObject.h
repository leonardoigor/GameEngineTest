#pragma once
#include <imgui.h>
#include <vector>
#include <string>

class GameObject
{
public:
    std::string name;
    float position[3] = {0.0f, 0.0f, 0.0f};
    float rotation[3] = {0.0f, 0.0f, 0.0f};
    float scale[3] = {1.0f, 1.0f, 1.0f};
    float color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
};
