#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "../nlohmann/json.hpp"
using json = nlohmann::json;

// include user classes
// #include "Users/User/user.cpp"
// #include "Users/Member/member.cpp"
// #include "Users/Admin/admin.hpp"
#include "Database/MemberDatabase.cpp"

enum LoginType
{
    NONE,
    GUEST,
    MEMBER,
    ADMIN
};



class System
{
private:
    bool quit;
    LoginType login_type;
    std::vector<Users::Member> members;
    Users::Admin admin;

public:
    
    bool log_in(const std::string &username, const std::string &password, Database &database)
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

    void guest_menu(Database &database)
    {
        bool back = false;

        while (!back)
        {
            std::cout << "\nGuest menu:\n"
                         "==============================\n"
                         "0. Back.\n"
                         "1. View all supporter details.\n"
                         "2. Register as member account.\n";

            switch (prompt_choice(1, 3))
            {
            case 1:
                std::cout << "supporter's details \n";
                this->guest_view_supporter();
                break;
            case 2:
                std::cout << "Registered...\n";
                this->register_member(database);
                break;
            case 0:
                back = true;
                break;
            }
        }
    }

    void guest_view_supporter() {}

    void member_menu(Database &database)
    {
        bool back = false;

        while (!back)
        {
            std::cout << "\nMember menu:\n"
                      << "==============================\n"
                      << "0. Back.\n"
                      << "1. Log in.\n";

            switch (prompt_choice(0, 1))
            {
            case 1:
            {
                std::cout << "Enter your username: ";
                std::string username;
                std::getline(std::cin, username);

                std::cout << "Enter your password: ";
                std::string password;
                std::getline(std::cin, password);

                if (log_in(username, password, database))
                {
                    bool loggedIn = true;

                    while (loggedIn)
                    {
                        std::cout << "\nMember actions:\n"
                                  << "==============================\n"
                                  << "0. Logout.\n"
                                  << "1. Perform member action 1.\n"
                                  << "2. Perform member action 2.\n";

                        switch (prompt_choice(0, 2))
                        {
                        case 1:

                            break;
                        case 2:

                            break;
                        case 0:
                            loggedIn = false;
                            break;
                        }
                    }
                }
                break;
            }

            case 0:
                back = true;
                break;
            }
        }
    }
    // dsds
    void admin_menu() {}

    bool register_member(Database &database)
    {
        std::string username, password, full_name, phone_number, home_address, email, city;

        std::cout << "Enter your new username: ";
        std::getline(std::cin, username);

        for (const auto &member : this->members)
        {
            if (member.get_username() == username)
            {
                std::cout << "Error: Username '" << username << "' already exists.\n";
                return false;
            }
        }

        std::cout << "Enter your new password: ";
        std::getline(std::cin, password);

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

    static int prompt_choice(unsigned min, unsigned max)
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

    void main_loop()
    {
        Database database("src/member.json");
        database.loadData();
        this->members = database.get_all_members();
        std::cout << "======================================\n"
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
                this->guest_menu(database);
                break;
            case 2:
                this->member_menu(database);
                break;
            case 3:
                this->admin_menu();
                break;
            case 0:
                this->quit = true;
                std::cout << "FUCK YOU !!!!!!";
            default:
                break;
            }
        }
    }
};
