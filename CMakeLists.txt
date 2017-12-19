cmake_minimum_required(VERSION 3.5)
project (Modem)

find_package(Threads REQUIRED)

add_compile_options(-std=c++14 -pedantic -Wall -Wextra)

add_executable(Modem modem_test.cpp)

install(TARGETS Modem RUNTIME DESTINATION bin)

target_link_libraries(${PROJECT_NAME}
    gtest
    gtest_main
    ${CMAKE_THREAD_LIBS_INIT}
)
