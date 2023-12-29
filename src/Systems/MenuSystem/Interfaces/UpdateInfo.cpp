#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::update_member_info(std::string field)
{
    std::string new_info;
    std::cout << "Enter new " << field << ": ";
    std::getline(std::cin, new_info);
    if (field == "Full name")
    {
        userSystem.get_current_member().set_full_name(new_info);
    }
    else if (field == "Phone number")
    {
        userSystem.get_current_member().set_phone_number(new_info);
    }
    else if (field == "Home address")
    {
        userSystem.get_current_member().set_home_address(new_info);
    }
    else if (field == "email")
    {
        userSystem.get_current_member().set_email(new_info);
    }
    else if (field == "city")
    {
        userSystem.get_current_member().set_city(new_info);
    }
    else
    {
        std::cout << "Invalid field.\n";
    }
    userSystem.update_current_member();
}
