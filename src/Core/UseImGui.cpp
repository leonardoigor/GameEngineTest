#include "Core/UseImGui.h"

UseImGui::UseImGui()
{
    this->scene = Scene();
    this->editorUI = EditorUI(&scene);
}

UseImGui::~UseImGui()
{
}

// void EditorUI::ShowDockSpace()
// {
//     // Enable Docking
//     ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
// }
void UseImGui::Init(GLFWwindow *window, const char *glsf_version)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Habilita o docking
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Habilita viewports múltiplos (opcional)

    // setup platform/renderer binding
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsf_version);
    ImGui::StyleColorsDark();
}

void UseImGui::Update()
{
    editorUI.Render();
}

void UseImGui::Render()
{ // Render dear imgui into screen
    // ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UseImGui::Shutdown()
{ // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UseImGui::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}
