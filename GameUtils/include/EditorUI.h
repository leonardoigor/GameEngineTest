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
        isRunning = true;
    };
    EditorUI(Scene *scene) : currentScene(scene), selectedObject(nullptr)
    {
        LogMessage("teste");
        isRunning = true;
    }
    void ShowDockSpace();
    void Render();

    bool isRunning = false;

private:
    Scene *currentScene;
    GameObject *selectedObject;
    std::vector<std::string> logMessages;

public:
    void ShowMainMenuBar();

    void ShowViewport();

    void ShowInspector();

    void ShowHierarchy();

    void ShowConsole();
    void LogMessage(const std::string &message);
};