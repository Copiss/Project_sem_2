cmake_minimum_required(VERSION 3.15)

SET(CMAKE_CONFIGURATION_TYPES "Release")

set(PROJECT_NAME project)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_definitions(-DSFML_STATIC)

include_directories("ext/SFML/include/")
include_directories("inc/")
include_directories(includes)
link_directories("ext/SFML/lib/")

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "includes/*.hpp")

add_executable("${PROJECT_NAME}" ${SOURCES} ${HEADERS})

target_link_libraries("${PROJECT_NAME}" sfml-graphics-s
        sfml-window-s
        sfml-system-s
        opengl32
        freetype
        winmm
        gdi32
        sfml-audio-s
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)

# Копируем ресурсы в каталог собранного проекта
file(COPY "assets/" DESTINATION "/")