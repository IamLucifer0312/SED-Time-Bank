#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::show_members(std::string role)
{
    for (auto& member : userSystem.get_members())
    {
        if (member.get_username() == userSystem.get_current_member().get_username()) {
            continue;
        }
        if (is_blocked(member)) {
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
        if (is_blocked(member)) {
            continue;
        }
        member.show_member_info(role);
    }   
}

bool MenuSystem::is_blocked(Users::Member member) {
    for (auto& blocked_member : member.get_block_list())
        {
            if (blocked_member == userSystem.get_current_member().get_username())
            {
                return true;
            }
        }
    return false;
}