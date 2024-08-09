

set(GameUtilsDir ${CMAKE_SOURCE_DIR}/GameUtils/include)
set(ImGuiDir ${CMAKE_SOURCE_DIR}/vendor/imgui)

include_directories(include)

include_directories(${GameUtilsDir})
include_directories(${ImGuiDir})
file(GLOB_RECURSE FilesINFolder *.cpp *.h *hpp)

foreach(file ${FilesINFolder})
    message(STATUS "----- file compiled (${file})")
endforeach()

add_executable(App main.cpp ${FilesINFolder})

target_link_libraries(App PRIVATE glad::glad)
target_link_libraries(App PRIVATE glfw)

# target_link_libraries(App PRIVATE imgui::imgui)
target_link_libraries(App PRIVATE imgui)
target_link_libraries(App PUBLIC GameUtils)

# Adicione um alvo para copiar os arquivos após a construção
add_custom_command(TARGET App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${VCPKG_INSTALLED_DIR}/bin
    ${CMAKE_SOURCE_DIR}/output
    COMMENT "Copying all items from ${SOURCE_DIR} to ${DESTINATION_DIR}"
)
