#include "Core/UseImGui.h"
#include "glad/glad.h"
#include <Scene.h>
#include <EditorUI.h>
#include "GLFW/glfw3.h"

int main(int argc, char const *argv[])
{
    if (!glfwInit())
        return 1;

    // GL 3. + glsl 130
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // create window with graphics contex
    GLFWwindow *window = glfwCreateWindow(1280, 720, "GameEngine Test", NULL, NULL);
    if (window == NULL)
        return 1;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // enalbe VSync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // tie window context to glad's open
        throw("Unalbe to context to opengl");

    int screen_width, screen_height;
    glfwGetFramebufferSize(window, &screen_width, &screen_height);
    glViewport(0, 0, screen_width, screen_height);

    UseImGui mygui;
    mygui.Init(window, glsl_version);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        mygui.NewFrame();
        mygui.Update();

        mygui.Render();
        glfwSwapBuffers(window);
    }
    mygui.Shutdown();

    return 0;
}
