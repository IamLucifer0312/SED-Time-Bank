#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

// Check if the file is already included.
#ifndef MENUSYSTEM_HPP
#define MENUSYSTEM_HPP

// INCLUDES
#include "../UserSystem/UserSystem.hpp" 

// user classes
#include "../../Users/Users.hpp"



class MenuSystem
{
private:
    bool quit;
    // LoginType login_type;
    std::vector<Users::Member> members;
    Users::Admin admin;
    UserSystem userSystem;
    bool loggedIn;
    std::string member_username;

public:
    // constructor
    MenuSystem();

    int prompt_choice(unsigned min, unsigned max);

    void main_loop();

    void login_menu(string role);
    void register_menu();

    void guest_view_supporter();

    // guess menu
    void guest_menu();
    
    // member menu
    void member_menu();

    // admin menu
    void admin_menu();

    // show members
    void show_members(std::string role);
    void show_members_for_city(std::string city, std::string role);
    // clear screen
    void clear_screen();

    void update_member_info(std::string information);

    // interfaces
    void member_view_my_info(Users::Member current_member, std::string information);

    //check username and change password of members for admin
    void change_new_password(std::string member_username);

    //check username and block user
    void block_member(std::string member_username);
    void unblock_member(std::string member_username);
    bool is_blocked(Users::Member member);

    //find supporter
    void find_supporter_city(std::string role);
    void find_all_supporter(std::string role);
    void find_supporter_interface(std::string role);

    friend class UserSystem;

};

#endif // MENUSYSTEM_HPP