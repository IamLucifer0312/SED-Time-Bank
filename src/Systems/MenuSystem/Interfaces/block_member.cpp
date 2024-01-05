#include "../MenuSystem.hpp"


void MenuSystem::block_member(std::string member_username)
{
    for (auto &mem : userSystem.database.get_all_members())
    {
        if (mem.get_username() == member_username)
        {
            std::cout << "Do you want to block this member ? " << std::endl;
            return;
        }
    }
    std::cout << "There are no member have this username !!";
    return;
}