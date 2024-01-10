#include "../MenuSystem.hpp"

void MenuSystem::find_supporter_availableTime(std::string role){
    std::string date;
    std::string from;
    std::string to;
    std::cout << "Enter your date (Y-M-D): ";
    std::getline(std::cin, date);
    std::cout << "Enter your time (H:M:S)\n";
    std::cout << "From: ";
    std::getline(std::cin, from);
    std::cout << "To: ";
    std::getline(std::cin, to);
    std::string startTime = date + " " + from;
    std::string endTime = date + " " + to;
    std::cout << "Available supporters: \n";
    show_members_for_time(startTime, endTime, role);
    std::cout << "What do you want to do ?\n"
                            << "1. Book\n"
                            << "0. no\n";
            switch(prompt_choice(0,1)){
                case 1:
                    break;
                case 0:
                    break;
            }
}