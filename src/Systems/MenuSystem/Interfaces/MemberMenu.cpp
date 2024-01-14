#include "../MenuSystem.hpp"
#include "../Methods/ShowMembers.cpp"
#include "../../UserSystem/UserSystem.hpp"
#include "../Interfaces/Member/ViewAndUpdateInfo.cpp"
#include "../Interfaces/Member/AddCredit.cpp"
#include "../Interfaces/Member/BookJob.cpp"
#include "UpdateInfo.cpp"
#include "find_supporter_city.cpp"
#include "find_all_supporter.cpp"
#include "find_supporter_availableTime.cpp"
#include "Find_supporter.cpp"
#include "Member/ViewSentRequest.cpp"
#include "AddAvailableJob.cpp"
#include "Member/MakeRequest.cpp"
// member menu
void MenuSystem::member_menu()
{
    std::string information;
    while (loggedIn)
    {
        clear_screen();
        std::cout << "\n\nMember actions:\n"
                  << "==============================\n"
                  << "0. Logout.\n"
                  << "1. View my information.\n"
                  << "2. Add credit.\n"
                  << "3. Block member.\n"
                  << "4. View received request. \n"
                  << "5. Find supporter. \n"
                  << "6. View sent request. \n"
                  << "7. Add available job. \n";

        // testing
        const AvailableJob &tempJob = (userSystem.get_database().find_member("hung anh").get_available_jobs())[0];
        Period tempTime = Period();

        switch (prompt_choice(0, 7))
        {
        case 1:
            member_view_my_info(information);
            break;

        case 2:
            add_credit();
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

            // testing
            // cout << tempJob.get_supporter_name() << std::endl;
            // make_request(tempJob, tempTime);
            break;
        case 6:
            clear_screen();
            view_sent_request();
            break;
        case 7:
            add_available_job();
            break;
        case 0:
            loggedIn = false;
            break;
        }
    }
}