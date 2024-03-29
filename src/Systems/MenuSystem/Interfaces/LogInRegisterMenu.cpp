#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::login_menu(string role)
{
    std::cout << "Enter your username: ";
    std::string username;
    std::getline(std::cin, username);
    bool user_found = false;

    if (role == "member")
    {
        // check if username exists
        for (Users::Member user : userSystem.get_database().get_all_members())
        {
            if (user.get_username() == username)
            {
                user_found = true;
                break;
            }
        }
    }
    else if (role == "admin")
    {
        // check if username exists
        for (Users::Admin user : userSystem.get_database().get_all_admins())
        {
            if (user.get_username() == username)
            {
                user_found = true;
                break;
            }
        }
    }
    if (!user_found)
    {
        std::cout << "Username not found. Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter your password: ";
    std::string password;
    std::getline(std::cin, password);

    if (userSystem.validateLogin(username, password, role))
    {
        loggedIn = true;
        std::cout << "Login successfully! Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        std::cout << "Wrong password or username. Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
}
// register menu
void MenuSystem::register_menu()
{
    std::string username, password, full_name, phone_number, home_address, email, city;

    std::cout << "Enter your new username: ";
    std::getline(std::cin, username);
    if (userSystem.checkUsername(username))
    {
        std::cout << "Username already exists. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter your new password: ";
    std::getline(std::cin, password);

    if (!userSystem.checkPasswordEmpty(password))
    {
        std::cout << "Password cannot be empty. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (!userSystem.checkPasswordSpace(password))
    {
        std::cout << "Password cannot contain space. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter your full name: ";
    std::getline(std::cin, full_name);

    std::cout << "Enter your phone number: ";
    std::getline(std::cin, phone_number);

    try
    {
        std::stoi(phone_number);
    }
    catch (const std::invalid_argument &)
    {
        std::cout << "Invalid phone number. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    catch (const std::out_of_range &)
    {
        std::cout << "Invalid phone number. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (phone_number.length() > 10)
    {
        std::cout << "Phone number is too long. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    else if (phone_number.length() < 10)
    {
        std::cout << "Phone number is too short. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter your home address: ";
    std::getline(std::cin, home_address);

    std::cout << "Enter your email: ";
    std::getline(std::cin, email);

    if (!userSystem.checkEmail(email))
    {
        std::cout << "Invalid email. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    for (Users::Member user : userSystem.get_database().get_all_members())
    {
        if (user.get_email() == email)
        {
            std::cout << "Email already exists. Please try again.\n";
            std::cout << "Press Enter to continue.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
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
    std::cout << "Register successfully! Press Enter to continue.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    userSystem.save_database();
}
