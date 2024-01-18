#include "../../../MenuSystem.hpp"

using std::cin;
using std::cout;

void MenuSystem::view_approved_requests()
{
    vector<Request> &requests_list = this->userSystem.get_current_member().get_approved_sent_requests();
    std::cout << "1. Sent requests\n"
              << "2. Received requests\n"
              << "0. Back\n";
    switch (prompt_choice(0, 2))
    {
    case 1:
        requests_list = this->userSystem.get_current_member().get_approved_sent_requests();
        std::cout << "Approved requests: \n";
        std::cout << std::endl;

        for (int i = 0; i < requests_list.size(); ++i)
        {
            Request request = requests_list[i];
            cout << "Request " << i + 1 << ":" << std::endl;
            std::cout << std::endl;
            cout << "Supporter: " << request.get_supporter() << std::endl;
            cout << "Work time: " << request.get_job().get_available_time().get_start_time_string() << " - " << request.get_job().get_available_time().get_end_time_string() << std::endl;
            cout << "Credit: " << request.get_total_credit() << std::endl;
            cout << "Skill: " << request.get_job().get_skill().get_skill_name() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "\n";
        std::cout << "What do you want to do ?\n"
                  << "1. Rate supporter\n"
                  << "0. Back\n";
        switch (prompt_choice(0, 1))
        {
        case 1:
            review_supporter(requests_list);
            break;
        case 0:
            break;
        }
        break;
    case 2:
        requests_list = this->userSystem.get_current_member().get_approved_received_requests();
        std::cout << "Approved requests: \n";
        std::cout << std::endl;

        for (int i = 0; i < requests_list.size(); ++i)
        {
            Request request = requests_list[i];
            cout << "Request " << i + 1 << ":" << std::endl;
            std::cout << std::endl;
            cout << "Host: " << request.get_host() << std::endl;
            cout << "Work time: " << request.get_job().get_available_time().get_start_time_string() << " - " << request.get_job().get_available_time().get_end_time_string() << std::endl;
            cout << "Credit: " << request.get_total_credit() << std::endl;
            cout << "Skill: " << request.get_job().get_skill().get_skill_name() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "\n";
        std::cout << "What do you want to do ?\n"
                  << "1. Rate host\n"
                  << "0. Back\n";
        switch (prompt_choice(0, 1))
        {
        case 1:
            review_host(requests_list);
            break;
        case 0:
            break;
        }
        break;
    case 0:
        break;
    }
}

void MenuSystem::review_host(vector<Request> &requests_list)
{
    cout << "Enter the approved request (number) you want to review: \n";
    int selected_request_number = prompt_choice(1, requests_list.size() + 1);
    size_t sizeValue = static_cast<size_t>(selected_request_number);
    Request &selected_request = requests_list[sizeValue - 1];

    int hostRating;
    string comment;
    HostReview review;
    Users::Member host = userSystem.get_database().find_member(selected_request.get_host());

    if (host.get_username() == "")
    {
        std::cout << "0. Back\n";
        switch (prompt_choice(0, 0))
        {
        case 0:
            break;
        default:
            break;
        }
        return;
    }

    cout << "Please rate your host skill from 1 to 5: " << std::endl;
    hostRating = prompt_choice(1, 5);
    if (hostRating < 0 || hostRating > 5)
    {
        std::cout << "Invalid rating\n";
        std::cout << "0. Back\n";
        switch (prompt_choice(0, 0))
        {
        case 0:
            return;
        default:
            return;
        }
    }
    cout << "Please comment about your supporter: " << std::endl;
    getline(cin, comment);
    review = HostReview(comment, hostRating);
    host.add_host_review(review);
    host.calculate_avg_host_rating();

    // add credit to supporter
    userSystem.get_current_member().add_credit(selected_request.get_total_credit());

    // update database
    userSystem.update_member(host);

    std::cout << "Successfully reviewed host.\n";
    cout << "You have received " << selected_request.get_total_credit() << " credits for completing the work!" << std::endl;
    cout << "0. Back" << std::endl;

    switch (prompt_choice(0, 0))
    {
    case 0:
        return;

    default:
        return;
    }
}

void MenuSystem::review_supporter(vector<Request> &requests_list)
{
    cout << "Enter the approved request (number) you want to review: \n";
    int selected_request_number = prompt_choice(1, requests_list.size() + 1);
    size_t sizeValue = static_cast<size_t>(selected_request_number);
    Request &selected_request = requests_list[sizeValue - 1];

    int supporterRating;
    int skillRating;
    string comment;
    SupporterReview review;
    Users::Member supporter = userSystem.get_database().find_member(selected_request.get_supporter());
    if (supporter.get_username() == "")
    {
        std::cout << "0. Back\n";
        switch (prompt_choice(0, 0))
        {
        case 0:
            return;
        default:
            return;
        }
    }

    cout << "Please rate your supporter from 1 to 5: " << std::endl;
    supporterRating = prompt_choice(1, 5);
    if (supporterRating < 0 || supporterRating > 5)
    {
        std::cout << "Invalid rating\n";
        std::cout << "0. Back\n";
        switch (prompt_choice(0, 0))
        {
        case 0:
            return;
        default:
            return;
        }
    }
    
    cout << "Please rate your supporter's skill from 1 to 5: " << std::endl;
    skillRating = prompt_choice(1, 5);
    if (skillRating < 0 || skillRating > 5)
    {
        std::cout << "Invalid rating\n";
        std::cout << "0. Back\n";
        switch (prompt_choice(0, 0))
        {
        case 0:
            return;
        default:
            return;
        }
    }

    cout << "Please comment about your supporter: " << std::endl;
    getline(cin, comment);

    review = SupporterReview(comment, skillRating, supporterRating);
    supporter.add_supporter_review(review);
    supporter.calculate_avg_supporter_rating();
    userSystem.update_member(supporter);
    std::cout << "Successfully reviewed supporter.\n";
    std::cout << "Press any key to continue.\n";
    std::cin.get();
}