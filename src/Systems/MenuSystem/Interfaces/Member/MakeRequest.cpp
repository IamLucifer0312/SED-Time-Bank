#include "../../MenuSystem.hpp"

void MenuSystem::make_request(AvailableJob& job) {
    // Request(string &hostUsername, AvailableJob &job, Period &workTime);
    string supporter_username = job.get_supporter_name();
    Users::Member supporter = userSystem.get_database().find_member(supporter_username);

    Request temp = Request(userSystem.get_current_member().get_username(), job, job.get_available_time());
    userSystem.get_current_member().add_sent_request(temp);
    supporter.add_received_request(temp);
}