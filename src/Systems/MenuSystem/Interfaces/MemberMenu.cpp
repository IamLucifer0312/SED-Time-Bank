#include "../MenuSystem.hpp"
#include "../Methods/ShowMembers.cpp"
#include "../../UserSystem/UserSystem.hpp"
#include "../Interfaces/Member/ViewAndUpdateInfo.cpp"
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
                member_view_my_info(current_member, information);
                break;
                    
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                clear_screen();
                show_members("member");
                break;
            case 6:
                
                break;
            case 0:
                loggedIn = false;
                break;
            }
        }
    }