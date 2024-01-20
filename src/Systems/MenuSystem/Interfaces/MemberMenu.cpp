#include "../MenuSystem.hpp"
#include "../Methods/ShowMembers.cpp"
#include "../../UserSystem/UserSystem.hpp"
#include "Member/ViewAndUpdateInfo.cpp"
#include "Member/AddCredit.cpp"
#include "Member/UpdateInfo.cpp"
#include "FindSupporter/FindSupporter.cpp"
//Job and Request
#include "JobAndRequest/AvailableJob/BookJob.cpp"
#include "JobAndRequest/Request/ViewCurrentRequests.cpp"
#include "JobAndRequest/Request/RateApprovedJob.cpp"
#include "JobAndRequest/AvailableJob/UpdateAvailableJob.cpp"
#include "JobAndRequest/Request/MakeRequest.cpp"

#include "Block/BlockMemberInterface.cpp"
// member menu
void MenuSystem::member_menu()
{
    std::string information;
    while (loggedIn)
    {
        clear_screen();
        std::cout << "Member menu:\n"
                  << "==============================\n"
                  << "0. Logout.\n"
                  << "1. View my information.\n"
                  << "2. Add credit.\n"
                  << "3. Block member.\n"
                  << "4. View current requests. \n"
                  << "5. Find supporter. \n"
                  << "6. Update available job. \n"
                  << "7. View approved requests. \n";

        switch (prompt_choice(0, 7))
        {
        case 1:
            clear_screen();
            member_view_my_info(information);
            break;

        case 2:
            clear_screen();
            add_credit();
            break;
        case 3:
            clear_screen();
            block_member_interface();
            break;
        case 4:
            clear_screen();
            view_current_requests();
            break;
        case 5:
            clear_screen();
            find_supporter_interface();
            break;
        case 6:
            clear_screen();
            update_available_job();
            break;
        case 7:
            clear_screen();
            view_approved_requests();
            break;
        case 0:
            loggedIn = false;
            break;
        }
    }
}