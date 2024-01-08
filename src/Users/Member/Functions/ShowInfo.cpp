#include "../member.hpp"

void Users::Member::show_member_info(std::string role) {
    if (role == "member") {    
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        
        std::cout << "Skills: " << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "Available times: " << std::endl;
        for (Period &available_time : this->available_times)
        {   
            std::cout << "Period 1" << std::endl;
            std::cout << available_time.get_start_time_string() << std::endl;
            std::cout << available_time.get_end_time_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "Available Jobs: " << std::endl;
        for (AvailableJob &available_job : this->available_jobs)
        {
            std::cout << available_job.get_supporter_name() << std::endl;
            std::cout << available_job.get_skill()->get_string() << std::endl;
            std::cout << available_job.get_available_time()->get_start_time_string() << std::endl;
            std::cout << available_job.get_available_time()->get_end_time_string() << std::endl;
        }
        std::cout << std::endl;
    }
    else if (role == "admin" || role == "self")
    {
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Password :" << this->password << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        std::cout << "Credit: " << this->credit << std::endl;
        std::cout << "Skills: " << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
        }
        std::cout << "Available times: " << std::endl;
        for (Period &available_time : this->available_times)
        {
            std::cout << available_time.get_start_time_string() << std::endl;
            std::cout << available_time.get_end_time_string() << std::endl;
        }
        std::cout << std::endl;
        for (std::string &block_member : this->block_list)
        {
            std::cout << block_member << std::endl;
        }

        std::cout << "Available Jobs: " << std::endl;
        for (AvailableJob &available_job : this->available_jobs)
        {
            std::cout << available_job.get_supporter_name() << std::endl;
            std::cout << available_job.get_skill()->get_string() << std::endl;
            std::cout << available_job.get_available_time()->get_start_time_string() << std::endl;
            std::cout << available_job.get_available_time()->get_end_time_string() << std::endl;
        }
        std::cout << std::endl;
    }
    else if (role == "guest") {    
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        
        std::cout << "Skills: " << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "Available times: " << std::endl;
        for (Period &available_time : this->available_times)
        {   
            std::cout << "Period 1" << std::endl;
            std::cout << available_time.get_start_time_string() << std::endl;
            std::cout << available_time.get_end_time_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "Available Jobs: " << std::endl;
        for (AvailableJob &available_job : this->available_jobs)
        {
            std::cout << available_job.get_supporter_name() << std::endl;
            std::cout << available_job.get_skill()->get_string() << std::endl;
            std::cout << available_job.get_available_time()->get_start_time_string() << std::endl;
            std::cout << available_job.get_available_time()->get_end_time_string() << std::endl;
        }
        std::cout << std::endl;
    }

    // std::cout << "Credit: " << this->credit << std::endl;
}