#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::update_member_info(std::string information)
{
    if (information == "Full name")
    {
        std::string new_info;
        std::cout << "Enter new Full name: " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_full_name(new_info);
    }
    else if (information == "Phone number")
    {
        std::string new_info;
        std::cout << "Enter new Phone number: " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_phone_number(new_info);
    }
    else if (information == "Home address")
    {
        std::string new_info;
        std::cout << "Enter new Home address: " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_home_address(new_info);
    }
    else if (information == "email")
    {
        std::string new_info;
        std::cout << "Enter new email: " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_email(new_info);
    }
    else if (information == "city")
    {
        std::string new_info;
        std::cout << "Enter new city: " << information << ": ";
        std::getline(std::cin, new_info);
        userSystem.get_current_member().set_city(new_info);
    }
    else if (information == "Skill")
    {
        std::string skill_name;
        float consumed_per_hour, minimum_rating;
        std::cout << "Enter skill name: ";
        std::getline(std::cin, skill_name);
        std::cout << "Enter consumed per hour: ";
        std::cin >> consumed_per_hour;
        std::cout << "Enter minimum rating: ";
        std::cin >> minimum_rating;
        userSystem.get_current_member().add_skill(skill_name, consumed_per_hour, minimum_rating);
    }
    else if (information == "Block list") {
        std::cout << "Please go to the Block Member page to update your block list" << std::endl;
    }
    else
    {
        std::cout << "Invalid input.\n";    
    }
    userSystem.update_current_member();
}
