#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::show_members(string role)
{   
    // check if there are no members
    if (userSystem.get_members().size() == 0)
    {
        std::cout << "There are no members in the system !!\n";
        std::cout << "0. Back\n";
        prompt_choice(0, 0);
    }

    for (auto& member : userSystem.get_members())
    {
        if (member.get_username() == userSystem.get_current_member().get_username()) {
            continue;
        }
        if (is_blocked(member)) {
            continue;
        }
        if (role != "member") {
            member.show_member_info(role);
        } else {
            member.show_member_info_for_host(userSystem.get_current_member());
        }  
    }
    
}


void MenuSystem::show_members_for_city(std::string city)
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
        member.show_member_info_for_host(userSystem.get_current_member());
    }   
}

void MenuSystem::show_members_for_time(std::string startTime, std::string endTime)
{
    Period input_period = Period(startTime, endTime);
    for (auto& member : userSystem.get_members())
    {
        if (member.get_username() == userSystem.get_current_member().get_username()) {
            continue;
        }

        
        if (!member.is_overlap(input_period.get_start_time(), input_period.get_end_time()))
        {
            continue;
        }
        
      
        if (is_blocked(member)) {
            continue;
        }
        member.show_member_info_for_host(userSystem.get_current_member());
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

