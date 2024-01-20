#include "../UserSystem.hpp"

// login
bool UserSystem::validateLogin(const std::string &username, const std::string &password, const std::string role)
{
    // Login for member
    if (role == "member")
    {
        for (Users::Member &member : database.get_all_members())
        {
            // check if the username and password are correct
            if (member.get_username() == username && member.authenticate(password))
            {
                set_current_member(member);
                return true;
            }
        }
    }
    // Login for admin
    else if (role == "admin")
    {
        for (Users::Admin &admin : database.get_all_admins())
        {
            // check if the username and password are correct
            if (admin.get_username() == username && admin.authenticate(password))
            {
                set_admin(admin);
                return true;
            }
        }
    }

    return false;
}

// register member
void UserSystem::register_member(std::string username, std::string password, std::string full_name, 
                                 std::string phone_number, std::string home_address, std::string email, std::string city)
{
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

// check the email is valid or not
bool UserSystem::is_email_valid(const string &email)
{

    // Regular expression definition
    const std::regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    // Match the string pattern
    // with regular expression
    return regex_match(email, pattern);
}
