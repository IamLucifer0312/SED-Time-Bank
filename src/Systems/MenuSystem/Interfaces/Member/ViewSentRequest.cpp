#include "../../MenuSystem.hpp"
#include "../../../../Request/Request.hpp"
#include "../../../../Review/Review.hpp"
#include <string>

using std::cin;
using std::cout;

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
                cout << "\tStatus: " << request.get_status_string() << std::endl;
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
