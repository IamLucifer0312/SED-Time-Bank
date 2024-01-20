#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <regex>

// Check if the file is already included.
#ifndef USERSYSTEM_HPP
#define USERSYSTEM_HPP

// INCLUDES

// user classes
#include "../../Users/Users.hpp"

// database class
#include "../../Database/Database.hpp"

class UserSystem
{
private:
    bool quit;
    std::vector<Users::Member> members;
    Users::Admin admin;
    Database database;
    Users::Member current_member;

public:
    // constructor
    UserSystem();

    // load and save database
    void load_database();
    void save_database();

    // validators:
    // log in
    bool validateLogin(const std::string &username, const std::string &password, std::string role);
    // username
    bool checkUsername(const std::string &username);
    // password
    bool checkPasswordEmpty(const std::string &password);
    bool checkPasswordSpace(const std::string &password);
    // email
    bool checkEmail(const string &email);

    // reigster member
    void register_member(std::string username, std::string password, std::string full_name, std::string phone_number, std::string home_address, std::string email, std::string city);

    // getters
    std::vector<Users::Member> get_members();
    Users::Member &get_current_member();
    Database &get_database();
    
    // setters
    void set_current_member(Users::Member &member);
    void set_admin(Users::Admin &admin);
    void update_current_member();
    void update_member(Users::Member &newMember);
    void update_new_password();

    friend class MenuSystem;
};

#endif // USERSYSTEM_HPP