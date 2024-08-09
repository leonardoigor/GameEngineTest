include_directories(include)

file(GLOB_RECURSE FilesINFolder *.cpp *.h *hpp)

foreach(file ${FilesINFolder})
    message(STATUS "----- file compiled (${file})")
endforeach()

add_library(GameUtils STATIC ${FilesINFolder})