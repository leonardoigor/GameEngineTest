#pragma once
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <Scene.h>
#include <EditorUI.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class UseImGui
{
private:
public:
    UseImGui();
    ~UseImGui();

    void InitWindow();
    void Init(const char *glsf_version);
    virtual void Update();
    void Render();
    void Shutdown();
    void NewFrame();
    bool isRunning()
    {
        return editorUI.isRunning && !glfwWindowShouldClose(window);
    }

    Scene scene;
    EditorUI editorUI;
    GLFWwindow *window;
};
