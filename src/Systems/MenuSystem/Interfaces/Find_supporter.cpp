#include "../MenuSystem.hpp"

void MenuSystem::find_supporter_interface(std::string role){
    std::cout << "Do you want to search job for city or available time ?\n"
                            << "1. city\n"
                            << "2. available time\n"
                            << "0. no\n";

    switch (prompt_choice(0,2))
    {
        case 0:
            break;
        case 1:
            find_supporter_city();
            break;
        case 2:
            break;
    }
}

