#include "Database.hpp"

#define find_member_macro(username, memberList, found_member) \
    for (Users::Member & member : memberList)                 \
    {                                                         \
        if (member.get_username() == username)                \
        {                                                     \
            found_member = member;                            \
            break;                                            \
        }                                                     \
    }                                                         \
    if (&found_member == &memberList.back())                  \
    {                                                         \
        std::cerr << "Error: Member not found." << std::endl; \
    }

// constructor
Database::Database() {}
Database::Database(const string &member_file_name) : member_file(member_file_name)
{}

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

// Deserialize json to admin vector
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

// Deserialize json to member vector
vector<Users::Member> Database::deserializeMembers(const json &jsonArray)
{
    vector<Users::Member> deserializedMembers;
    for (const auto &memberJson : jsonArray)
    {
        Users::Member member;
        member.deserialize(memberJson);
        deserializedMembers.push_back(member);
    }
    // set the jobs of members to the corresponding requests
    set_job_to_requests(deserializedMembers);

    return deserializedMembers;
}

// set the jobs of members to the corresponding requests
void Database::set_job_to_requests(vector<Users::Member> &deserializedMembers)
{
    for (Users::Member &member : deserializedMembers)
    {
        // set sent requests
        if (!member.get_sent_requests().empty())
        {
            for (Request &request : member.get_sent_requests())
            {
                string skillName = request.get_temp_skill_name();

                Users::Member supporter;
                find_member_macro(request.get_supporter(), deserializedMembers, supporter);

                Skill tempSkill = supporter.get_skill_by_name(skillName);

                AvailableJob &job = request.get_job();
                job.set_skill(tempSkill);

                request.set_job(job);
            }
        }

        // set received requests
        if (!member.get_received_requests().empty())
        {
            for (Request &request : member.get_received_requests())
            {
                string skillName = request.get_temp_skill_name();

                Users::Member supporter;
                find_member_macro(request.get_supporter(), deserializedMembers, supporter);

                Skill tempSkill = supporter.get_skill_by_name(skillName);

                AvailableJob &job = request.get_job();
                job.set_skill(tempSkill);

                request.set_job(job);
            }
        }
       
        // set approved sent requests
        if (!member.get_approved_sent_requests().empty())
        {
            for (Request &request : member.get_approved_sent_requests())
            {
                string skillName = request.get_temp_skill_name();

                Users::Member supporter;
                find_member_macro(request.get_supporter(), deserializedMembers, supporter);

                Skill tempSkill = supporter.get_skill_by_name(skillName);

                AvailableJob &job = request.get_job();
                job.set_skill(tempSkill);

                request.set_job(job);
            }
        }

        // set approved received requests
        if (!member.get_approved_received_requests().empty())
        {
            for (Request &request : member.get_approved_received_requests())
            {
                string skillName = request.get_temp_skill_name();

                Users::Member supporter;
                find_member_macro(request.get_supporter(), deserializedMembers, supporter);

                Skill tempSkill = supporter.get_skill_by_name(skillName);

                AvailableJob &job = request.get_job();
                job.set_skill(tempSkill);

                request.set_job(job);
            }
        }

    }
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
    if (!file.is_open())
    {
        // Create new file if not found
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        std::cerr << "Creating new file: " << filename << std::endl;
        std::ofstream newFile(filename);
        // Initialize the file with default admin account
        json adminData = {
            {"username", "admin"},
            {"password", "rmit1234"},
        };
        json adminArray = json::array();
        adminArray.push_back(adminData);
        newFile << adminArray << std::endl;
        newFile.close();
        // return empty data;
        return deserializeAdmins(adminArray);
    }
    //Reopen the file
    if (!file.is_open())
    {
        std::ifstream file(filename);
    }

    json jsonArray;
    file >> jsonArray;
    file.close();
    return deserializeAdmins(jsonArray);
}

vector<Users::Member> Database::loadMembersFromFile(const string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        // Create new file if not found
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        std::cerr << "Creating new file: " << filename << std::endl;
        std::ofstream newFile(filename);
        // Initialize the file with empty value
        newFile << "[]" << std::endl;
        newFile.close();
        // return empty data
        json jsonArray = json::array();
        return deserializeMembers(jsonArray);
    }

    json jsonArray;
    file >> jsonArray;
    file.close();
    return deserializeMembers(jsonArray);
}

// Load data from file
void Database::loadData()
{
    this->members = loadMembersFromFile(member_file);
    this->admins = loadAdminsFromFile(admin_file);
};

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

// Finder
Users::Member& Database::find_member(const string &username)
{
    for (Users::Member &member : members)
    {
        if (member.get_username() == username)
        {
            return member;
        }
        else if (&member == &members.back()) 
        {
            std::cerr << "Error: Member not found." << std::endl;
        }
    }
    Users::Member *member = new Users::Member();
    return *member;
}