#include "../MenuSystem.hpp"


void MenuSystem::change_new_password(std::string new_password)
{
    std::cout << "Enter this user's new password: ";
    std::getline(std::cin, new_password);

}