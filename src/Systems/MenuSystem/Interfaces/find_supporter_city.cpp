#include "../MenuSystem.hpp"


void MenuSystem::find_supporter_city()
{
    std::cout << "which city do you want to search \n"
              << "1. Ha noi\n"
              << "2. Sai gon\n";

    switch (prompt_choice(1, 2)){
        case 1:
            clear_screen();
            show_members_for_city("Ha noi");
            std::cout << "What do you want to do ?\n"
                            << "1. Book\n"
                            << "0. no\n";
            switch(prompt_choice(0,1)){
                case 1:
                    book_job();
                    break;
                case 0:
                    break;
            }
            break; 
        case 2:
            clear_screen();
            show_members_for_city("Sai gon");
            std::cout << "What do you want to do ?\n"
                            << "1. Book\n"
                            << "0. no\n";
            switch(prompt_choice(0,1)){
                case 1:
                    book_job();
                    break;
                case 0:
                    break;
            }
            break;
    }
}