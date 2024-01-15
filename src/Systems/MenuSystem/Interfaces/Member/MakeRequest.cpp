#include "../../MenuSystem.hpp"

void MenuSystem::make_request(const AvailableJob &job, Period &workTime)
{

    // get supporter
    string supporter_username = job.get_supporter_name();
    Users::Member &supporter = userSystem.get_database().find_member(supporter_username);
    

    // check if the user request the work time to be the same as the available time
    if (workTime == Period())
    {
        workTime = job.get_available_time();
    }

    Request temp = Request(userSystem.get_current_member().get_username(), job, workTime, Status::PENDING, job.get_skill().get_skill_name());

    userSystem.get_current_member().get_sent_requests().push_back(temp);
    supporter.get_received_requests().push_back(temp);

    // save to database
    userSystem.update_current_member();
    userSystem.update_member(supporter);
}