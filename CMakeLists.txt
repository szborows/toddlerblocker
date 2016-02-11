set(CMAKE_VERSION_MINIMUM 3.0)

set(CMAKE_CXX_FLAGS "-std=c++14")
add_executable(toddlerblocker main.cpp)
target_link_libraries(toddlerblocker X11)
