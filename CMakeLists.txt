# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(SED)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Source files
set(SOURCES

    src/Users/Admin/admin.cpp
    src/Users/Member/member.cpp
    src/Users/User/user.cpp

    src/Database/database.cpp

    src/Systems/UserSystem/userSystem.cpp
    

    src/Systems/MenuSystem/menuSystem.cpp
    src/Skill/skill.cpp
    src/Period/period.cpp

    main.cpp
)

# Create executable
add_executable(SED ${SOURCES})
