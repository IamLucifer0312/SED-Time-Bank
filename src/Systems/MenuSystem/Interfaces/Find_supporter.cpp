#include "../MenuSystem.hpp"

void MenuSystem::find_supporter_interface(std::string role)
{
    // testing
    const AvailableJob &tempJob = (userSystem.get_database().find_member("TT").get_available_jobs())[0];
    Period tempTime = Period();
    make_request(tempJob, tempTime);
    std::cout << "Sent request successfully!" << std::endl;

    // std::cout << "Received requests: " << (userSystem.get_database().find_member("hung anh").get_received_requests()) != nullptr << std::endl;

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