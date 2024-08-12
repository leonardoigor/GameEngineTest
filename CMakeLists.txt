cmake_minimum_required(VERSION 3.11)

set(VCPKG_LIB_NAMES
    glad
    imgui
    glfw3
)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/GameEngine)

# Set the output directories for libraries and archives
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/GameEngine/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/GameEngine/bin)

# Ensure the same output directories for specific configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output/GameEngine)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output/GameEngine)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output/GameEngine/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output/GameEngine/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/output/GameEngine/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/output/GameEngine/bin)

project("GameEngineTest")

# Path to vcpkg executable
set(VCPKG_ROOT "C:/Program Files/vcpkg")
set(VCPKG_EXECUTABLE "${VCPKG_ROOT}/vcpkg.exe")
set(VCPKG_INSTALLED_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

# Check if vcpkg executable exists
if(NOT EXISTS ${VCPKG_EXECUTABLE})
    message(FATAL_ERROR "vcpkg executable not found at ${VCPKG_EXECUTABLE}. Please ensure vcpkg is installed.")
endif()

include(cmakes/updateSubModules.cmake)
include(cmakes/imguiFileDialodCreateLibrary.cmake)
include(cmakes/imguiCreateLibrary.cmake)

# Install dependencies specified in vcpkg.json
execute_process(
    COMMAND ${VCPKG_EXECUTABLE} install
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE VCPKG_RESULT
)

if(NOT VCPKG_RESULT EQUAL 0)
    message(FATAL_ERROR "vcpkg install failed with error code ${VCPKG_RESULT}")
endif()

message(STATUS "vcpkg dependencies installed successfully")

# Include vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_INSTALLED_DIR "${VCPKG_INSTALLED_DIR}")
set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "Target triplet for vcpkg")

foreach(item ${VCPKG_LIB_NAMES})
    set("${item}_DIR" ${VCPKG_INSTALLED_DIR}/share/${item})
    message(STATUS "Library VCPKG LINK ${item}_DIR = ${${item}_DIR}")
endforeach()

include_directories(${VCPKG_INSTALLED_DIR}/include)
link_directories(${VCPKG_INSTALLED_DIR}/lib)
link_directories(${VCPKG_INSTALLED_DIR}/bin)

# Ensure the toolchain file is used
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Project setup
find_package(glad CONFIG REQUIRED)

# find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_subdirectory(GameUtils)
add_subdirectory(ProjectManager)
add_subdirectory(GameEngine/src)
