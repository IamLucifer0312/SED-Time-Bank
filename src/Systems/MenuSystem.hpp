#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

// Check if the file is already included.
#ifndef MENUSYSTEM_HPP
#define MENUSYSTEM_HPP

// INCLUDES
// user classes
#include "../Users/Users.hpp"

// database class
#include "../Database/Database.hpp"

// enum LoginType
// {
//     NONE,
//     GUEST,
//     MEMBER,
//     ADMIN
// };

class MenuSystem
{
private:
    bool quit;
    // LoginType login_type;
    std::vector<Users::Member> members;
    Users::Admin admin;

public:

    // guess menu
    void guest_menu(Database &database);
    
    // member menu
    void member_menu(Database &database);

    // admin menu
    void admin_menu();

    friend class UserSystem;

};

#endif // MENUSYSTEM_HPP