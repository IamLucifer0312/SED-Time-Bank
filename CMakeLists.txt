# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(Group2_Program)

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
    src/Classes/Skill/skill.cpp
    src/Classes/Period/period.cpp
    src/Classes/AvailableJob/availableJob.cpp
    src/Classes/Review/review.cpp
    src/Classes/Request/request.cpp
    main.cpp
)

# Create executable
add_executable(Group2_Program ${SOURCES})
