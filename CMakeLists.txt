#minimalna werscja CMake
cmake_minimum_required(VERSION 2.8)

#nazwa projektu - Modem
project(Modem)

#Ustaw folder wyjściowy, w którym program zostanie stworzony
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#Te foldery zostaną zainkludowane:
include_directories("${PROJECT_BINARY_DIR}")


add_executable(Modem main.cpp)



#zmienne globalne:

# CMAKE_BINARY_DIR - jeśli się buduje in-source -> to samo co CMAKE_SOURCE_DIR
#   				 w innym przpadku, jest to katalog nadrzędny całego drzewa budowania

# CMAKE_SOURCE_DIR - katalog, gdzie cmake zaczyna się. np. najwyższy poziom katalogu źródłowego

# EXECUTABLE_SOURCE_DIR - zmienna określająca wspólne miejsce, gdzie CMake powinien włożyć wszystkie pliki wykonywalne (zamiast CMAKE_CURRENT_BINARY_DIR)
#			SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}\bin)

#PROJECT_NAME - nazwa projektu, ustawiana przez komendę PROJECT()

#PROJECT_SOURCE_DIR - zawiera pełną ścieżkę do korzenia, katalogu źródłowego projektu :D
#						np. do najbliższego katalogu, gdzie CMakeLists.txt zawiera komendę PROJECT()

