#include "EditorUI.h"

void EditorUI::ShowMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New Scene"))
            { /* New Scene Code */
            }
            if (ImGui::MenuItem("Open..."))
            { /* Open Scene Code */
            }
            if (ImGui::MenuItem("Save"))
            { /* Save Scene Code */
            }
            if (ImGui::MenuItem("Exit"))
            {
                isRunning = false;
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "CTRL+Z"))
            { /* Undo Code */
            }
            if (ImGui::MenuItem("Redo", "CTRL+Y"))
            { /* Redo Code */
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void EditorUI::ShowViewport()
{
    ImGui::Begin("Viewport");

    // ShowMainMenuBar();
    // Renderização da cena vai aqui
    ImGui::Image((void *)nullptr, ImVec2(1280, 720)); // Substituir com a textura renderizada da cena
    ImGui::End();
}

void EditorUI::ShowInspector()
{
    if (ImGui::BeginChild("Inspector"))
    {

        if (selectedObject)
        {
            ImGui::Text("Transform");
            ImGui::DragFloat3("Position", selectedObject->position);
            ImGui::DragFloat3("Rotation", selectedObject->rotation);
            ImGui::DragFloat3("Scale", selectedObject->scale);

            if (ImGui::CollapsingHeader("Render"))
            {
                ImGui::ColorEdit4("Color", selectedObject->color);
            }
        }

        ImGui::EndChild();
    }
}

void EditorUI::ShowHierarchy()
{
    ImGui::Begin("Hierarchy", nullptr, ImGuiWindowFlags_NoCollapse);

    for (auto &object : currentScene->GetObjects())
    {
        if (ImGui::Selectable(object.name.c_str(), &object == selectedObject))
        {
            selectedObject = &object;
        }
    }

    ImGui::End();
}
void EditorUI::ShowDockSpace()
{
    ImGuiID dockSpaceID = ImGui::GetID("MyDockSpace");

    // Enable Docking
    ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImGui::DockSpace(dockSpaceID, ImVec2(0, 0), ImGuiDockNodeFlags_PassthruCentralNode);

    // Setup the dock layout (only needs to be done once)
    static bool setupDone = false;
    if (!setupDone)
    {
        // ImGui::DockBuilderAddNode(dockSpaceID, ImGuiDockNodeFlags_DockSpace);
        // ImGui::DockBuilderSetNodeSize(dockSpaceID, viewport->Size);

        // ImGuiID dockId = dockSpaceID;
        // ImGuiID dockRightID = ImGui::DockBuilderSplitNode(dockId, ImGuiDir_Right, 0.25f, NULL, &dockId);
        // ImGui::DockBuilderDockWindow("Inspector", dockRightID);
        // ImGui::DockBuilderFinish(dockSpaceID);

        setupDone = true;
    }
}
void EditorUI::Render()
{

    ShowMainMenuBar();
    ShowDockSpace();
    // ShowHierarchy();
    // ShowConsole();
    // ShowViewport();
    // ShowInspector();
    const ImGuiViewport *main_viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 650, main_viewport->WorkPos.y + 20), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(550, main_viewport->Size.y), ImGuiCond_FirstUseEver);

    if (!ImGui::Begin("Main Window", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar))
    {
        ImGui::End();
        return;
    }
    else
    {
        ImGui::PushItemWidth(ImGui::GetFontSize() * -12);

        ImVec2 viewportSize = ImGui::GetMainViewport()->Size;
        ImGui::SetWindowSize(viewportSize);
        ImGui::SetWindowPos(ImVec2(0, 20));
        // Create dockable child windows
        ImGui::End();
    }
    if (ImGui::Begin("Dockable Child Window 1", nullptr, ImGuiWindowFlags_ChildWindow | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_ChildWindow))
    {
        ImVec2 viewportSize = ImGui::GetMainViewport()->Size;
        ImVec2 newsize = ImVec2(10, 20);
        ImGui::SetWindowSize(newsize);
        ImGui::SetWindowPos(ImVec2(0, 20));

        ImGui::Text("This is a dockable child window.");
        ImGui::EndChild();
        // ImGui::End();
    }
    else
    {
        ImGui::End();
    }
}
void EditorUI::ShowConsole()
{
    ImGui::Begin("Console");
    for (const auto &message : logMessages)
    {
        ImGui::TextWrapped(message.c_str());
    }
    ImGui::End();
}

void EditorUI::LogMessage(const std::string &message)
{
    // Get the current time
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now);

    // Format the time as {YYYY-MM-DD HH:MM:SS}
    std::ostringstream timeStream;
    timeStream << std::put_time(localTime, "[%Y-%m-%d %H:%M:%S]");

    // Create the log entry with the date and message
    std::string logEntry = timeStream.str() + " - " + message;

    // Add the log entry to the logMessages vector
    logMessages.push_back(logEntry);
}
