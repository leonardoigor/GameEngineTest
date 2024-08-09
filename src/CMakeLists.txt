

set(GameUtilsDir ${CMAKE_SOURCE_DIR}/GameUtils/include)

include_directories(include)

include_directories(${GameUtilsDir})
file(GLOB_RECURSE FilesINFolder *.cpp *.h *hpp)

foreach(file ${FilesINFolder})
    message(STATUS "----- file compiled (${file})")
endforeach()

add_executable(App main.cpp ${FilesINFolder})

target_link_libraries(App PRIVATE glad::glad)
target_link_libraries(App PRIVATE glfw)
target_link_libraries(App PRIVATE imgui::imgui)
target_link_libraries(App PUBLIC GameUtils)
