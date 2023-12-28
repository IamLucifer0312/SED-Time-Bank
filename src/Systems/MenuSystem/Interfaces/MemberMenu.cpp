#include "../MenuSystem.hpp"
#include "../Methods/ShowMembers.cpp"
#include "../../UserSystem/UserSystem.hpp"
// member menu
    void MenuSystem::member_menu()
    {

        while (loggedIn)
        {
            std::cout << "\nMember actions:\n"
                        << "==============================\n"
                        << "0. Logout.\n"
                        << "1. View my information.\n"
                        << "2. Add credit.\n"
                        << "3. Block member.\n"
                        << "4. View request. \n"
                        << "5. Find supporter. \n"
                        << "6. View all members. \n";

            switch (prompt_choice(0, 6))
            {
            case 1:

                break;
            case 2:

                break;
            case 6:
                clear_screen();
                show_members();
                break;
            case 0:
                loggedIn = false;
                break;
            }
        }
    }
    