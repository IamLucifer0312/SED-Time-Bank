#include "MenuSystem.hpp"
#include "UserSystem.hpp"

// default constructor
MenuSystem::MenuSystem()
{
    this->userSystem = UserSystem();
}


// handle choices
int MenuSystem::prompt_choice(unsigned min, unsigned max)
{
    int choice = -1;
    std::string buffer;

    std::cout << "Enter your choice: ";
    std::getline(std::cin, buffer);
    try
    {
        choice = std::stoi(buffer);
    }
    catch (std::invalid_argument &e)
    {
        choice = -1;
    }
    catch (std::out_of_range &e)
    {
        choice = -1;
    }

    while (choice == -1)
    {
        std::cout << "Enter your choice: ";
        std::getline(std::cin, buffer);

        if (choice < min || max < choice)
            choice = -1;
        try
        {
            choice = std::stoi(buffer);
        }
        catch (std::invalid_argument &e)
        {
            choice = -1;
        }
        catch (std::out_of_range &e)
        {
            choice = -1;
        }
    }

    return choice;
}
// guest view supporter
void MenuSystem::guest_view_supporter() {};
// login menu
 void MenuSystem::login_menu() {
        std::cout << "Enter your username: ";
        std::string username;
        std::getline(std::cin, username);

        std::cout << "Enter your password: ";
        std::string password;
        std::getline(std::cin, password);

        if (userSystem.validateLogin(username, password))
        {
            bool loggedIn = true;

            while (loggedIn)
            {
                std::cout << "\nMember actions:\n"
                            << "==============================\n"
                            << "0. Logout.\n"
                            << "1. Perform member action 1.\n"
                            << "2. Perform member action 2.\n";

                switch (prompt_choice(0, 2))
                {
                case 1:

                    break;
                case 2:

                    break;
                case 0:
                    loggedIn = false;
                    break;
                }
            }
        }    
 }
// register menu
    void MenuSystem::register_menu() {
        std::string username, password, full_name, phone_number, home_address, email, city;

        std::cout << "Enter your new username: ";
        std::getline(std::cin, username);
        std::cout << "Enter your new password: ";
        std::getline(std::cin, password);

        for (const auto &member : this->members)
        {
            if (member.get_username() == username)
            {
                std::cout << "Error: Username '" << username << "' already exists.\n";
                return;
            }
        }

        if (password.empty())
        {
            std::cout << "Error: Your password cannot be empty.\n";
            return;
        }

        for (auto c : password)
        {
            if (c == ' ')
            {
                std::cout << "Error: Your password cannot contain space character.\n";
                return;
            }
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

    // guess menu
    void MenuSystem::guest_menu()
    {
        bool back = false;
        UserSystem user;

        while (!back)
        {
            std::cout << "\nGuest menu:\n"
                         "==============================\n"
                         "0. Back.\n"
                         "1. View all supporter details.\n"
                         "2. Register as member account.\n";

            switch (prompt_choice(1, 3))
            {
            case 1:
                std::cout << "supporter's details \n";
                guest_view_supporter();
                break;
            case 2:
                std::cout << "Registered...\n";
                register_menu();
                break;
            case 0:
                back = true;
                break;
            }
        }
    }

    // member menu
    void MenuSystem::member_menu()
    {
        bool back = false;

        while (!back)
        {
            std::cout << "\nMember menu:\n"
                      << "==============================\n"
                      << "0. Back.\n"
                      << "1. Log in.\n";

            switch (prompt_choice(0, 1))
            {
            case 1:
            {
                login_menu();
                break;
            }

            case 0:
                back = true;
                break;
            }
        }
    }

    void MenuSystem::admin_menu() {}

// main loop
void MenuSystem::main_loop()
{
    userSystem.load_database();
    

    std::cout << "\n"
              << "======================================\n"
              << "EEET2482/COSC2082 ASSIGNMENT\n"
              << "TIME BANK APPLICATION\n"
              << "\n"
              << "Instructor: Mr. Tran Duc Linh\n"
              << "Group: Group 2\n"
              << "s4021255, Cu Duc Quang\n"
              << "s3978616, Nguyen Trong Tien\n"
              << "s4000948, Pham Hung Anh\n"
              << "s3979081, Tran Phan Trong Phuc"
              << "\n======================================\n\n";

    while (!this->quit)
    {
        std::cout << "\nMAIN MENU\n"
                  << "=========================\n"
                  << "--> 0. Exit\n"
                  << "--> 1. Login as Guest\n"
                  << "--> 2. Login as Member\n"
                  << "--> 3. Login as Admin\n";

        switch (prompt_choice(1, 5))
        {
        case 1:
            guest_menu();
            break;
        case 2:
            member_menu();
            break;
        case 3:
            admin_menu();
            break;
        case 0:
            this->quit = true;
            std::cout << "FUCK YOU !!!!!!" << std::endl;
        default:
            break;
        }
    }
}