set(SOURCES
        src/TextRecognizer.cpp
        )

add_library(recognition ${SOURCES})
target_include_directories(recognition PUBLIC src)
