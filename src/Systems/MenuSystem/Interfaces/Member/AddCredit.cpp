#include "../../MenuSystem.hpp"
#include <limits>

void MenuSystem::add_credit()
{
    float credit;
    std::cout << "Enter the amount of credit: ";
    std::cin >> credit;

    if (std::cin.fail())
    {
        clear_screen();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a valid number.\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (credit < 0)
    {
        clear_screen();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Credit must be positive!\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (credit == 0)
    {
        clear_screen();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "No credit was added\n";
        std::cout << "Press Enter to continue.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    userSystem.current_member.add_credit(credit);
    userSystem.update_current_member();
    clear_screen();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Successfully added credit.\n";
    std::cout << "Your current credit is " << userSystem.get_current_member().get_credit() << std::endl;
    std::cout << "Press Enter to continue.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}