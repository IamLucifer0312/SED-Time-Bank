#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::show_members(std::string role)
{
    for (auto& member : userSystem.get_members())
    {
        if (member.get_username() == userSystem.get_current_member().get_username()) {
            continue;
        }
        member.show_member_info(role);
    }
    
}


void MenuSystem::show_members_for_city(std::string city, std::string role)
{
    for (auto& member : userSystem.get_members())
    {
        if (member.get_username() == userSystem.get_current_member().get_username()) {
            continue;
        }

        if (member.get_city() != city)
        {
            continue;
        }
        member.show_member_info(role);
    }   
}