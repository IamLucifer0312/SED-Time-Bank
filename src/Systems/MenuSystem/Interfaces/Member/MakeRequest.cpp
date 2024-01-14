#include "../../MenuSystem.hpp"

void MenuSystem::make_request(const AvailableJob &job, Period &workTime)
{

    // get supporter
    string supporter_username = job.get_supporter_name();
    Users::Member &supporter = userSystem.get_database().find_member(supporter_username);

    // check if the user request the work time to be the same as the available time
    if (workTime == Period())
    {
        workTime.set_start_time(job.get_available_time().get_start_time_string());
        workTime.set_end_time(job.get_available_time().get_end_time_string());
    }

    Request temp = Request(userSystem.get_current_member().get_username(), job, workTime, Status::PENDING, job.get_skill().get_skill_name());
    userSystem.get_current_member().add_sent_request(temp);
    supporter.add_received_request(temp);

    // save to database
    userSystem.update_current_member();
    userSystem.update_member(supporter);
}