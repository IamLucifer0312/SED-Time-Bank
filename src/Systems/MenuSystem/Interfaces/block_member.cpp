#include "../MenuSystem.hpp"


void MenuSystem::block_member(std::string member_username)
{
    for (auto &mem : userSystem.database.get_all_members())
    {
        if (mem.get_username() == member_username)
        {
            std::cout << "Do you want to block this member ? \n"
                      << "1. Yes\n"
                      << "2. No\n";

            switch (prompt_choice(1, 2))
            {
                case 1:
                    break;
                    
                case 2:
                    break;
            }
            return;
        }
    }
    std::cout << "There are no member having this username !!";
    return;
}