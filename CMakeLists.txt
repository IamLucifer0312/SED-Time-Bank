# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(SED)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Source files
set(SOURCES

    src/Users/Admin/Admin.hpp
    src/Users/Member/member.cpp
    src/Users/User/user.cpp

    src/Database/database.cpp

    src/Systems/userSystem.cpp
    src/Systems/menuSystem.cpp

    main.cpp
)

# Create executable
add_executable(SED ${SOURCES})
