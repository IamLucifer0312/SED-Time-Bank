#include "../MenuSystem.hpp"
#include "../Methods/ShowMembers.cpp"
#include "../../UserSystem/UserSystem.hpp"
#include "UpdateInfo.cpp"
// member menu
    void MenuSystem::member_menu()
    {
        std::string field;
        std::string answer;
        Users::Member current_member = userSystem.get_current_member();
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
                current_member.show_member_info();
                std::cout << "Do you want to change information (Y/N): ";
                std::getline(std::cin, answer);
                if (answer == "Y"){
                    std::cout << "Which field do you want to update: ";
                    std::getline(std::cin, field);
                    update_member_info(field);
                    current_member = userSystem.get_current_member();
                } else if (answer == "N"){
                    break;
                } else {
                    std::cout << "Invalid input.\n";
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