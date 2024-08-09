
cmake_minimum_required(VERSION 3.10)
project(imgui)

set(pp ${CMAKE_SOURCE_DIR}/vendor/imgui)

# Lista de arquivos fonte do ImGui
set(IMGUI_SRC
    ${pp}/imgui.cpp
    ${pp}/imgui_demo.cpp
    ${pp}/imgui_draw.cpp
    ${pp}/imgui_tables.cpp
    ${pp}/imgui_widgets.cpp
    ${pp}/backends/imgui_impl_glfw.cpp
    ${pp}/backends/imgui_impl_opengl3.cpp
)

# Cria a biblioteca estática ImGui
add_library(imgui STATIC ${IMGUI_SRC})

# Inclui diretórios de cabeçalhos
target_include_directories(imgui PUBLIC ${pp})