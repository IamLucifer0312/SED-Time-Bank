#include "../../../MenuSystem.hpp"
#include "../../../../../Classes/Request/Request.hpp"
#include "../../../../../Classes/Review/Review.hpp"
#include <string>

using std::cin;
using std::cout;

#define print_status(status)                                         \
    switch (status)                                                  \
    {                                                                \
    case 0:                                                          \
        cout << "\tStatus: PENDING" << std::endl;                    \
        break;                                                       \
    case 2:                                                          \
        cout << "\t>> Your request has been REJECTED!" << std::endl; \
        break;                                                       \
    default:                                                         \
        cout << "Failed to print status" << std::endl;               \
        break;                                                       \
    }

void MenuSystem::view_sent_request()
{
    bool is_running = true;
    while (is_running)
    {
        vector<Request> &requests_list = this->userSystem.get_current_member().get_sent_requests();

        // check if there are no requests
        if (requests_list.size() == 0)
        {
            clear_screen();
            cout << "There are no requests." << std::endl;

            cout << "0. Back" << std::endl;

            switch (prompt_choice(0, 0))
            {
            case 0:
                is_running = false;
                break;
            default:
                is_running = false;
                break;
            }
        }

        else
        {
            for (int i = 0; i < requests_list.size(); ++i)
            {
                Request request = requests_list[i];
                cout << "Request " << i + 1 << ":" << std::endl;
                cout << "\tSupporter: " << request.get_supporter() << std::endl;
                cout << "\tWork time: " << request.get_job().get_available_time().get_start_time_string() << " - " << request.get_job().get_available_time().get_end_time_string() << std::endl;
                cout << "\tCredit: " << request.get_total_credit() << std::endl;
                cout << "\tSkill: " << request.get_job().get_skill().get_skill_name() << std::endl;
                print_status(request.get_status());
                cout << std::endl;
            }

            cout << "0. Back" << std::endl;

            switch (prompt_choice(0, 0))
            {
            case 0:
                is_running = false;
                break;

            default:
                break;
            }
        }
    }
}
