#include "../UserSystem.hpp"

void UserSystem::update_new_password(){
    for (auto& password : database.get_all_members())
    {
        if (password.get_password() == newPassword.get_password())
        {
            password = newPassword;
        }
    }
    database.update_member(newPassword);
    database.saveData();
}