#include "Core/UseImGui.h"

UseImGui::UseImGui()
{
    this->scene = Scene();
    this->editorUI = EditorUI(&scene);
}

UseImGui::~UseImGui()
{
}
// static const ImGuiID dockSpaceID = ImGui::GetID("MyDockSpace");
void UseImGui::InitWindow()
{
    if (!glfwInit())
        throw("error glfwInit");

    // GL 3. + glsl 130
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // create window with graphics contex
    GLFWwindow *window = glfwCreateWindow(1280, 720, "GameEngine Test", NULL, NULL);
    if (window == NULL)
        throw("error window == NULL");

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // enalbe VSync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // tie window context to glad's open
        throw("Unalbe to context to opengl");

    int screen_width, screen_height;
    glfwGetFramebufferSize(window, &screen_width, &screen_height);
    glViewport(0, 0, screen_width, screen_height);
    this->window = window;
}
void UseImGui::Init(const char *glsf_version)
{
    InitWindow();
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Habilita o docking
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
