#include "MenuSystem.hpp"
#include "../UserSystem/UserSystem.hpp"
#include "Interfaces/Guest/GuestMenu.cpp"
#include "Interfaces/MemberMenu.cpp"
#include "Interfaces/Admin/AdminMenu.cpp"
#include "Interfaces/LogInRegisterMenu.cpp"
#include "Methods/ClearScreen.cpp"

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

    while (choice == -1)
    {
        std::cout << "Enter your choice: ";
        std::getline(std::cin, buffer);

        // check if input is a number
        try
        {
            choice = std::stoi(buffer);

            // check if input is in range
            if (choice < min || choice > max)
            {
                if (min == max)
                    std::cerr << "Choice out of range. The choice must be " << min << "." << std::endl;
                else
                    std::cerr << "Choice out of range. Please try again from (" << min << " to " << max << ")." << std::endl;
                choice = -1;
            }
        }
        catch (std::invalid_argument &e)
        {
            if (min == max)
                std::cerr << "Invalid choice. The choice must be " << min << "." << std::endl;
            else
                std::cerr << "Invalid choice. Please enter your choice from (" << min << " to " << max << ")." << std::endl;
        }
        catch (std::out_of_range &e)
        {
            std::cerr << "Choice out of range. Please try again." << std::endl;
        }
    }

    return choice;
}

// main loop
void MenuSystem::main_loop()
{
    userSystem.load_database();

    clear_screen();
    while (!this->quit)
    {

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

        std::cout << "\nMAIN MENU\n"
                  << "=========================\n"
                  << "--> 0. Exit\n"
                  << "--> 1. Login as Guest\n"
                  << "--> 2. Login as Member\n"
                  << "--> 3. Login as Admin\n";

        switch (prompt_choice(0, 3))
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