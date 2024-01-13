#include "../../MenuSystem.hpp"
#include "../../../../Request/Request.hpp"
#include "../../../../Review/Review.hpp"
#include <string>


using std::cout;
using std::cin;

void MenuSystem::view_sent_request(){
    bool is_running = true;
    while (is_running){
        vector<Request> &requests_list = this->userSystem.get_current_member().get_sent_requests();
        if (requests_list.size() == 0){
            cout << "There are no requests." << std::endl;
            is_running = false;

            cout << "0. Back" << std::endl;

            switch (prompt_choice(0,0))
            {
            case 0:
                is_running = false;
                break;
            default:
                break;
            }
        }
        else{
            for (int i = 0; i < requests_list.size(); ++i) {
                Request request = requests_list[i];
                cout << "Request " << i + 1 << ":" << std::endl;
                cout << "Supporter: " << request.get_supporter() << std::endl;
                cout << "Work time: " << request.get_job().get_available_time().get_start_time_string() << " - " << request.get_job().get_available_time().get_end_time_string() << std::endl;
                cout << "Credit: " << request.get_total_credit() << std::endl;
                cout << request.get_job().get_skill().get_string() << std::endl;
                cout << "Status: " << request.get_status_string() << std::endl;
            }

            cout << "What would you like to do?" << std::endl;
            cout << "0. Back" << std::endl;
            cout << "1. View request" << std::endl;
          
            switch (prompt_choice(0, 1))
            {
            case 0:
                is_running = false;
                break;

            case 1:
                accepted_request(requests_list);
                break;
        
            default:
                break;
            }
        }
    }
}

void MenuSystem::accepted_request(vector<Request> &requests_list){
    cout << "Enter the accepted request (number) you want to view: ";
    int selected_request_number = prompt_choice(1, requests_list.size() + 1);
    
    Request &selected_request = requests_list[selected_request_number - 1];
        cout << "Request " << selected_request_number << ":" << std::endl;
        cout << "Host: " << selected_request.get_supporter() << std::endl;
        cout << "Work time: " << selected_request.get_job().get_available_time().get_start_time_string() << " - " << selected_request.get_job().get_available_time().get_end_time_string() << std::endl;
        cout << "Credit: " << selected_request.get_total_credit() << std::endl;
        cout << selected_request.get_job().get_skill().get_string() << std::endl;

        int skillrating;
        int supporterrating;
        string comment;
        SupporterReview review;
        selected_request.get_supporter();
        Users::Member host = userSystem.get_database().find_member(selected_request.get_supporter());

        cout << "Please rate your supporter skill from 1 to 5: " << std::endl;
        cin >> skillrating;
        cout << "Please rate your supporter from 1 to 5: " << std::endl;
        cin >> supporterrating;
        cout << "Please comment about your supporter: " << std::endl;
        cin >> comment;
        review = SupporterReview(comment, skillrating, supporterrating);
        host.add_supporter_review(review);

}