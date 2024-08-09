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
    ImGui::Begin("Viewport", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    // Renderização da cena vai aqui
    ImGui::Image((void *)nullptr, ImVec2(1280, 720)); // Substituir com a textura renderizada da cena
    ImGui::End();
}

void EditorUI::ShowInspector()
{
    ImGui::Begin("Inspector");

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

    ImGui::End();
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
// void EditorUI::ShowDockSpace()
// {
//     // Enable Docking
//     ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
// }
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
