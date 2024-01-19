#include "../../MenuSystem.hpp"
#include "../../../UserSystem/UserSystem.hpp"
#include "ChangePassword.cpp"
void MenuSystem::admin_menu()
{
    while (loggedIn)
    {
        bool user_found = false;
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

            switch (prompt_choice(1, 2))
            {
            case 1:
                std::cout << "\nWhich user do you want to update password: ";
                std::getline(std::cin, member_username);

                // check if username exists
                for (Users::Member user : userSystem.get_database().get_all_members())
                {
                    if (user.get_username() == member_username)
                    {
                        user_found = true;
                        break;
                    }
                }
                if (!user_found)
                {
                    std::cout << "Username not found. Please try again\n";
                    std::cout << "Press Enter to continue.\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                change_new_password(member_username);
                break;
            case 2:
                break;
            }
            break;
        case 0:
            loggedIn = false;
            break;
        }
    }
}