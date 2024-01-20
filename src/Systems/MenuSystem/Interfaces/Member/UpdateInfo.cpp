#include "../../MenuSystem.hpp"
#include "../../../UserSystem/UserSystem.hpp"

void MenuSystem::update_member_info(std::string information)
{
    if (information == "Full name")
    {
        std::string new_info;
        std::cout << "Enter new " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_full_name(new_info);
    }
    else if (information == "Password")
    {
        std::string new_info;
        std::cout << "Enter new " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_password(new_info);
    }
    else if (information == "Phone number")
    {
        std::string new_info;
        std::cout << "Enter new " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_phone_number(new_info);
    }
    else if (information == "Home address")
    {
        std::string new_info;
        std::cout << "Enter new : " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_home_address(new_info);
    }
    else if (information == "Email")
    {
        std::string new_info;
        std::cout << "Enter new " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_email(new_info);
    }
    else if (information == "City")
    {
        std::string new_info;
        std::cout << "1. Ha noi\n";
        std::cout << "2. Sai gon\n";
        switch (prompt_choice(1, 2))
        {
        case 1:
            new_info = "Ha noi";
            break;
        case 2:
            new_info = "Sai gon";
            break;
        default:
            break;
        }

        if (new_info.empty())
        {
            std::cout << "Invalid input\n";
            std::cout << "0. Back" << std::endl;
            switch (prompt_choice(0, 0))
            {
            case 0:
                return;
            default:
                return;
            }
        }
        userSystem.get_current_member().set_city(new_info);
    }
    else if (information == "Skill")
    {
        std::string skill_name;
        float consumed_per_hour, minimum_rating;
        std::cout << "1. Add Skill \n";
        std::cout << "2. Remove Skill \n";
        switch (prompt_choice(1, 2))
        {
        case 1:
            std::cout << "Enter skill name: ";
            std::getline(std::cin, skill_name);

            if (skill_name.empty())
            {
                std::cout << "Skill name cannot be empty\n";
                std::cout << "0. Back" << std::endl;
                switch (prompt_choice(0, 0))
                {
                case 0:
                    return;
                default:
                    return;
                }
            }

            std::cout << "Enter consumed per hour: ";
            std::cin >> consumed_per_hour;

            if (!consumed_per_hour || consumed_per_hour < 0)
            {
                std::cout << "Invalid number\n";
                std::cout << "0. Back" << std::endl;
                switch (prompt_choice(0, 0))
                {
                case 0:
                    return;
                default:
                    return;
                }
            }

            std::cout << "Enter minimum host rating for this skill: ";
            std::cin >> minimum_rating;

            if (minimum_rating < 0 || minimum_rating > 5)
            {
                std::cout << "Minimum rating must be between 0 and 5\n";
                std::cout << "0. Back" << std::endl;
                switch (prompt_choice(0, 0))
                {
                case 0:
                    return;
                default:
                    return;
                }
            }

            userSystem.get_current_member().add_skill(skill_name, consumed_per_hour, minimum_rating);

            std::cout << "Skill added successfully\n";
            std::cout << "Press Enter to continue.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        case 2:
            for (auto skill : userSystem.get_current_member().get_skills())
            {
                std::cout << skill.get_string() << std::endl;
            }
            std::cout << "Enter the skill name you want to remove: ";
            std::getline(std::cin, skill_name);

            if (!userSystem.get_current_member().have_skill(skill_name))
            {
                std::cout << "You don't have this skill\n";
                std::cout << "0. Back" << std::endl;
                switch (prompt_choice(0, 0))
                {
                case 0:
                    return;
                default:
                    return;
                }
            }

            userSystem.get_current_member().remove_skill(skill_name);
            break;
        default:
            break;
        }
    }
    else if (information == "Block list")
    {
        std::cout << "Please go to the Block Member page to update your block list" << std::endl;
    }
    else
    {
        std::cout << "Invalid input. Please enter the correct information in the list\n";
        std::cout << "0. Back" << std::endl;
        switch (prompt_choice(0, 0))
        {
        case 0:
            return;
        default:
            return;
        }
    }
    userSystem.update_current_member();
    std::cout << "Update Successfully\n";
    std::cout << "Press Enter to continue.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
