#include "UserSystem.hpp"
#include "Methods/LogInRegister.cpp"
#include "Methods/UpdateCurrentMember.cpp"

// default constructor
UserSystem::UserSystem()
{
    this->database = Database("member.json");
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

// Getters

std::vector<Users::Member> UserSystem::get_members()
{
    return database.get_all_members();
};

Users::Member &UserSystem::get_current_member()
{
    return current_member;
};

Database &UserSystem::get_database()
{
    return database;
};

void UserSystem::set_current_member(Users::Member &member)
{
    current_member = member;
};

void UserSystem::set_admin(Users::Admin &admin)
{
    admin = admin;
};
