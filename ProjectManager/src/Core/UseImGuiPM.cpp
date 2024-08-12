#include "Core/UseImGuiPM.hpp"

UseImGuiPM::UseImGuiPM()
{
    this->scene = Scene();
    this->createWindowData = CreateWindowData();
    this->createWindowData.projectName = "teste";
    this->createWindowData.projectPath = "C:/Projects";
    this->editorUI = EditorUI(&scene);
}

UseImGuiPM::~UseImGuiPM()
{
}

void UseImGuiPM::InitWindow()
{
    if (!glfwInit())
        throw("error glfwInit");

    // GL 3. + glsl 130
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // create window with graphics contex
    GLFWwindow *window = glfwCreateWindow(1280, 720, "Project Manager", NULL, NULL);
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

void UseImGuiPM::Init(const char *glsf_version)
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

void UseImGuiPM::Update()
{
    editorUI.ShowDockSpace();
    ShowMainMenuBar();
    if (isNewProjectWindow)
        NewProjectWindow();
}

void UseImGuiPM::Render()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UseImGuiPM::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UseImGuiPM::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

bool UseImGuiPM::isRunning()
{
    return isRunningFlag && !glfwWindowShouldClose(window);
}

void UseImGuiPM::ShowMainMenuBar()
{

    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New Project"))
            {
                isNewProjectWindow = true;
            }
            if (ImGui::MenuItem("Open Project"))
            { /* Open Scene Code */
            }
            if (ImGui::MenuItem("Exit"))
            {
                isRunningFlag = false;
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

void UseImGuiPM::NewProjectWindow()
{
    std::string projectPath = createWindowData.ProjectPathFull();
    const ImGuiViewport *main_viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 650, main_viewport->WorkPos.y + 20), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(550, main_viewport->Size.y), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("New Project", &isNewProjectWindow))
    {
        ImGui::PushItemWidth(ImGui::GetFontSize() * -12);

        ImVec2 viewportSize = ImGui::GetMainViewport()->Size;
        ImGui::SetWindowSize(viewportSize);
        ImGui::SetWindowPos(ImVec2(0, 20));
        int lettterCount = 0;
        getCharacterCounts(createWindowData.projectName, lettterCount);
        // Input field for the project name
        ImGui::InputText("Project Name", &createWindowData.projectName[0], createWindowData.projectName.size() + lettterCount);

        // Display the current save path
        ImGui::Text("Save Path: %s", projectPath.c_str());

        // Button to change the path (in a real application, this would open a file dialog)
        auto instance = ImGuiFileDialog::Instance();
        if (ImGui::Button("Change Path"))
        {
            IGFD::FileDialogConfig config;
            config.path = ".";
            config.countSelectionMax = 1;

            instance->OpenDialog("ChooseFileDlgKey", "Choose Folder", nullptr, config);
            // display
        }
        if (instance->Display("ChooseFileDlgKey"))
        {
            if (instance->IsOk())
            { // action if OK
                std::string filePathName = instance->GetFilePathName();
                std::string filePath = instance->GetCurrentPath();
                // action
                createWindowData.projectPath = filePath;
            }

            // close
            ImGuiFileDialog::Instance()->Close();
        }

        // Button to create the project
        if (ImGui::Button("Create Project"))
        {
            // Code to create the project would go here
            // For example, saving the project details to a file or initializing the project structure

            // Close the window after creating the project
            isNewProjectWindow = false;
        }
    }
    ImGui::End();
}