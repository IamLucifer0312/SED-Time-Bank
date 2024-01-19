#include "../../MenuSystem.hpp"

void MenuSystem::find_all_supporter()
{
    show_members("member");
    vector<Users::Member> tempSupporterList = userSystem.get_members();

    std::cout << "What do you want to do ?\n"
              << "1. Book\n"
              << "0. no\n";
    switch (prompt_choice(0, 1))
    {
    case 1:
        book_job(tempSupporterList);
        break;
    case 0:
        break;
    }
}