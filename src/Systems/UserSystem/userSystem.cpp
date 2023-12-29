#include "UserSystem.hpp"
#include "Methods/LogInRegister.cpp"
#include "Methods/UpdateCurrentMember.cpp"

// default constructor
UserSystem::UserSystem()
{
    this->database = Database("../src/member.json");
}



// Load and save data
void UserSystem::load_database()
{
    database.loadData();
}

void UserSystem::save_database()
{
    database.saveData();
}

 std::vector<Users::Member> UserSystem::get_members(){
     return database.get_all_members();
 };

Users::Member& UserSystem::get_current_member(){
    return current_member;
};

void UserSystem::set_current_member(Users::Member &member){
    current_member = member;
};





