#include "../../MenuSystem.hpp"
#include "BlockMember.cpp"
#include "UnblockMember.cpp"

void MenuSystem::block_member_interface()
{
    int i = 0;
    int count = 0;
    std::cout << "Would you like to block or unblock member?\n"
              << "1. Block\n"
              << "2. Unblock\n";
    switch (prompt_choice(1, 2))
    {
    // Block
    case 1:
        clear_screen();

        // check if the list is empty
        if (userSystem.database.get_all_members().size() == 0)
        {
            std::cout << "\nThere are no members !!\n";
            std::cout << "0. Back\n";
            switch (prompt_choice(0, 0))
            {
            case 0:
                break;
            default:
                break;
            }
            break;
        }
        
        std::cout << "Here are the list of current members:\n";

        for (i = 0; i < userSystem.database.get_all_members().size(); ++i)
        {
            // check if the member username is already in the block list
            if ((check_block_list(userSystem.database.get_all_members()[i].get_username())) || (userSystem.database.get_all_members()[i].get_username() == userSystem.get_current_member().get_username()))
            {
                count++;
                continue;
            }
            else
            {
                std::cout << std::endl;
                std::cout << i + 1 - count << ". " << userSystem.database.get_all_members()[i].get_username() << std::endl;
            }
        }

        std::cout << "\nWhat do you want to do ?\n"
                  << "1. Block\n"
                  << "0. Back\n";

        switch (prompt_choice(0, 1))
        {
        case 1:
            std::cout << "\nWhich user do you want to block: ";
            std::getline(std::cin, member_username);
            block_member(member_username);
            break;
        case 0:
            break;
        default:
            break;
        }

        break;
    // Unblock
    case 2:
        clear_screen();
        
        // check if the list is empty
        if (userSystem.get_current_member().get_block_list().size() == 0)
        {
            std::cout << "\nThere are no members in your block list !!\n";
            std::cout << "0. Back\n";
            switch (prompt_choice(0, 0))
            {
            case 0:
                break;
            default:
                break;
            }
            break;
        }

        std::cout << "Here are the list of members you are currently blocking:\n";

        for (i = 0; i < userSystem.get_current_member().get_block_list().size(); ++i)
        {
            std::cout << std::endl;
            std::cout << i + 1 << ". " << userSystem.get_current_member().get_block_list()[i] << std::endl;
        }

        std::cout << "\nWhat do you want to do ?\n"
                  << "1. Unblock\n"
                  << "0. Back\n";

        switch (prompt_choice(0, 1))
        {
        case 1:
            std::cout << "\nWhich user do you want to unblock: ";
            std::getline(std::cin, member_username);
            unblock_member(member_username);
            break;
        case 0:
            break;
        default:
            break;
        }
    }
}

bool MenuSystem::check_block_list(const string member_username)
{
    for (string memName : userSystem.get_current_member().get_block_list())
    {
        if (memName == member_username)
        {
            return true;
        }
    }
    return false;
}