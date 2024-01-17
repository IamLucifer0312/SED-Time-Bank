#include "../MenuSystem.hpp"

void MenuSystem::find_supporter_interface()
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
        find_supporter_city();
        break;
    case 2:
        clear_screen();
        find_supporter_availableTime();
        break;
    case 3:
        clear_screen();
        find_all_supporter();
        break;
    }
}

// guest view supporter
void MenuSystem::guest_view_supporter()
{
    show_members("guest");
}