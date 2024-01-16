#include "../../MenuSystem.hpp"


void MenuSystem::add_credit() {
    float credit;
    std::cout << "Enter the amount of credit: ";
    std::cin >> credit;
    if (credit < 0) {
        std::cout << "Credit must be positive!\n";
        std::cout << "0. Back\n";
        switch(prompt_choice(0, 0)) {
            case 0:
                break;
        }
        return;
    }

    userSystem.current_member.add_credit(credit);
    userSystem.update_current_member();
    std::cout << "Successfully added credit.\n";
    std::cout << "Your current credit is " << userSystem.get_current_member().get_credit() << std::endl;
    std::cout << "0. Back\n";
    switch(prompt_choice(0, 0)) {
        case 0:
            break;
    }
}