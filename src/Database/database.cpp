#include "Database.hpp"

// constructor
Database::Database() {}
Database::Database(const string &member_file_name) : member_file(member_file_name)
{
    // Load data from file to members vector in constructor if needed
    // this->loadData();
}

// Serialize member vector to json
json Database::serializeMembers(const vector<Users::Member> &members)
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

// Deserialize json to member vector
vector<Users::Admin> Database::deserializeAdmins(const json &jsonArray)
{
    vector<Users::Admin> deserializedAdmins;
    for (const auto &adminJson : jsonArray)
    {
        Users::Admin admin;
        admin.deserialize(adminJson);
        deserializedAdmins.push_back(admin);
    }
    return deserializedAdmins;
}

vector<Users::Member> Database::deserializeMembers(const json &jsonArray)
{
    vector<Users::Member> deserializedMembers;
    for (const auto &memberJson : jsonArray)
    {
        Users::Member member;
        member.deserialize(memberJson);
        deserializedMembers.push_back(member);
    }
    return deserializedMembers;
}

// Add a member to the database object
void Database::add_member(const Users::Member &member)
{
    members.push_back(member);
}

// Retrieve all members from the database object
vector<Users::Member> Database::get_all_members() const
{
    return members;
}

vector<Users::Admin> Database::get_all_admins() const
{
    return admins;
}

// Load members from data file
vector<Users::Admin> Database::loadAdminsFromFile(const string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
    }

    json jsonArray;
    file >> jsonArray;
    file.close();
    return deserializeAdmins(jsonArray);
}

vector<Users::Member> Database::loadMembersFromFile(const string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
    }

    json jsonArray;
    file >> jsonArray;
    file.close();
    return deserializeMembers(jsonArray);
}

// Saving members to data file
void Database::saveMembersToFile(const vector<Users::Member> &members, const string &filename)
{
    json jsonArray = serializeMembers(members);
    std::ofstream file(filename);
    file << std::setw(4) << jsonArray << std::endl;
    file.close();
}

// Save data to file
void Database::saveData()
{
    saveMembersToFile(members, member_file);
};

// Load data from file
void Database::loadData()
{
    this->members = loadMembersFromFile(member_file);
    this->admins = loadAdminsFromFile(admin_file);
};

void Database::update_member(const Users::Member &member)
{
    for (auto &new_member_infor : members)
    {
        if (new_member_infor.get_username() == member.get_username())
        {
            new_member_infor = member;
            return;
        }
    }
    std::cerr << "Error: Member not found." << std::endl;
    return;
}