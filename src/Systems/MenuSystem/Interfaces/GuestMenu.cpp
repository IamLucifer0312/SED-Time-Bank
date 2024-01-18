#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

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
                clear_screen();
                std::cout << "Supporter's Details: \n";
                std::cout << "==============================\n";
                guest_view_supporter();
                break;
            case 2:
                clear_screen();
                std::cout << "Registered...\n";
                register_menu();
                break;
            case 0:
                back = true;
                break;
            }
        }
    }