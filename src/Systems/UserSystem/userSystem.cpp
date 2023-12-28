#include "UserSystem.hpp"
#include "Methods/LogInRegister.cpp"

// default constructor
UserSystem::UserSystem()
{}



// Load and save data
void UserSystem::load_database()
{
    Database database("../src/member.json");
    database.loadData();
}

void UserSystem::save_database()
{
    database.saveData();
}




