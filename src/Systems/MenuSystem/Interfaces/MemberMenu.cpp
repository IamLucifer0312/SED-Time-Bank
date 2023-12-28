#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"
// member menu
void MenuSystem::member_menu()
{
    bool back = false;
    UserSystem user;

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