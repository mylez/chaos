cmake_minimum_required(VERSION 3.2)

project(chaos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("/usr/local/include")
include_directories("/usr/local/include/libxml2")
include_directories(".")
include_directories("./Core/include/jsoncpp/dist")
include_directories("./Core/include/SDL_FontCache")

link_directories("/usr/local/lib")

file(GLOB chaos_SRC
        "*.cpp"
        "Core/*.cpp"
        #"UI/*.cpp"
        "Chaos/*.cpp"
        "Components/*.cpp"
        "Systems/*.cpp"
        "GameStates/*.cpp"
        "Core/include/jsoncpp/dist/jsoncpp.cpp"
        "Core/include/SDL_FontCache/SDL_FontCache.c"
        "Core/include/zlib-1.2.11/*c"
)

add_executable(chaos ${chaos_SRC})

target_link_libraries(chaos xml2)
target_link_libraries(chaos SDL2)
target_link_libraries(chaos SDL2_image)
target_link_libraries(chaos SDL2_ttf)
target_link_libraries(chaos SDL2_gfx)
