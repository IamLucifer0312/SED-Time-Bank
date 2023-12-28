#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

// Check if the file is already included.
#ifndef USERSYSTEM_HPP
#define USERSYSTEM_HPP

// INCLUDES


// user classes
#include "../../Users/Users.hpp"

// database class
#include "../../Database/Database.hpp"

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
    Database database;
    //std::string currentUser;

public:
    // constructor
    UserSystem();

    // load and save database
    void load_database();
    void save_database();

    // log in
    bool log_in(const std::string &username, const std::string &password, Database &database);
    // validators:
    // log in
    bool validateLogin(const std::string &username, const std::string &password);

    bool checkUSername(const std::string &username);
    bool checkPasswordEmpty(const std::string &password);
    bool checkPasswordSpace(const std::string &password);

    // reigster member
    void register_member( std::string username, std::string password, std::string full_name, std::string phone_number, std::string home_address, std::string email, std::string city);

    friend class MenuSystem;
};

#endif // USERSYSTEM_HPP