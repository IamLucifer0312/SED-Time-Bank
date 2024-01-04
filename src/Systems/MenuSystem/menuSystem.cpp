#include "MenuSystem.hpp"
#include "../UserSystem/UserSystem.hpp"
#include "Interfaces/GuestMenu.cpp"
#include "Interfaces/MemberMenu.cpp"
#include "Interfaces/AdminMenu.cpp"
#include "Interfaces/LoginRegisterMenu.cpp"
#include "Methods/ClearScreen.cpp"
#include "Interfaces/change_new_password.cpp"

// default constructor
MenuSystem::MenuSystem()
{
    this->quit = false;
    this->userSystem = UserSystem();
    this->loggedIn = false;
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

// main loop
void MenuSystem::main_loop()
{
    userSystem.load_database();
    
    clear_screen();

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
            clear_screen();
            guest_menu();
            break;
        case 2:
            clear_screen();
            login_menu("member");
            break;
        case 3:
            clear_screen();
            login_menu("admin");
            break;
        case 0:
            this->quit = true;
            std::cout << "Have a nice day !!!" << std::endl;
        default:
            break;
        }
    }
}