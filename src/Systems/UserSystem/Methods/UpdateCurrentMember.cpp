#include "../UserSystem.hpp"

void UserSystem::update_current_member(){
    for (auto& member : database.get_all_members())
    {
        if (member.get_username() == current_member.get_username())
        {
            member = current_member;
        }
    }
    database.update_member(current_member);
    database.saveData();
}
