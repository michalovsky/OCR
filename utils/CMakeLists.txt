set(SOURCES
        src/GetExecutablePath.cpp
        src/GetProjectPath.cpp
        src/StringHelper.cpp
        )

add_library(utils ${SOURCES})
target_include_directories(utils PUBLIC src)
