#pragma once
#include <imgui.h>
#include <vector>
#include <string>
#include <GameObject.h>

class Scene
{
public:
    std::vector<GameObject> objects;

    std::vector<GameObject> &GetObjects();
    void AddObject(const GameObject &object);
};