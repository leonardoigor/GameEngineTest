#pragma once
#include < GameObject.h>
#include <scene.h>
#include <imgui.h>
#include <vector>
#include <string>

class EditorUI
{
public:
    EditorUI() {};
    EditorUI(Scene *scene) : currentScene(scene), selectedObject(nullptr) {}

    void Render()
    {
        ShowMainMenuBar();
        ShowViewport();
        ShowInspector();
        ShowHierarchy();
        ShowConsole();
    }

private:
    Scene *currentScene;
    GameObject *selectedObject;
    std::vector<std::string> logMessages;

    void ShowMainMenuBar();

    void ShowViewport();

    void ShowInspector();

    void ShowHierarchy();

    void ShowConsole();

public:
    void LogMessage(const std::string &message);
};