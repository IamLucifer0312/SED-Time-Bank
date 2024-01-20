#include "../Member.hpp"

void Users::Member::show_member_info(std::string role)
{
    if (role == "admin" || role == "self")
    {
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Password :" << this->password << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        std::cout << "Credit: " << this->credit << std::endl;
        std::cout << "Average host rating: " << this->avg_host_rating << std::endl;
        std::cout << "Average supporter rating: " << this->avg_supporter_rating << std::endl;

        std::cout << std::endl;

        std::cout << "Skills: " << std::endl;
        std::cout << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
        }
        std::cout << "Available Times: " << std::endl;
        std::cout << std::endl;
        for (Period &available_time : this->available_times)
        {
            std::cout << "  Start time: " << available_time.get_start_time_string() << std::endl;
            std::cout << "  End time: " << available_time.get_end_time_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Block list: \n";
        for (std::string &block_member : this->block_list)
        {
            std::cout << "  Username: "<< block_member << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Available Jobs: " << std::endl;
        std::cout << std::endl;
        for (AvailableJob &available_job : this->available_jobs)
        {
            std::cout << "  Supporter name: " << available_job.get_supporter_name() << std::endl;
            std::cout << available_job.get_skill().get_string() << std::endl;
            std::cout << "  Start time:" << available_job.get_available_time().get_start_time_string() << std::endl;
            std::cout << "  End time:" << available_job.get_available_time().get_end_time_string() << std::endl;
            std::cout << "  -------------------------"<< std::endl;
            std::cout << std::endl;
        }
        std::cout << "----------------------------" << std::endl;
        std::cout << std::endl;
    }
    else if (role == "guest")
    {
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        std::cout << "Average host rating: " << this->avg_host_rating << std::endl;
        std::cout << "Average supporter rating: " << this->avg_supporter_rating << std::endl;

        std::cout << std::endl;

        std::cout << "Skills: " << std::endl;
        std::cout << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "Available Times: " << std::endl;
        std::cout << std::endl;
        for (Period &available_time : this->available_times)
        {   
            std::cout << "  Start time: " << available_time.get_start_time_string() << std::endl;
            std::cout << "  End time: " << available_time.get_end_time_string() << std::endl;
            std::cout << std::endl;
        }

        std::cout << std::endl;

        std::cout << "Available Jobs: " << std::endl;
        std::cout << std::endl;
        for (AvailableJob &available_job : this->available_jobs)
        {
            std::cout << "  Supporter name: " << available_job.get_supporter_name() << std::endl;
            std::cout << available_job.get_skill().get_string() << std::endl;
            std::cout << "  Start time:" << available_job.get_available_time().get_start_time_string() << std::endl;
            std::cout << "  End time:" << available_job.get_available_time().get_end_time_string() << std::endl;
            std::cout << "  -------------------------"<< std::endl;
            std::cout << std::endl;
        }
        std::cout << "----------------------------" << std::endl;
        std::cout << std::endl;
    }
}

void Users::Member::show_member_info_for_host(Users::Member &current_member)
{
    std::cout << "Username: " << this->username << std::endl;
    std::cout << "Full name: " << this->full_name << std::endl;
    std::cout << "Phone number: " << this->phone_number << std::endl;
    std::cout << "Home address: " << this->home_address << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "City: " << this->city << std::endl;
    std::cout << "Average host rating: " << this->avg_host_rating << std::endl;
    std::cout << "Average supporter rating: " << this->avg_supporter_rating << std::endl;

    std::cout << std::endl;

    std::cout << "Skills: " << std::endl;
    std::cout << std::endl;
    for (Skill &skill : this->skills)
    {
        std::cout << skill.get_string() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Available Times: " << std::endl;
    std::cout << std::endl;
    for (Period &available_time : this->available_times)
    {   
        std::cout << "  Start time: " << available_time.get_start_time_string() << std::endl;
        std::cout << "  End time: " << available_time.get_end_time_string() << std::endl;
        std::cout << std::endl;
    }

    // Unsuitable available jobs will not be shown
    std::cout << "Available Jobs: " << std::endl;
    std::cout << std::endl;
    // filter available jobs
    for (AvailableJob &available_job : this->available_jobs)
    {
        // by minimum host rating
        if (available_job.get_skill().get_mininum_rating() > current_member.get_avg_host_rating()) 
        {
            continue;
        }
        // by consumed credit
        if (available_job.get_skill().get_consumed_per_hour() > current_member.get_credit()) 
        {
            continue;
        }
        std::cout << "  Supporter name: " << available_job.get_supporter_name() << std::endl;
        std::cout << available_job.get_skill().get_string() << std::endl;
        std::cout << "  Start time:" << available_job.get_available_time().get_start_time_string() << std::endl;
        std::cout << "  End time:" << available_job.get_available_time().get_end_time_string() << std::endl;
        std::cout << "  -------------------------"<< std::endl;
        std::cout << std::endl;
    }

    std::cout << "----------------------------" << std::endl;
    std::cout << std::endl;
}