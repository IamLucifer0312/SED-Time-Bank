#include "../../../MenuSystem.hpp"

void MenuSystem::update_available_job()
{
    std::string skill_name;
    
    std::cout << "Add or remove your avalable job? \n"
              << "0. Back\n"
              << "1. Add. \n"
              << "2. Remove. \n";

    std::string start_time;
    std::string end_time;
    int arraySize = userSystem.get_current_member().get_available_times().size();
    int answer = 0;
    vector<AvailableJob> availableJobs = userSystem.get_current_member().get_available_jobs();
    size_t sizeValue = 0;
    Skill skill = Skill();
    Period available_time = Period();

    switch (prompt_choice(1, 2))
    {
        case 1:

            std::cout << "\nEnter your skill name: ";
            std::getline(std::cin, skill_name);

            if (!userSystem.get_current_member().have_skill(skill_name))
            {
                std::cout << "This skill doesn't match your current skills.\n";
                std::cout << "Please Enter to continue\n";
                std::cin.ignore();
                return;
            }

            for (size_t i = 0; i < arraySize; i++)
            {
                std::cout << i + 1 << std::endl;
                std::cout << userSystem.get_current_member().get_available_times()[i].get_start_time_string() << std::endl;
                std::cout << userSystem.get_current_member().get_available_times()[i].get_end_time_string() << std::endl;
                std::cout << std::endl;
            }

            answer = prompt_choice(1, arraySize);
            sizeValue = static_cast<size_t>(answer);
            skill = userSystem.get_current_member().get_skill_by_name(skill_name);
            available_time = userSystem.get_current_member().get_available_times()[sizeValue -1];
            userSystem.get_current_member().add_available_job(available_time, skill);
            std::cout << "Successfully added avalable job.\n";
            userSystem.update_current_member();
            break;
        
        case 2:
            std::cout << std::endl;
            arraySize = userSystem.get_current_member().get_available_jobs().size();
            for (size_t i = 0; i < arraySize; i++)
            {
                std::cout << i + 1 << std::endl;
                availableJobs[i].showInfo();
                std::cout << std::endl;
            }
            std::cout << "Please choose your available job to remove: \n ";
            answer = prompt_choice(1, arraySize);
            sizeValue = static_cast<size_t>(answer);
            userSystem.get_current_member().remove_available_job(availableJobs[sizeValue - 1]);
            std::cout << "Successfully removed avalable job.\n";
            userSystem.update_current_member();
            break;
    }
    std::cout << "0. Back" << std::endl;
    switch (prompt_choice(0, 0))
    {
    case 0:
        break;
    default:
        break;
    }
}