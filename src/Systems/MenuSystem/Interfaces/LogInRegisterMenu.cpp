#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::login_menu(string role) {
        std::cout << "Enter your username: ";
        std::string username;
        std::getline(std::cin, username);

        std::cout << "Enter your password: ";
        std::string password;
        std::getline(std::cin, password);

        if (userSystem.validateLogin(username, password, role))
        {
            loggedIn = true;
            std::cout << "Login successfully!\n";
            if (role == "admin")
            {
                admin_menu();
            }
            else if (role == "member")
            {
                member_menu();
            }
        } else {
            std::cout << "Login failed\n";
            return;
        }   

 }
// register menu
    void MenuSystem::register_menu() {
        std::string username, password, full_name, phone_number, home_address, email, city;

        std::cout << "Enter your new username: ";
        std::getline(std::cin, username);
        std::cout << "Enter your new password: ";
        std::getline(std::cin, password);

        if (userSystem.checkUSername(username))
        {
            std::cout << "Username already exists. Please try again.\n";
            return;
        }

        if (!userSystem.checkPasswordEmpty(password))
        {
            std::cout << "Password cannot be empty. Please try again.\n";
            return;
        }

        if (!userSystem.checkPasswordSpace(password))
        {
            std::cout << "Password cannot contain space. Please try again.\n";
            return;
        }

        std::cout << "Enter your full name: ";
        std::getline(std::cin, full_name);

        std::cout << "Enter your phone number: ";
        std::getline(std::cin, phone_number);

        std::cout << "Enter your home address: ";
        std::getline(std::cin, home_address);

        std::cout << "Enter your email: ";
        std::getline(std::cin, email);

        std::cout << "Enter your city: ";
        std::getline(std::cin, city);

        userSystem.register_member(username, password, full_name, phone_number, home_address, email, city);
        userSystem.save_database();
    }
