#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

// Check if the file is already included.
#ifndef USERSYSTEM_HPP
#define USERSYSTEM_HPP

// INCLUDES

// menu system
#include "MenuSystem.hpp"

// user classes
#include "../Users/Users.hpp"

// database class
#include "../Database/Database.hpp"

enum LoginType
{
    NONE,
    GUEST,
    MEMBER,
    ADMIN
};

class UserSystem
{
private:
    bool quit;
    LoginType login_type;
    std::vector<Users::Member> members;
    Users::Admin admin;

public:

    // log in
    bool log_in(const std::string &username, const std::string &password, Database &database);


    void guest_view_supporter();

    // reigster member
    bool register_member(Database &database);

    // handle choices
    static int prompt_choice(unsigned min, unsigned max);

    // main loop
    void main_loop();

    friend class MenuSystem;
};

#endif // USERSYSTEM_HPP