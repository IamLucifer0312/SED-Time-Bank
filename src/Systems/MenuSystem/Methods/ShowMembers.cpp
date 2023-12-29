#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::show_members()
{
    for (auto& member : userSystem.get_members())
    {
        member.show_member_info();
    }
    
}

void MenuSystem::show_members_for_admin()
{
    for (auto& member : userSystem.get_members())
    {
        member.show_member_info_for_admin();
    }
    
}