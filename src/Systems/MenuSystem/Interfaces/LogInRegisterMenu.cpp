#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::login_menu(string role)
{
    std::cout << "Enter your username: ";
    std::string username;
    std::getline(std::cin, username);

    std::cout << "Enter your password: ";
    std::string password;
    std::getline(std::cin, password);

    if (userSystem.validateLogin(username, password, role))
    {
        loggedIn = true;
        std::cout << "Login successfully! Press any key to continue.\n";
        std::cin.get();
        if (role == "admin")
        {
            admin_menu();
        }
        else if (role == "member")
        {
            member_menu();
        }
    }
    else
    {
        std::cout << "Login failed. Press any key to continue\n";
        std::cin.get();
        return;
    }
}
// register menu
void MenuSystem::register_menu()
{
    std::string username, password, full_name, phone_number, home_address, email, city;

    std::cout << "Enter your new username: ";
    std::getline(std::cin, username);
    if (userSystem.checkUSername(username))
    {
        std::cout << "Username already exists. Please try again.\n";
        return;
    }

    std::cout << "Enter your new password: ";
    std::getline(std::cin, password);

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

    try {
        std::stoi(phone_number);
    } catch (const std::invalid_argument&) {
        std::cout << "Invalid phone number. Please try again.\n";
        return;
    } catch (const std::out_of_range&) {
        std::cout << "Invalid phone number. Please try again.\n";
        return;
    }

    if (phone_number.length() > 10)
    {
        std::cout << "Phone number is too long. Please try again.\n";
        return;
    }
    else if (phone_number.length() < 10)
    {
        std::cout << "Phone number is too short. Please try again.\n";
        return;
    }
    

    std::cout << "Enter your home address: ";
    std::getline(std::cin, home_address);

    std::cout << "Enter your email: ";
    std::getline(std::cin, email);

    if(!userSystem.is_email_valid(email))
    {
        std::cout << "Invalid email. Please try again.\n";
        return;
    }

    std::cout << "Which city do you want to register \n"
              << "1. Ha noi\n"
              << "2. Sai gon\n";
    switch (prompt_choice(1, 2))
    {
    case 1:
        city = "Ha noi";
        break;
    case 2:
        city = "Sai gon";
        break;
    }

    userSystem.register_member(username, password, full_name, phone_number, home_address, email, city);
    userSystem.save_database();
}
