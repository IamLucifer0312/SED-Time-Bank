#include "../MenuSystem.hpp"


void MenuSystem::block_member(std::string member_username)
{
    for (auto &mem : userSystem.database.get_all_members())
    {
        if (mem.get_username() == member_username)
        {
            std::cout << "This username is correct. " << std::endl;
            // std::cout <<"Update password successfully !";
            // userSystem.database.update_member(mem);
            // userSystem.save_database();
            return;
        }
    }
    std::cout << "There are no member have this username !!";
    return;
}