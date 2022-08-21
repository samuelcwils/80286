cmake_minimum_required(VERSION 3.23.2)

project("80286")

include_directories(include/)

add_executable(${PROJECT_NAME}  
    src/add.cpp   
    src/cpu.cpp
    src/flags.cpp
    src/genpurp.cpp
    src/main.cpp
    src/sub.cpp  
    src/logic.cpp 
    src/uncondtrans.cpp
)
