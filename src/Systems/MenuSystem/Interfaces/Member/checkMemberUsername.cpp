#include "../../MenuSystem.hpp"
#include "../change_new_password.cpp"

bool MenuSystem::check_member_username(const std::string &member_username, std::string new_password)
{
    for (const auto &member : userSystem.database.get_all_members())
    {
        if (member.get_username() == member_username)
        {   
            std::cout << "This username is correct. " << std::endl;
            change_new_password(new_password);
            return true;
        }
    }
    std::cout << "There are no member have this username !!";
    return false;
}