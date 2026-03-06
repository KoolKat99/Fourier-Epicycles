cmake_minimum_required(VERSION 3.16)

project(fourier_draw LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



include(FetchContent)

# FetchContent_Declare(
#     opencv
#     GIT_REPOSITORY https://github.com/opencv/opencv.git
#     GIT_TAG 4.7.1   # or whatever version you want
# )

# # Make it available
# FetchContent_MakeAvailable(opencv)

find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})


# Fetch KissFFT from GitHub
FetchContent_Declare(
    kissfft
    GIT_REPOSITORY https://github.com/mborgerding/kissfft.git
    GIT_TAG master
)

FetchContent_MakeAvailable(kissfft)
add_library(dft STATIC
    src/dft.cpp
)

# Add KissFFT include directory
target_include_directories(dft PUBLIC
    ${kissfft_SOURCE_DIR}
)

# Link the KissFFT library (NOT the header!)
target_link_libraries(dft PRIVATE kissfft opencv_core opencv_imgcodecs opencv_imgproc opencv_highgui)




# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_library(draw STATIC
    src/draw.cpp
)

target_link_libraries(draw
    sfml-graphics
    sfml-window
    sfml-system
)


add_executable(${PROJECT_NAME}
    src/main.cpp
)


target_link_libraries(${PROJECT_NAME}
    dft
    draw
)
