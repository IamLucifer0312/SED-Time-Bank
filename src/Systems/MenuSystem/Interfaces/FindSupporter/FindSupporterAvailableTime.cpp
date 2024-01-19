#include "../../MenuSystem.hpp"

void MenuSystem::find_supporter_availableTime()
{
    std::string date;
    std::string from;
    std::string to;
    Period tester;

    std::cout << "Enter your date (Y-M-D): ";
    getline(std::cin, date);
    // check if date is valid
    try
    {
        tester.parse_date_time(date + " 00:00:00");
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Invalid date. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter your time (H:M:S)\n";
    std::cout << "From: ";
    getline(std::cin, from);
    // check if time is valid
    try
    {
        tester.parse_date_time(date + " " + from);
    }
    catch (const std::exception &e)
    {
        std::cout << "Invalid time. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "To: ";
    getline(std::cin, to);
    // check if time is valid
    try
    {
        tester.parse_date_time(date + " " + to);
    }
    catch (const std::exception &e)
    {
        std::cout << "Invalid time. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (tester.parse_date_time(date + " " + from) >= tester.parse_date_time(date + " " + to))
    {
        std::cout << "The time input is negative. Please try again.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::string startTime = date + " " + from;
    std::string endTime = date + " " + to;

    clear_screen();
    show_members_for_time(startTime, endTime);
}