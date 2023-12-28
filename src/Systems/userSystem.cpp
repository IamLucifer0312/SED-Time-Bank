#include "UserSystem.hpp"

// login member
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
bool UserSystem::register_member(Database &database)
{
    std::string username, password, full_name, phone_number, home_address, email, city;

    std::cout << "Enter your new username: ";
    std::getline(std::cin, username);
    std::cout << "Enter your new password: ";
    std::getline(std::cin, password);

    for (const auto &member : this->members)
    {
        if (member.get_username() == username)
        {
            std::cout << "Error: Username '" << username << "' already exists.\n";
            return false;
        }
    }

    if (password.empty())
    {
        std::cout << "Error: Your password cannot be empty.\n";
        return false;
    }

    for (auto c : password)
    {
        if (c == ' ')
        {
            std::cout << "Error: Your password cannot contain space character.\n";
            return false;
        }
    }

    std::cout << "Enter your full name: ";
    std::getline(std::cin, full_name);

    std::cout << "Enter your phone number: ";
    std::getline(std::cin, phone_number);

    std::cout << "Enter your home address: ";
    std::getline(std::cin, home_address);

    std::cout << "Enter your email: ";
    std::getline(std::cin, email);

    std::cout << "Enter your city: ";
    std::getline(std::cin, city);

    this->members.emplace_back(username, password, full_name, phone_number, home_address, email, city);

    database.add_member(Users::Member(username, password, full_name, phone_number, home_address, email, city));
    // database.save_data();
    database.saveData();
    return true;
}

// handle choices
int UserSystem::prompt_choice(unsigned min, unsigned max)
{
    int choice = -1;
    std::string buffer;

    std::cout << "Enter your choice: ";
    std::getline(std::cin, buffer);
    try
    {
        choice = std::stoi(buffer);
    }
    catch (std::invalid_argument &e)
    {
        choice = -1;
    }
    catch (std::out_of_range &e)
    {
        choice = -1;
    }

    while (choice == -1)
    {
        std::cout << "Enter your choice: ";
        std::getline(std::cin, buffer);

        if (choice < min || max < choice)
            choice = -1;
        try
        {
            choice = std::stoi(buffer);
        }
        catch (std::invalid_argument &e)
        {
            choice = -1;
        }
        catch (std::out_of_range &e)
        {
            choice = -1;
        }
    }

    return choice;
}

// i dont know what this function do
void UserSystem::guest_view_supporter() {}

// main loop
void UserSystem::main_loop()
{
    Database database("../src/member.json");
    database.loadData();
    this->members = database.get_all_members();

    MenuSystem menu;

    std::cout << "\n\n\n\n\n\n"
              << "======================================\n"
              << "EEET2482/COSC2082 ASSIGNMENT\n"
              << "TIME BANK APPLICATION\n"
              << "\n"
              << "Instructor: Mr. Tran Duc Linh\n"
              << "Group: Group 2\n"
              << "s4021255, Cu Duc Quang\n"
              << "s3978616, Nguyen Trong Tien\n"
              << "s4000948, Pham Hung Anh\n"
              << "s3979081, Tran Phan Trong Phuc"
              << "\n======================================\n\n";

    while (!this->quit)
    {
        std::cout << "\nMAIN MENU\n"
                  << "=========================\n"
                  << "--> 0. Exit\n"
                  << "--> 1. Login as Guest\n"
                  << "--> 2. Login as Member\n"
                  << "--> 3. Login as Admin\n";

        switch (prompt_choice(1, 5))
        {
        case 1:
            menu.guest_menu(database);
            break;
        case 2:
            menu.member_menu(database, *this);
            break;
        case 3:
            menu.admin_menu();
            break;
        case 0:
            this->quit = true;
            std::cout << "FUCK YOU !!!!!!" << std::endl;
        default:
            break;
        }
    }
}