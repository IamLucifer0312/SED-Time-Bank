#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::update_member_info(std::string information)
{
    std::string new_info;
    std::cout << "Enter new information: " << information << ": ";
    std::getline(std::cin, new_info);
    if (information == "Full name")
    {
        userSystem.get_current_member().set_full_name(new_info);
    }
    else if (information == "Phone number")
    {
        userSystem.get_current_member().set_phone_number(new_info);
    }
    else if (information == "Home address")
    {
        userSystem.get_current_member().set_home_address(new_info);
    }
    else if (information == "email")
    {
        userSystem.get_current_member().set_email(new_info);
    }
    else if (information == "city")
    {
        userSystem.get_current_member().set_city(new_info);
    }
    else
    {
        std::cout << "Invalid input.\n";
    }
    userSystem.update_current_member();
}
