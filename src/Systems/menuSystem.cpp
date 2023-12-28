#include "MenuSystem.hpp"
#include "UserSystem.hpp"

    // guess menu
    void MenuSystem::guest_menu(Database &database)
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

            switch (user.prompt_choice(1, 3))
            {
            case 1:
                std::cout << "supporter's details \n";
                user.guest_view_supporter();
                break;
            case 2:
                std::cout << "Registered...\n";
                user.register_member(database);
                break;
            case 0:
                back = true;
                break;
            }
        }
    }

    // member menu
    void MenuSystem::member_menu(Database &database)
    {
        bool back = false;
        UserSystem user;

        while (!back)
        {
            std::cout << "\nMember menu:\n"
                      << "==============================\n"
                      << "0. Back.\n"
                      << "1. Log in.\n";

            switch (user.prompt_choice(0, 1))
            {
            case 1:
            {
                std::cout << "Enter your username: ";
                std::string username;
                std::getline(std::cin, username);

                std::cout << "Enter your password: ";
                std::string password;
                std::getline(std::cin, password);

                if (user.log_in(username, password, database))
                {
                    bool loggedIn = true;

                    while (loggedIn)
                    {
                        std::cout << "\nMember actions:\n"
                                  << "==============================\n"
                                  << "0. Log out.\n"
                                  << "1. View my information.\n"
                                  << "2. Add credit.\n"
                                  << "3. Block member.\n"
                                  << "4. View request. \n"
                                  << "5. Find supporter. \n"
                                  << "6. View the tutor. \n";
                        switch (user.prompt_choice(0, 6))
                        {
                        case 1:

                            break;
                        case 2:

                            break;
                        case 3:

                            break;
                        case 4:

                            break;
                        case 5:

                            break;
                        case 6:

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