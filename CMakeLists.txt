cmake_minimum_required(VERSION 3.2)

project(chaos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(".")
include_directories("./include/jsoncpp/dist")
link_directories("/usr/local/lib")

file(GLOB chaos_SRC
    "*.cpp"
    "Core/*.cpp"
    "Chaos/*.cpp"
    "Chaos/GameObjects/*.cpp"
    "Chaos/GameStates/*.cpp"
    "Chaos/Scenes/*.cpp"
    "include/jsoncpp/dist/jsoncpp.cpp"
)

add_executable(chaos ${chaos_SRC})

target_link_libraries(chaos SDL2)
target_link_libraries(chaos SDL2_image)
target_link_libraries(chaos SDL2_ttf)


