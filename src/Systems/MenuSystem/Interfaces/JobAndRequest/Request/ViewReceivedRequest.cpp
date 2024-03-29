#include "../../../MenuSystem.hpp"
#include "../../../../../Classes/Request/Request.hpp"
#include "../../../../../Classes/Review/Review.hpp"
#include <string>

using std::cin;
using std::cout;

void MenuSystem::view_received_request()
{
    bool is_running = true;
    while (is_running)
    {

        vector<Request> &requests_list = this->userSystem.get_current_member().get_received_requests();

        // check if there are no requests
        if (requests_list.size() == 0)
        {
            clear_screen();
            cout << "There are no requests." << std::endl;

            std::cout << "Press Enter to continue.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            is_running = false;
        }

        else
        {
            for (int i = 0; i < requests_list.size(); ++i)
            {
                Request request = requests_list[i];
                Users::Member host = userSystem.get_database().find_member(request.get_host());
                cout << std::endl;
                cout << "Request " << i + 1 << ":" << std::endl;
                cout << "\tHost: " << request.get_host() << std::endl;
                cout << "\tWork time: " << request.get_job().get_available_time().get_start_time_string() << " - " << request.get_job().get_available_time().get_end_time_string() << std::endl;
                cout << "\tCredit: " << request.get_total_credit() << std::endl;
                cout << "\tSkill: " << request.get_job().get_skill().get_skill_name() << std::endl;
                cout << "\tHost's average rating: " << host.get_avg_host_rating() << std::endl;
                cout << "\tHost reviews: ";
                for (int i = 0; i < host.get_host_reviews().size(); i++)
                {
                    if (i == host.get_host_reviews().size() - 1)
                    {
                        std::cout << "\"" << host.get_host_reviews()[i].get_comment() << "\"";
                        break;
                    }
                    std::cout << "\"" << host.get_host_reviews()[i].get_comment() << "\", ";
                }
                cout << std::endl;
            }

            cout << std::endl;
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

            default:
                break;
            }
        }
    }
}

void MenuSystem::accept_or_reject_request(vector<Request> &requests_list)
{
    cout << std::endl;
    cout << "Enter the request (number) you want to accept or reject: " << std::endl;
    int selected_request_number = prompt_choice(1, requests_list.size());

    Request &selected_request = requests_list[selected_request_number - 1];

    clear_screen();
    cout << "Request " << selected_request_number << ":" << std::endl;
    cout << "Host: " << selected_request.get_host() << std::endl;
    cout << "Work time: " << selected_request.get_job().get_available_time().get_start_time_string() << " - " << selected_request.get_job().get_available_time().get_end_time_string() << std::endl;
    cout << "Credit: " << selected_request.get_total_credit() << std::endl;
    cout << selected_request.get_job().get_skill().get_skill_name() << std::endl;

    cout << std::endl;
    cout << "What would you like to do?" << std::endl;
    cout << "0. Back" << std::endl;
    cout << "1. Accept" << std::endl;
    cout << "2. Reject" << std::endl;

    Users::Member host = userSystem.get_database().find_member(selected_request.get_host());
    // temporary variable for checking if request is found
    bool request_found = false;

    switch (prompt_choice(0, 2))

    {
    case 0:
        break;

    case 1:
        // set the status of request to accepted
        for (int i = 0; i < host.get_sent_requests().size(); ++i)
        {
            if ((host.get_sent_requests())[i] == selected_request)
            {
                (host.get_sent_requests())[i].set_status(Status::ACCEPTED);
                request_found = true;
                break;
            }
        }

        if (!request_found)
        {
            std::cerr << "Host request not found." << std::endl;
            break;
        }

        selected_request.set_status(Status::ACCEPTED);

        // subtract credit from host
        host.subtract_credit(selected_request.get_total_credit());
        cout << "Credit subtracted from host." << std::endl;

        // add request to approved list
        host.add_approved_sent_request(selected_request);
        userSystem.current_member.add_approved_received_request(selected_request);

        // remove request from requests list
        remove_request(selected_request, requests_list);
        remove_request(selected_request, host.get_sent_requests());

        // save to database
        userSystem.update_member(host);
        userSystem.update_member(userSystem.current_member);
        cout << "Request accepted." << std::endl;
        cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;

    case 2:
        // set status of request to rejected
        for (int i = 0; i < host.get_sent_requests().size(); ++i)
        {
            if ((host.get_sent_requests())[i] == selected_request)
            {
                (host.get_sent_requests())[i].set_status(Status::REJECTED);
                request_found = true;
                remove_request(selected_request, requests_list);

                // save to database
                userSystem.update_current_member();
                userSystem.update_member(host);

                cout << "Request rejected." << std::endl;
                cout << "Press Enter to continue.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        if (!request_found)
        {
            std::cerr << "Host request not found." << std::endl;
            break;
        }
    default:
        break;
    }
}

bool MenuSystem::remove_request(Request &request, vector<Request> &requests_list)
{

    string hostUsername = request.get_host();

    for (int i = 0; i < requests_list.size(); ++i)
    {
        if (requests_list[i] == request)
        {
            requests_list.erase(requests_list.begin() + i);
            return true;
        }
    }

    std::cerr << "Request not found." << std::endl;
    return false;
}
