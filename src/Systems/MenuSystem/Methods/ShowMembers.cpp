#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::show_members()
{
    for (auto& member : userSystem.get_members())
    {
        member.show_member_info();
    }
    
}

