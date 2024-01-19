#include "../../MenuSystem.hpp"
#include "../../../UserSystem/UserSystem.hpp"

// guess menu
void MenuSystem::guest_menu()
{
    bool back = false;
    UserSystem user;

    while (!back)
    {
        clear_screen();
        std::cout << "\nGuest menu:\n"
                     "==============================\n"
                     "0. Back.\n"
                     "1. View all supporter details.\n"
                     "2. Register as member account.\n";

        switch (prompt_choice(0, 2))
        {
        case 1:
            clear_screen();
            std::cout << "Supporter's Details: \n";
            std::cout << "==============================\n";
            guest_view_supporter();
            std::cout << "Press Enter to continue.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        case 2:
            clear_screen();
            std::cout << "Registering...\n";
            register_menu();
            break;
        case 0:
            back = true;
            break;
        }
    }
}