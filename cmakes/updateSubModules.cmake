# Install dependencies specified in vcpkg.json
execute_process(
    COMMAND git submodule update --init --recursive
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE VCPKG_RESULT
)

if(NOT VCPKG_RESULT EQUAL 0)
    message(FATAL_ERROR "get submodules failed with error code ${VCPKG_RESULT}")
else()
    message(STATUS "get submodules success with  code ${VCPKG_RESULT}")
endif()

# Adiciona o diretório do ImGui como subdiretório
