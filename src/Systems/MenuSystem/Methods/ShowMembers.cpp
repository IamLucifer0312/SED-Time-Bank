#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::show_members(std::string role)
{
    for (auto& member : userSystem.get_members())
    {
        member.show_member_info(role);
    }
    
}