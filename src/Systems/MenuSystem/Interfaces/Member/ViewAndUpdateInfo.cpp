#include "../../MenuSystem.hpp"


void MenuSystem::member_view_my_info(Users::Member current_member, std::string information)
{
    clear_screen();
    current_member.show_member_info("member");
    std::cout << "\nDo you want to update information ? "
            << "1. Yes\n"
            << "2. No\n";
    switch (prompt_choice(1,2)){
        case 1: 
            std::cout << "\nWhich information do you want to update: ";
            std::getline(std::cin, information);
            update_member_info(information);
            current_member = userSystem.get_current_member();
            std::cout << "Update Successfully";
            break;
        case 2:
            break;
        case 0:
            break;
    }
}