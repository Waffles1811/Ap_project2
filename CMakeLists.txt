cmake_minimum_required(VERSION 3.22.1)
project(AP)

set(CMAKE_CXX_STANDARD 11)


# Find SFML package
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

#only .cpp files
add_executable(AP main.cpp
        game.cpp
        camera.cpp
        entityModel.cpp
        view.cpp
        factories/graphic_factory.cpp
)

target_link_libraries(AP ${CMAKE_SOURCE_DIR}/library/libAPDoodleJumpLibrary.so)

target_include_directories(AP PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link SFML libraries
target_link_libraries(AP sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

