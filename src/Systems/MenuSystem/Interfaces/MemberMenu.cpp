#include "../MenuSystem.hpp"
#include "../Methods/ShowMembers.cpp"
#include "../../UserSystem/UserSystem.hpp"
#include "UpdateInfo.cpp"
// member menu
    void MenuSystem::member_menu()
    {
        std::string information;
        Users::Member current_member = userSystem.get_current_member();
        while (loggedIn)
        {
            std::cout << "\n\nMember actions:\n"
                        << "==============================\n"
                        << "0. Logout.\n"
                        << "1. View my information.\n"
                        << "2. Add credit.\n"
                        << "3. Block member.\n"
                        << "4. View request. \n"
                        << "5. Find supporter. \n"
                        << "6. View the request. \n";

            switch (prompt_choice(0, 6))
            {
                case 1:
                    clear_screen();
                    current_member.show_member_info();
                    std::cout << "\nDo you want to update information ? "
                          << "1. Yes\n"
                          << "2. No\n";
                    switch (prompt_choice(1,2)){
                        case 1: 
                            std::cout << "\nWhich information do you want to update: ";
                            std::getline(std::cin, information);
                            update_member_info(information);
                            current_member = userSystem.get_current_member();
                            std::cout << "Update Successfully";
                            break;
                        case 2:
                            break;
                    }
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

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