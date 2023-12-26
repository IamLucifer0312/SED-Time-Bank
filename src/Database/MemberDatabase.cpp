#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "../../nlohmann/json.hpp"
using json = nlohmann::json;

// include user classes
#include "../Users/User/user.cpp"
#include "../Users/Member/member.cpp"
#include "../Users/Admin/admin.hpp"
class Database
{
private:
    std::vector<Users::Member> members;
    std::string member_file;

public:
    Database(const std::string &file_name) : member_file(file_name)
    {
        // Load data from file to members vector in constructor if needed
        // this->loadData();
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