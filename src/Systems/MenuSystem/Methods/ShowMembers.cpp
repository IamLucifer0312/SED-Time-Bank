#include "../MenuSystem.hpp"
#include "../../UserSystem/UserSystem.hpp"

void MenuSystem::show_members(string role)
{
    // check if there are no members
    if (userSystem.get_members().size() == 0)
    {
        std::cout << "There are no members in the system !!\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (auto &member : userSystem.get_members())
    {
        if (member.get_username() == userSystem.get_current_member().get_username())
        {
            continue;
        }
        if (is_blocked(member))
        {
            continue;
        }
        if (role != "member")
        {
            member.show_member_info(role);
        }
        else
        {
            member.show_member_info_for_host(userSystem.get_current_member());
        }
    }
}

void MenuSystem::show_members_for_city(std::string city)
{
    // Extract all members from the same city
    vector<Users::Member> temp;
    for (auto &member : userSystem.get_members())
    {
        if (member.get_username() == userSystem.get_current_member().get_username())
        {
            continue;
        }

        if (member.get_city() != city)
        {
            continue;
        }
        if (is_blocked(member))
        {
            continue;
        }
        temp.push_back(member);
    }

    // check if there are no members
    if (temp.size() == 0)
    {
        std::cout << "There are no members from this city !!\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        for (auto &member : temp)
        {
            member.show_member_info_for_host(userSystem.get_current_member());
        }

        std::cout << "What do you want to do ?\n"
                  << "1. Book\n"
                  << "0. no\n";
        switch (prompt_choice(0, 1))
        {
        case 1:
            book_job(temp);
            break;
        case 0:
            break;
        }
    }
}

void MenuSystem::show_members_for_time(std::string startTime, std::string endTime)
{
    Period input_period = Period(startTime, endTime);
    vector<Users::Member> temp;
    for (auto &member : userSystem.get_members())
    {
        if (member.get_username() == userSystem.get_current_member().get_username())
        {
            continue;
        }

        if (!member.is_overlap(input_period.get_start_time(), input_period.get_end_time()))
        {
            continue;
        }

        if (is_blocked(member))
        {
            continue;
        }
        temp.push_back(member);
    }

    if (temp.size() == 0)
    {
        std::cout << "There are no members available at this time !!\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        std::cout << "Available supporters: \n";
        for (auto &member : temp)
        {
            member.show_member_info_for_host(userSystem.get_current_member());
        }

        std::cout << "What do you want to do ?\n"
                  << "1. Book\n"
                  << "0. no\n";
        switch (prompt_choice(0, 1))
        {
        case 1:
            book_job(temp);
            break;
        case 0:
            break;
        }
    }
}

bool MenuSystem::is_blocked(Users::Member member)
{
    for (auto &blocked_member : member.get_block_list())
    {
        if (blocked_member == userSystem.get_current_member().get_username())
        {
            return true;
        }
    }
    return false;
}
