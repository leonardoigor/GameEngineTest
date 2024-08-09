#pragma once
#include < GameObject.h>
#include <scene.h>
#include <imgui.h>
#include <vector>
#include <string>

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
class EditorUI
{
public:
    EditorUI()
    {
        LogMessage("teste");
    };
    EditorUI(Scene *scene) : currentScene(scene), selectedObject(nullptr)
    {
        LogMessage("teste");
    }

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