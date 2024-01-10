#include "../MenuSystem.hpp"

void MenuSystem::add_available_job()
{
    std::string supporter_name;
    std::string skill_name;
    
    std::cout << "Do you want to add or update your avalable job? "
              << "1. Yes."
              << "2. No.";

    std::string start_time;
    std::string end_time;

    switch (prompt_choice(1, 2))
    {
        case 1:
            std::cout << "Enter your supporter name: ";
            std::getline(std::cin, supporter_name);

            std::cout << "\nEnter your skill name: ";
            std::getline(std::cin, skill_name);

            // for (int i = 0; i < sizeof(userSystem.get_current_member().get_available_times()); i++)
            // {
            //     std::cout << i + 1 << std::endl;
            //     std::cout << userSystem.get_current_member().get_available_times()[i].get_start_time_string() << std::endl;
            //     std::cout << userSystem.get_current_member().get_available_times()[i].get_end_time_string() << std::endl;
            //     std::cout << std::endl;
            // }

            for (Period availableTime: userSystem.get_current_member().get_available_times())
            {
                std::cout << availableTime.get_start_time_string() << std::endl;
                std::cout << availableTime.get_end_time_string() << std::endl;
                std::cout << std::endl;
            }

            std::getline(std::cin, skill_name);
            break;
        case 2:
            break;
    }
}