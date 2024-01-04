#include "../../MenuSystem.hpp"
#include <vector>
#include "../../../../Request/Request.hpp"

using std::cout;

void MenuSystem::view_received_request()
{
    bool is_running = true;
while (is_running)
{

vector<Request *> requests_list = this->userSystem.get_current_member().get_received_requests();

for (int i = 0; i < requests_list.size(); ++i) {
        Request* request = requests_list[i];
        cout << "Request " << i + 1 << ":" << std::endl;
        cout << "Host: " << request->get_host() << std::endl;
        cout << "Work time: " << request->get_work_time() << std::endl;
        cout << "Credit: " << request->get_total_credit() << std::endl;
        cout << "Skill: " << request->get_job().get_skill().get_skill_name() << std::endl;
    }

    cout << "What would you like to do?" << std::endl;
    cout << "0. Back" << std::endl;
    cout << "1. Accept or reject a request" << std::endl;

    switch (prompt_choice(0, 1))
    {
    case 0:
        is_running = false;
        break;

    case 1:
        accept_or_reject_request(requests_list);
        break;
    }
}
}


void accept_or_reject_request(vector<Request *> requests_list){
    MenuSystem menuSystem;
    cout << "Enter the number of the request you want to accept or reject: ";
    int selected_request_number = menuSystem.prompt_choice(1, requests_list.size() + 1);
    
    Request* selected_request = requests_list[selected_request_number - 1];
        cout << "Request " << selected_request_number << ":" << std::endl;
        cout << "Host: " << selected_request->get_host() << std::endl;
        cout << "Work time: " << selected_request->get_work_time() << std::endl;
        cout << "Credit: " << selected_request->get_total_credit() << std::endl;
        cout << "Skill: " << selected_request->get_job().get_skill().get_skill_name() << std::endl;

        cout << "What would you like to do?" << std::endl;
        cout << "0. Back" << std::endl;
        cout << "1. Accept" << std::endl;
        cout << "2. Reject" << std::endl;

        switch (menuSystem.prompt_choice(0, 2))
        {
        case 0:
            break;

        case 1:
            break;

        case 2:
            selected_request->set_status(Request::Status::REJECTED);
            break;
        
        default:
            break;
        }
}