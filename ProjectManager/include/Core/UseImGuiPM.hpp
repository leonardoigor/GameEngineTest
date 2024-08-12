#pragma once
#include <Scene.h>
#include <EditorUI.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <Models/CreateWindowData.hpp>

class UseImGuiPM
{
private:
public:
    UseImGuiPM();
    ~UseImGuiPM();

    void InitWindow();
    void Init(const char *glsf_version);
    virtual void Update();
    void Render();
    void Shutdown();
    void NewFrame();
    bool isRunning();
    void NewProjectWindow();

    Scene scene;
    EditorUI editorUI;
    GLFWwindow *window;
    CreateWindowData createWindowData;
    bool isRunningFlag;
    bool isNewProjectWindow = false;

public:
    void ShowMainMenuBar();
    void getCharacterCounts(const std::string &input, int &letterCount)
    {
        letterCount = 0;

        for (size_t i = 0; i < input.size(); ++i)
        {
            char c = input[i];
            if (c == '\0')
            {
                break; // Stop processing if the null character is encountered
            }
            if (std::isalpha(c) || !std::isspace(c))
            {
                letterCount++;
            }
        }
    }
};
