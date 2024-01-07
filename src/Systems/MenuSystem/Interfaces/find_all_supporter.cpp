#include "../MenuSystem.hpp"


void MenuSystem::find_all_supporter(std::string role)
{
    show_members(role);

    std::cout << "What do you want to do ?\n"
                    << "1. Book\n"
                    << "0. no\n";
    switch(prompt_choice(0,1)){
        case 1:
            break;
        case 0:
            break;
    }
    
}