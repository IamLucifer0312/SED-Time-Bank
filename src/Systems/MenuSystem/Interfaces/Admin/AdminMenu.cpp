#include "../../MenuSystem.hpp"
#include "../../../UserSystem/UserSystem.hpp"
#include "ChangePassword.cpp"
void MenuSystem::admin_menu()
{
    while (loggedIn)
    {
        clear_screen();
        std::cout << "Admin menu: \n"
                        << "==============================\n"
                        << "0. Logout.\n"
                        << "1. View list member.\n";

        switch (prompt_choice(0, 1))
        {
            case 1:
                clear_screen();
                show_members("admin");
                std::cout << "Do you want to change password for any User ?" << std::endl
                          << "1. Yes\n"
                          << "2. No\n";

                switch (prompt_choice(0, 1))
                {
                    case 1: 
                        std::cout << "\nWhich user do you want to update password: ";
                        std::getline(std::cin, member_username);
                        change_new_password(member_username);
                        break;
                    case 0:
                        break;
                }
                break;
            case 0:
                loggedIn = false;
                break;
        }
    }
}