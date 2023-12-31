#include "../MenuSystem.hpp"


void MenuSystem::unblock_member(std::string member_username)
{
    for (auto &mem : userSystem.database.get_all_members())
    {
        if (mem.get_username() == member_username)
        {
            std::cout << "Do you want to unblock this member ? \n"
                      << "1. Yes\n"
                      << "2. No\n";
            switch (prompt_choice(1, 2))
            {
                case 1:
                    userSystem.get_current_member().remove_block_list(member_username);
                    userSystem.database.update_member(userSystem.get_current_member());
                    userSystem.save_database();
                    std::cout << "Member " << mem.get_username() << " has been unblocked !!\n";
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