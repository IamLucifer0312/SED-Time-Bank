#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "../nlohmann/json.hpp"
using json = nlohmann::json;

// include user classes
#include "Users/User/user.hpp"
#include "Users/Member/member.hpp"
#include "Users/Admin/admin.hpp"

enum LoginType
{
    NONE,
    GUEST,
    MEMBER,
    ADMIN
};

class Database
{
private:
    std::vector<Users::Member> members;
    std::string member_file;

public:
    Database(const std::string &file_name) : member_file(file_name)
    {
        // Load data from file to members vector in constructor if needed
        // this->load_data();
    }

    json serializeMembers(const std::vector<Users::Member> &members)
    {
        json jsonArray;
        for (const auto &member : members)
        {
            json memberJson;
            member.serialize(memberJson);
            jsonArray.push_back(memberJson);
        }
        return jsonArray;
    }

    std::vector<Users::Member> deserializeMembers(const json &jsonArray)
    {
        std::vector<Users::Member> deserializedMembers;
        for (const auto &memberJson : jsonArray)
        {
            Users::Member member;
            member.deserialize(memberJson);
            deserializedMembers.push_back(member);
        }
        return deserializedMembers;
    }

    // Function to save data to file
    // void save_data()
    // {
    //     std::ofstream file(member_file, std::ios::binary);

    //     if (!file.is_open())
    //     {
    //         std::cout << "Unable to open file.\n";
    //         return;
    //     }

    //     for (const auto &member : members)
    //     {
    //         std::map<std::string, std::string> member_data = member.to_map_member();
    //         for (const auto &data : member_data)
    //         {
    //             file << data.first << ":" << data.second << "\n";
    //         }
    //         file << "\n"; // Separate each member's data
    //     }

    //     file.close();
    // }

    // Function to load data from file
    //     void load_data()
    //     {
    //         std::ifstream file(member_file);

    //         if (!file.is_open())
    //         {
    //             std::cout << "Unable to open file.\n";
    //             return;
    //         }

    //         members.clear(); // Clear existing data before loading new data

    //         std::map<std::string, std::string> member_data;
    //         std::string line;
    //         while (std::getline(file, line))
    //         {
    //             if (line.empty())
    //             {
    //                 // Process member data
    //                 Users::Member member;
    //                 member.from_map(member_data);
    //                 members.push_back(member);
    //                 member_data.clear();
    //             }
    //             else
    //             {
    //                 // Split line into key-value pair
    //                 size_t pos = line.find(':');
    //                 if (pos != std::string::npos)
    //                 {
    //                     std::string key = line.substr(0, pos);
    //                     std::string value = line.substr(pos + 1);
    //                     member_data[key] = value;
    //                 }
    //             }
    //         }

    //         file.close();
    //     }

    // Function to add a member to the database
    void add_member(const Users::Member &member)
    {
        members.push_back(member);
    }

    // Function to retrieve all members from the database
    std::vector<Users::Member> get_all_members() const
    {
        return members;
    }

    std::vector<Users::Member> loadMembersFromFile(const std::string &filename)
    {
        std::ifstream file(filename);
        // if (!file.is_open()) {
        //     std::cerr << "Error: Unable to open file: " << filename << std::endl;
        //     return nullptr;
        // }

        json jsonArray;
        file >> jsonArray;
        file.close();
        return deserializeMembers(jsonArray);
    }

    // Saving vector of Users::Member to a file

    void saveMembersToFile(const std::vector<Users::Member> &members, const std::string &filename)
    {
        json jsonArray = serializeMembers(members);
        std::ofstream file(filename);
        file << std::setw(4) << jsonArray << std::endl;
        file.close();
    }

    void saveData()
    {
        saveMembersToFile(members, member_file);
    };

    void loadData()
    {
        this->members = loadMembersFromFile(member_file);
    };
};

class System
{
private:
    bool quit;
    LoginType login_type;
    std::vector<Users::Member> members;
    Users::Admin admin;

public:
    // bool detected_database();
    // void load_database(Database &database)
    // {
    //     database.loadMembersFromFile(member_file);
    // }

    // void save_database(Database &database)
    // {
    //     database.save_data();
    // }

    // void reset_database();

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
        Database database("member.json");
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
