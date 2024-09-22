cmake_minimum_required(VERSION 3.10)
project(MyProject CXX)

# Specify the C standard
set(CMAKE_CXX_STANDARD 11)

# Add the executable
add_executable(MyExecutable main.cpp)
find_package(openCV REQUIRED)
# Include libraries (modify as needed)
# For example, if you need to link with math library
target_link_libraries(MyExecutable ${OpenCV_LIBS})  # Replace 'm' with other libraries as needed

# If you have more libraries, you can add them like this:
# target_link_libraries(MyExecutable library1 library2 ...)
