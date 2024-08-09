#include "Scene.h"

std::vector<GameObject> &Scene::GetObjects()
{
    return objects;
}

void Scene::AddObject(const GameObject &object)
{
    objects.push_back(object);
}
