#include "../../MenuSystem.hpp"


void MenuSystem::add_credit() {
    float credit;
    std::cout << "Enter the amount of credit: ";
    std::cin >> credit;
    if (credit < 0) {
        std::cout << "Credit must be positive!\n";
        return;
    }

    userSystem.current_member.add_credit(credit);
    userSystem.update_current_member();
}