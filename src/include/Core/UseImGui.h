#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <Scene.h>
#include <EditorUI.h>

class UseImGui
{
private:
public:
    UseImGui();
    ~UseImGui();

    void Init(GLFWwindow *window, const char *glsf_version);
    virtual void Update();
    void Render();
    void Shutdown();
    void NewFrame();
    Scene scene;
    EditorUI editorUI;
};
