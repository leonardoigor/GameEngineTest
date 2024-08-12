#include "Core/UseImGuiPM.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    const char *glsl_version = "#version 130";

    UseImGuiPM mygui;
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
