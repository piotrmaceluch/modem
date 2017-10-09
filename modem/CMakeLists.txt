#minimalna werscja CMake
cmake_minimum_required(VERSION 2.8)

#nazwa projektu
project(Modulator)

############### MAKRA #####################
 
 # CMAKE_BINARY_DIR 
 # -jesli buduje w zrodle, to jest to to samo co CMAKE_SOURCE_DIR
 # w innym przypadku, jest to najwyzszy poziom w drzewie budowania

 # CMAKE_SOURCE_DIR
 # folder z ktorego cmake jest startowany, w tym przypaku najwyzszy poziom   # strkuktury katalogow 
 
 # EXECUTABLE_OUTPUT_PATH
 # trzeba ustawic te zmienna, by ustalic wspolne miejsce gdzie CMake
 # wstawi wszystkie pliki wykonywalne(executable), 
 # zamiast do CMAKE_CURRENT_BINARY_DIR)
 
 # LIBRARY_OUTPU_PATH
 # trzeba ustawic te zmienna, by ustalic wspolne miejsce gdzie CMake
 # wstawi wszystkie biblioteki(libraries), 
 # zamiast do CMAKE_CURRENT_BINARY_DIR)

 # PROJECT_NAME
 # nazwa projektu, ustawiana poprzez PROJECT(nazwa_projektu)

 # PROJECT_SOURCE_DIR
 # zawiera pełną ścieżkę do korzenia, dla katalogu w którym znajduje się projekt

###########################################

#ten folder bedzie zaincludowany

include_directories("${PROJECT_BINARY_DIR}")

add_executable(Modulator main.cpp)
#add_executable(Modulator functions.cpp)
#add_executable(Modulator symbol.cpp)


