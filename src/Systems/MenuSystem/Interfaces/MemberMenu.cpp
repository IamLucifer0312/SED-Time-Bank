#include "../MenuSystem.hpp"
#include "../Methods/ShowMembers.cpp"
#include "../../UserSystem/UserSystem.hpp"
// member menu
    void MenuSystem::member_menu()
    {

        Users::Member *current_member;    

        while (loggedIn)
        {
            std::cout << "\nMember actions:\n"
                        << "==============================\n"
                        << "0. Logout.\n"
                        << "1. View my information.\n"
                        << "2. Add credit.\n"
                        << "3. Block member.\n"
                        << "4. View request. \n"
                        << "5. Find supporter. \n"
                        << "6. View all members. \n";

            switch (prompt_choice(0, 6))
            {
            case 1:
                std::cout << "\nUsername: " << current_member->get_username() << "\n"
                          << "Full name: " << current_member->get_full_name() << "\n"
                          << "Last name: " << current_member->get_phone_number() << "\n"
                          << "Phone number: " << current_member->get_home_address() << "\n"
                          << "email: " << current_member->get_email() << "\n"
                          << "city: " << current_member->get_city() << "\n"
                          << "credit: " << current_member->get_credit() << "\n";
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                clear_screen();
                show_members();
                break;
            case 0:
                loggedIn = false;
                break;
            }
        }
    }