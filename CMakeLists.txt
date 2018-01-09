cmake_minimum_required(VERSION 3.5)
project(modem)

find_package(Threads REQUIRED)

add_compile_options(-std=c++14 -pedantic -Wall -Wextra)

add_executable(modem main.cpp 
                     Modem.cpp
                     Modulator.cpp
                     Demodulator.cpp                     
                     Modulator_functions.cpp
					 Demodulator_functions.cpp
                     modulator_ut.cpp
					 demodulator_ut.cpp
					 modem_ut.cpp
			  )


install(TARGETS modem RUNTIME DESTINATION bin)

target_link_libraries(${PROJECT_NAME}
    gtest
    gtest_main
    ${CMAKE_THREAD_LIBS_INIT}
)
