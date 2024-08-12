
cmake_minimum_required(VERSION 3.10)
project(ImGuiFileDialog)

set(pp ${CMAKE_SOURCE_DIR}/vendor/ImGuiFileDialog)
file(GLOB_RECURSE files ${pp}/*.cpp ${pp}/*.hpp ${pp}/*.h)

# Lista de arquivos fonte do ImGui
set(IMGUI_SRC
    ${pp}/ImGuiFileDialog.cpp
    ${pp}/ImGuiFileDialog.h
)

# Cria a biblioteca estática ImGui
add_library(ImGuiFileDialog STATIC ${IMGUI_SRC})

# Inclui diretórios de cabeçalhos
target_include_directories(ImGuiFileDialog PUBLIC ${pp})
target_link_libraries(ImGuiFileDialog PRIVATE imgui)
