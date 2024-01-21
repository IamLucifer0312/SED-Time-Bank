#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "../../nlohmann/json.hpp"

using json = nlohmann::json;
using std::string;
using std::vector;

// include user classes
#include "../Users/Users.hpp"

// Check if the file is already included.
#ifndef DATABASE_HPP
#define DATABASE_HPP

class Database
{
private:
    vector<Users::Member> members;
    vector<Users::Admin> admins;
    string admin_file = "admin.json";
    string member_file;

public:
    // default constructor
    Database();
    // constructor
    Database(const string &member_file_name);

    // Serialize member vector to json
    json serializeMembers(const vector<Users::Member> &members);

    // Deserialize json to member vector
    vector<Users::Member> deserializeMembers(const json &jsonArray);
    vector<Users::Admin> deserializeAdmins(const json &jsonArray);

    // Add a member to the database object
    void add_member(const Users::Member &member);

    // Retrieve all members from the database object
    vector<Users::Member> get_all_members() const;
    vector<Users::Admin> get_all_admins() const;

    // Load members from data file
    vector<Users::Member> loadMembersFromFile(const string &filename);
    vector<Users::Admin> loadAdminsFromFile(const string &filename);

    // set the jobs of members to the corresponding requests
    void set_job_to_requests(vector<Users::Member>& deserializedMembers);

    // Saving members to data file
    void saveMembersToFile(const vector<Users::Member> &members, const string &filename);

    // Save data to file
    void saveData();

    // Load data from file
    void loadData();

    // Setters
    void update_member(const Users::Member &member);

    // Finder
    Users::Member& find_member(const string &username);
};

#endif // DATABASE_HPP