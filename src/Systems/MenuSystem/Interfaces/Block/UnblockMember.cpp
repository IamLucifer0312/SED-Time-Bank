#include "../../MenuSystem.hpp"

void MenuSystem::unblock_member(std::string member_username)
{
    for (auto &mem : userSystem.database.get_all_members())
    {
        if (mem.get_username() == member_username)
        {
            std::cout << "Do you want to unblock " << member_username << "? \n"
                      << "1. Yes\n"
                      << "2. No\n";
            switch (prompt_choice(1, 2))
            {
            case 1:
                userSystem.get_current_member().remove_block_list(member_username);
                userSystem.database.update_member(userSystem.get_current_member());
                userSystem.save_database();

                clear_screen();
                std::cout << mem.get_username() << " has been unblocked !!\n";
                std::cout << "Press any key to continue.\n";
                std::cin.get();

                break;

            case 2:
                break;
            }
            return;
        }
    }
    std::cout << "There are no member having this username !!\n";
    std::cout << "Press any key to continue.\n";
    std::cin.get();
    return;
}