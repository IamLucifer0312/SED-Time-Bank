#include "../MenuSystem.hpp"

void MenuSystem::clear_screen() {
    #ifdef _WIN32 
        system("cls");
    #else 
        system("clear");
    #endif

    return;
}