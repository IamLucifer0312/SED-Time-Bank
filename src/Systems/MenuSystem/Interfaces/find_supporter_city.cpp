#include "../MenuSystem.hpp"


void MenuSystem::find_supporter_city()
{
    clear_screen();
    std::cout << "which city do you want to search \n"
              << "1. Ha noi\n"
              << "2. Sai gon\n";

    switch (prompt_choice(1, 2)){
        case 1:
            show_members_for_city("Ha noi", "member");
            break; 
        case 2:
            show_members_for_city("Sai gon", "member");
            break;
    }
}