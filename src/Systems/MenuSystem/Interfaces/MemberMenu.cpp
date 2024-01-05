#include "../MenuSystem.hpp"
#include "../Methods/ShowMembers.cpp"
#include "../../UserSystem/UserSystem.hpp"
#include "../Interfaces/Member/ViewAndUpdateInfo.cpp"
#include "UpdateInfo.cpp"
#include "find_supporter_city.cpp"
#include "Find_supporter.cpp"
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
                        << "6. View the tutor. \n";

            switch (prompt_choice(0, 6))
            {
            case 1:
                member_view_my_info(current_member, information);
                break;
                    
            case 2:

                break;
            case 3:
                clear_screen();
                std::cout << "Block or unblock member?\n"
                            << "1. Block\n"
                            << "2. Unblock\n";
                switch (prompt_choice(1, 2))
                {
                case 1:
                    std::cout << "\nWhich user do you want to block: ";
                    std::getline(std::cin, member_username);
                    block_member(member_username);
                    break;
                case 2:
                    std::cout << "\nWhich user do you want to unblock: ";
                    std::getline(std::cin, member_username);
                    unblock_member(member_username);
                    break;
                }
                break;
            case 4:

                break;
            case 5:
                clear_screen();
                find_supporter_interface("member");
                break;
            case 6:
                
                break;
            case 0:
                loggedIn = false;
                break;
            }
        }
    }