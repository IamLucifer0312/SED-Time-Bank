#include "../../MenuSystem.hpp"

void MenuSystem::find_all_supporter()
{
    show_members("member");
    vector<Users::Member> tempSupporterList = userSystem.get_members();

    // remove the current user from the list
    for (int i = 0; i < tempSupporterList.size(); i++)
    {
        if (tempSupporterList[i].get_username() == userSystem.get_current_member().get_username())
        {
            tempSupporterList.erase(tempSupporterList.begin() + i);
            break;
        }
    }
    
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