#include "../MenuSystem.hpp"

void MenuSystem::add_available_job()
{
    std::string skill_name;
    
    std::cout << "Do you want to add or update your avalable job? \n"
              << "1. Yes. \n"
              << "2. No. \n";

    std::string start_time;
    std::string end_time;
    int arraySize = userSystem.get_current_member().get_available_times().size();
    int answer = 0;
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
            available_time = userSystem.get_current_member().get_available_times()[sizeValue];
            userSystem.get_current_member().add_available_job(available_time, skill);
            std::cout << "Successfully added avalable job.\n";
            userSystem.update_current_member();
            break;
        
        case 2:
            break;
    }
}