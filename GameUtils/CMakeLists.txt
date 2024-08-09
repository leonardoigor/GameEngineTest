include_directories(include)
set(ImGuiDir ${CMAKE_SOURCE_DIR}/vendor/imgui)
include_directories(${ImGuiDir})

file(GLOB_RECURSE FilesINFolder *.cpp *.h *hpp)

foreach(file ${FilesINFolder})
    message(STATUS "----- file compiled (${file})")
endforeach()

add_library(GameUtils STATIC ${FilesINFolder})