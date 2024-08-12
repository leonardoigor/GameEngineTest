cmake_minimum_required(VERSION 3.11)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/ProjectManager)

# Set the output directories for libraries and archives
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/ProjectManager/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/ProjectManager/bin)

# Ensure the same output directories for specific configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output/ProjectManager)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output/ProjectManager)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output/ProjectManager/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output/ProjectManager/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output/ProjectManager/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output/ProjectManager/bin)

set(GameUtilsDir ${CMAKE_SOURCE_DIR}/GameUtils/include)
set(ImGuiDir ${CMAKE_SOURCE_DIR}/vendor/imgui)
set(ImGuiDir ${CMAKE_SOURCE_DIR}/vendor/ImGuiFileDialog)

include_directories(${ImGuiDir})
include_directories(${GameUtilsDir})
include_directories(include)

file(GLOB_RECURSE filesToInclude include/*.hpp include/*.h)
file(GLOB_RECURSE filesToIncludeSrc src/*.cpp)

add_executable(ProjectManager main.cpp ${filesToIncludeSrc} ${filesToInclude})
target_link_libraries(ProjectManager PRIVATE glad::glad)
target_link_libraries(ProjectManager PRIVATE glfw)

target_link_libraries(ProjectManager PRIVATE imgui)
target_link_libraries(ProjectManager PUBLIC GameUtils)
target_link_libraries(ProjectManager PUBLIC ImGuiFileDialog)

# Adicione um alvo para copiar os arquivos após a construção
add_custom_command(TARGET ProjectManager POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${VCPKG_INSTALLED_DIR}/bin
    ${CMAKE_SOURCE_DIR}/output/ProjectManager
    COMMENT "Copying all items from ${SOURCE_DIR} to ${DESTINATION_DIR}"
)

# Adicione um template para copiar os arquivos após a construção
add_custom_command(TARGET ProjectManager POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/ProjectManager/templates
    ${CMAKE_SOURCE_DIR}/output/ProjectManager/templates
    COMMENT "Copying all items from ${SOURCE_DIR} to ${DESTINATION_DIR}"
)
