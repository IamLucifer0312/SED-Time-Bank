#include "../MenuSystem.hpp"

void MenuSystem::change_new_password(string member_username)
{
    std::string new_password;
    std::cout << "Enter this user's new password: ";
    std::getline(std::cin, new_password);
    for (auto &mem : userSystem.database.get_all_members())
    {
        if (mem.get_username() == member_username)
        {
            std::cout << "This username is correct. " << std::endl;
            mem.set_password(new_password);
            std::cout <<"Update password successfully !";
            userSystem.database.update_member(mem);
            userSystem.save_database();
            return;
        }
    }
    std::cout << "There are no member have this username !!";
    return;
}