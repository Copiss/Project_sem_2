cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
          # Если версия установленой программы
          # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME project)     # имя проекта   
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)    # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)   # дефайны

include_directories("ext/SFML/include/") # добавляем директории
include_directories("inc/")
include_directories(includes)
link_directories("ext/SFML/lib/") 

file(GLOB SOURCES "src/*.cpp") # Добавить все файлы cpp в src-папке в переменную SOURCES

file(GLOB HEADERS "includes/*.hpp") # Добавить все файлы hpp в include-папке в переменную HEADERS

add_executable("${PROJECT_NAME}" ${SOURCES} ${HEADERS}) # Создать исполняемый файл MyProject из исходников
           
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
        sfml-window-s-d
        sfml-system-s-d
        opengl32
        freetype
        winmm
        gdi32
        sfml-audio-s-d
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)
file(COPY "assets/" DESTINATION "/")