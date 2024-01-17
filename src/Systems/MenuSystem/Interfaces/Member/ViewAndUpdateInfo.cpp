#include "../../MenuSystem.hpp"


void MenuSystem::member_view_my_info(std::string information)
{
    clear_screen();
    userSystem.get_current_member().show_member_info("self");
    std::cout << "\nDo you want to update information ? \n"
            << "1. Yes\n"
            << "2. No\n";
    switch (prompt_choice(1,2)){
        case 1: 
            std::cout << "\nList of information you can update: \n"
                    << "- Full name\n"
                    << "- Phone number\n"
                    << "- Home Address\n"
                    << "- Email\n"
                    << "- City\n"
                    << "- Skill\n";
            std::cout << "\nWhich information do you want to update: ";
            std::getline(std::cin, information);
            update_member_info(information);
            break;
        case 2:
            break;
        case 0:
            break;
    }
}
