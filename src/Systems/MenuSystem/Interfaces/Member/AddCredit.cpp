#include "../../MenuSystem.hpp"


void MenuSystem::add_credit() {
    float credit;
    std::cout << "Enter the amount of credit: ";
    std::cin >> credit;
    userSystem.current_member.add_credit(credit);
    userSystem.update_current_member();
}