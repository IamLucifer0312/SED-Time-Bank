#include "MenuSystem.hpp"

    // guess menu
    void MenuSystem::guest_menu(Database &database)
    {
        bool back = false;
        UserSystem system;

        while (!back)
        {
            std::cout << "\nGuest menu:\n"
                         "==============================\n"
                         "0. Back.\n"
                         "1. View all supporter details.\n"
                         "2. Register as member account.\n";

            switch (system.prompt_choice(1, 3))
            {
            case 1:
                std::cout << "supporter's details \n";
                system.guest_view_supporter();
                break;
            case 2:
                std::cout << "Registered...\n";
                system.register_member(database);
                break;
            case 0:
                back = true;
                break;
            }
        }
    }

    // member menu
    void MenuSystem::member_menu(Database &database, UserSystem &system)
    {
        bool back = false;

        while (!back)
        {
            std::cout << "\nMember menu:\n"
                      << "==============================\n"
                      << "0. Back.\n"
                      << "1. Log in.\n";

            switch (system.prompt_choice(0, 1))
            {
            case 1:
            {
                std::cout << "Enter your username: ";
                std::string username;
                std::getline(std::cin, username);

                std::cout << "Enter your password: ";
                std::string password;
                std::getline(std::cin, password);

                if (system.log_in(username, password, database))
                {
                    bool loggedIn = true;

                    while (loggedIn)
                    {
                        std::cout << "\nMember actions:\n"
                                  << "==============================\n"
                                  << "0. Logout.\n"
                                  << "1. Perform member action 1.\n"
                                  << "2. Perform member action 2.\n";

                        switch (system.prompt_choice(0, 2))
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
                break;
            }

            case 0:
                back = true;
                break;
            }
        }
    }

    void MenuSystem::admin_menu() {}