#include <iostream>
#include "Member.hpp"

// default constructor
Users::Member::Member()
{
    this->full_name = "";
    this->phone_number = "";
    this->home_address = "";
    this->email = "";
    this->city = "";
    this->credit = 20;
    this->skills = {};
}

// constructor
Users::Member::Member(
    const string &username,
    const string &password,
    const string &full_name,
    const string &phone_number,
    const string &home_address,
    const string &email,
    const string &city,
    const float &credit) : User(username, password)
{
    this->full_name = full_name;
    this->phone_number = phone_number;
    this->home_address = home_address;
    this->email = email;
    this->city = city;
    this->credit = credit;
    this->skills = {};
}

// Getter methods
const string Users::Member::get_full_name() const
{
    return full_name;
}

const string Users::Member::get_phone_number() const
{
    return phone_number;
}

const string Users::Member::get_home_address() const
{
    return home_address;
}

const string Users::Member::get_email() const
{
    return email;
}

const string Users::Member::get_city() const
{
    return city;
}

const float Users::Member::get_credit() const
{
    return credit;
}

const std::vector<Skill> Users::Member::get_skills() const
{
    return skills;
}

const string Users::Member::get_password() const
{
    return password;
}

const std::vector<AvailableJob> Users::Member::get_available_jobs() const
{
    return available_jobs;
}
    
vector<Request> &Users::Member::get_received_requests() {
    return receivedRequests;
}

const std::vector<Request> Users::Member::get_sent_requests() const
{
    return sentRequests;
}

// extract data from map
void Users::Member::from_map(std::map<string, string> map)
{
    User::from_map(map);
    this->full_name = map["full_name"];
    this->phone_number = map["phone_number"];
    this->home_address = map["home_address"];
    this->email = map["email"];
    this->city = map["city"];
    this->credit = std::stof(map["credit"]);
}

// convert data to map
std::map<string, string> Users::Member::to_map_member() const
{
    std::map<string, string> map = to_map_member();
    map.emplace("full_name", this->full_name);
    map.emplace("phone_number", this->phone_number);
    map.emplace("home_address", this->home_address);
    map.emplace("email", this->email);
    map.emplace("city", this->city);
    map.emplace("credit", std::to_string(this->credit));
    return map;
}

// Serialization function for Member class
void Users::Member::serialize(json &j) const
{
    j = {
        {"username", username},
        {"password", password},
        {"full_name", full_name},
        {"phone_number", phone_number},
        {"home_address", home_address},
        {"email", email},
        {"city", city},
        {"credit", credit}
        // Add more member variables to serialize
    };

    // Creating a JSON array for skills
    json skillsArray;
    for (const auto &skill : skills)
    {
        json singleSkill;
        singleSkill["skill_name"] = skill.get_skill_name();
        singleSkill["consumed_per_hour"] = skill.get_consumed_per_hour();
        singleSkill["minimum_rating"] = skill.get_mininum_rating();
        skillsArray.push_back(singleSkill);
    }

    // Adding the skills array to the JSON object
    j["skills"] = skillsArray;
}

// Deserialization function for Member class
void Users::Member::deserialize(const json &j)
{
    username = j.at("username").get<string>();
    password = j.at("password").get<string>();
    full_name = j.at("full_name").get<string>();
    phone_number = j.at("phone_number").get<string>();
    home_address = j.at("home_address").get<string>();
    email = j.at("email").get<string>();
    city = j.at("city").get<string>();
    credit = j.at("credit").get<float>();
    // Deserialize other member variables

    // Deserialize skills array
    if (j.find("skills") != j.end())
    {
        const json &skillsArray = j.at("skills");
        for (const auto &skill : skillsArray)
        {
            std::string skillName = skill.at("skill_name").get<std::string>();
            float consumedPerHour = skill.at("consumed_per_hour").get<float>();
            float minimumRating = skill.at("minimum_rating").get<float>();
            skills.emplace_back(skillName, consumedPerHour, minimumRating);
        }
    }
}

// Setters:

void Users::Member::set_full_name(const string &full_name)
{
    this->full_name = full_name;
}

void Users::Member::set_phone_number(const string &phone_number)
{
    this->phone_number = phone_number;
}

void Users::Member::set_home_address(const string &home_address)
{
    this->home_address = home_address;
}

void Users::Member::set_email(const string &email)
{
    this->email = email;
}

void Users::Member::set_city(const string &city)
{
    this->city = city;
}

void Users::Member::set_credit(const float &credit)
{
    this->credit = credit;
}

void Users::Member::set_password(const string &password)
{
    this->password = password;
}

// add skill
void Users::Member::add_skill(string &skill_name, float &consumed_per_hour, float &minimum_rating)
{
    Skill skill = Skill(skill_name, consumed_per_hour, minimum_rating);
    this->skills.push_back(skill);
}

// add available job
void Users::Member::add_available_job()
{
    AvailableJob availableJob = AvailableJob();
    this->available_jobs.push_back(availableJob);
}

void Users::Member::show_member_info(std::string role)
{
    if (role == "member")
    {
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
        }
        std::cout << std::endl;
    }
    else if (role == "admin")
    {
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Password :" << this->password << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        std::cout << "Credit: " << this->credit << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
        }
        std::cout << std::endl;
    }

    // std::cout << "Credit: " << this->credit << std::endl;
}
