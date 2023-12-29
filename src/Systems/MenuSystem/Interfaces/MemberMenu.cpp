#include "../MenuSystem.hpp"
#include "../Methods/ShowMembers.cpp"
#include "../../UserSystem/UserSystem.hpp"
#include "UpdateInfo.cpp"
// member menu
    void MenuSystem::member_menu()
    {
        std::string information;
        std::string answer;
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
                        << "6. View all members. \n";

            switch (prompt_choice(0, 6))
            {
            case 1:
                clear_screen();
                // std::cout << '\n';
                current_member.show_member_info();
                std::cout << "\nDo you want to change information (Y/N): ";
                std::getline(std::cin, answer);
                if (answer == "Y"){
                    std::cout << "\nWhich information do you want to update: ";
                    std::getline(std::cin, information);
                    update_member_info(information);
                    current_member = userSystem.get_current_member();
                    std::cout << "Update Successfully";
                } else if (answer == "N"){
                    break;
                } else {
                    std::cerr << "Please type Y for Yes or N for No\n";
                }
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
                clear_screen();
                show_members();
                break;
            case 0:
                loggedIn = false;
                break;
            }
        }
    }