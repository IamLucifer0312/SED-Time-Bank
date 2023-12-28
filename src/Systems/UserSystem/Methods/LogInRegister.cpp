#include "../UserSystem.hpp"


// login
bool UserSystem::validateLogin(const std::string &username, const std::string &password)
{

    for (Users::Member &member : database.get_all_members())
    {
        if (member.get_username() == username && member.authenticate(password))
        {
            return true;
        }
    }
    return false;
}
bool UserSystem::log_in(const std::string &username, const std::string &password, Database &database)
{
    for (const auto &member : database.get_all_members())
    {
        if (member.get_username() == username && member.authenticate(password))
        {
            std::cout << "Login successful!\n";
            return true;
        }
    }
    std::cout << "Login failed. Invalid username or password.\n";
    return false;
}

// register member
void UserSystem::register_member(std::string username, std::string password, std::string full_name, std::string phone_number, std::string home_address, std::string email, std::string city) {
    database.add_member(Users::Member(username, password, full_name, phone_number, home_address, email, city, 20));
    database.saveData();
    return;
}

// validators
bool UserSystem::checkUSername(const std::string &username)
{
    for (const auto &member : database.get_all_members())
    {
        if (member.get_username() == username)
        {
            return true;
        }
    }
    return false;
}

bool UserSystem::checkPasswordEmpty(const std::string &password)
{
    if (password.empty())
    {
        return false;
    }
    return true;
}

bool UserSystem::checkPasswordSpace(const std::string &password)
{
    for (auto c : password)
    {
        if (c == ' ')
        {
            return false;
        }
    }
    return true;
}