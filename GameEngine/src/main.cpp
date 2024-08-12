#include "Core/UseImGui.h"
#include <Scene.h>
#include <EditorUI.h>
// #include "GLFW/glfw3.h"

int main(int argc, char const *argv[])
{
    const char *glsl_version = "#version 130";

    UseImGui mygui;
    mygui.Init(glsl_version);

    while (mygui.isRunning())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        mygui.NewFrame();
        mygui.Update();

        mygui.Render();
        glfwSwapBuffers(mygui.window);
    }
    mygui.Shutdown();

    return 0;
}
