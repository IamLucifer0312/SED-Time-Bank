#include "../../MenuSystem.hpp"

void MenuSystem::add_credit()
{
    float credit;
    std::cout << "Enter the amount of credit: ";
    std::cin >> credit;
    if (credit < 0)
    {
        clear_screen();
        std::cout << "Credit must be positive!\n";
        std::cout << "Press any key to continue.\n";
        std::cin.get();
    }

    userSystem.current_member.add_credit(credit);
    userSystem.update_current_member();
    clear_screen();
    std::cout << "Successfully added credit.\n";
    std::cout << "Your current credit is " << userSystem.get_current_member().get_credit() << std::endl;
    std::cout << "0. Back\n";
    std::cout << "Press any key to continue.\n";
    std::cin.get();
}