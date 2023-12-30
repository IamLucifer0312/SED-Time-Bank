#include "../../MenuSystem.hpp"

bool MenuSystem::check_member_username(const std::string &member_username)
{
    for (const auto &member : database.get_all_members())
    {
        if (member.get_username() == member_username)
        {
            std::cout << "This username is correct. Please enter new password: " << std::endl;
            return true;
    }

    std::cout << "There are no member have this username !!";
    return false;
} 