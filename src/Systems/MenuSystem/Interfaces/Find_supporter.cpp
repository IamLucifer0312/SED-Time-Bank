#include "../MenuSystem.hpp"

void MenuSystem::find_supporter_interface(std::string role)
{
    std::cout << "Do you want to search job for city or available time ?\n"
              << "1. city\n"
              << "2. available time\n"
              << "3. all\n"
              << "0. no\n";

    switch (prompt_choice(0, 3))
    {
    case 0:
        clear_screen();
        break;
    case 1:
        clear_screen();
        find_supporter_city(role);
        break;
    case 2:
        clear_screen();
        find_supporter_availableTime(role);
        break;
    case 3:
        clear_screen();
        find_all_supporter(role);
        break;
    }
}

// guest view supporter
void MenuSystem::guest_view_supporter()
{
    show_members("guest");
}