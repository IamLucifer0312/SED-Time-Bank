#include "../../MenuSystem.hpp"


void MenuSystem::find_supporter_city()
{
    std::cout << "which city do you want to search \n"
              << "1. Ha noi\n"
              << "2. Sai gon\n";

    switch (prompt_choice(1, 2)){
        case 1:
            clear_screen();
            show_members_for_city("Ha noi");
            break; 
        case 2:
            clear_screen();
            show_members_for_city("Sai gon");
            break;
    }
}