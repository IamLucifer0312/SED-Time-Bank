// #include "src/system.cpp"
#include <fstream>

#include "src/Systems/Systems.hpp"

int main() {   
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    

    MenuSystem menuSystem;
    menuSystem.main_loop();
    return 0;
}