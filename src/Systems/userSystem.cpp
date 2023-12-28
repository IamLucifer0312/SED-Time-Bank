#include "UserSystem.hpp"
#include "MenuSystem.hpp"

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

// login
bool UserSystem::validateLogin(const std::string &username, const std::string &password)
{
    for (const auto &member : database.get_all_members())
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

// bool UserSystem::register_member(Database &database)
// {
//     std::string username, password, full_name, phone_number, home_address, email, city;

//     std::cout << "Enter your new username: ";
//     std::getline(std::cin, username);
//     std::cout << "Enter your new password: ";
//     std::getline(std::cin, password);

//     for (const auto &member : this->members)
//     {
//         if (member.get_username() == username)
//         {
//             std::cout << "Error: Username '" << username << "' already exists.\n";
//             return false;
//         }
//     }

//     if (password.empty())
//     {
//         std::cout << "Error: Your password cannot be empty.\n";
//         return false;
//     }

//     for (auto c : password)
//     {
//         if (c == ' ')
//         {
//             std::cout << "Error: Your password cannot contain space character.\n";
//             return false;
//         }
//     }

//     std::cout << "Enter your full name: ";
//     std::getline(std::cin, full_name);

//     std::cout << "Enter your phone number: ";
//     std::getline(std::cin, phone_number);

//     std::cout << "Enter your home address: ";
//     std::getline(std::cin, home_address);

//     std::cout << "Enter your email: ";
//     std::getline(std::cin, email);

//     std::cout << "Enter your city: ";
//     std::getline(std::cin, city);

//     this->members.emplace_back(username, password, full_name, phone_number, home_address, email, city, 20);

//     database.add_member(Users::Member(username, password, full_name, phone_number, home_address, email, city, 20));
//     // database.save_data();
//     database.saveData();
//     return true;
// }





