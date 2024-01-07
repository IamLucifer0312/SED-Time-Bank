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

vector<Request> &Users::Member::get_received_requests()
{
    return receivedRequests;
}

const std::vector<Request> Users::Member::get_sent_requests() const
{
    return sentRequests;
}

const std::vector<Period> Users::Member::get_available_times() const
{
    return available_times;
}

const std::vector<string> Users::Member::get_block_list() const
{
    return block_list;
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
    for (const Skill &skill : skills)
    {
        json singleSkill;
        singleSkill["skill_name"] = skill.get_skill_name();
        singleSkill["consumed_per_hour"] = skill.get_consumed_per_hour();
        singleSkill["minimum_rating"] = skill.get_mininum_rating();
        skillsArray.push_back(singleSkill);
    }

    // Adding the skills array to the JSON object
    j["skills"] = skillsArray;

    // Creating a JSON array for available times
    json availableTimesArray;
    for (const Period &availableTime : available_times)
    {
        json singleAvailableTime;
        singleAvailableTime["start_time"] =  availableTime.get_start_time_string();
        singleAvailableTime["end_time"] =  availableTime.get_end_time_string();
        availableTimesArray.push_back(singleAvailableTime);
    }

    // Adding the available times array to the JSON object
    j["available_times"] = availableTimesArray;

    json blockListArray;
    for (const auto &block_member : block_list)
    {
        blockListArray.push_back(block_member);
    }
    j["block_list"] = blockListArray;
    
    // Creating a JSON array for recieved requests
    json receivedRequestsArray;
    for (const Request &request : receivedRequests)
    {
        json singleRequest = request;
        receivedRequestsArray.push_back(singleRequest);
    }
    // Adding the recieved requests array to the JSON object
    j["received_requests"] = receivedRequestsArray;
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

    // Deserialize available times array
    if (j.find("available_times") != j.end())
    {
        const json &availableTimesArray = j.at("available_times");
        for (const auto &availableTime : availableTimesArray)
        {
            std::string startTime = availableTime.at("start_time").get<std::string>();
            std::string endTime = availableTime.at("end_time").get<std::string>();
            available_times.emplace_back(startTime, endTime);
        }
    }

    // Deserialize available jobs array (not implemented yet)
    // Desirialize block list array
    if (j.find("block_list") != j.end())
    {
        const json &blockListArray = j.at("block_list");
        for (const auto &block_member : blockListArray)
        {
            block_list.push_back(block_member);
        }
    }

    // Deserialize recieved requests array
    if (j.find("received_requests") != j.end())
    {
        const json &receivedRequestsArray = j.at("received_Requests");
        for (const auto &request : receivedRequestsArray)
        {
            std::string host = request.at("host").get<std::string>();
            std::string supporter = request.at("supporter").get<std::string>();
            AvailableJob job = request.at("job").get<AvailableJob>();
            std::string workTime = request.at("work_time").get<std::string>();
            Status status = static_cast<Status>(request.at("status").get<int>());
            float totalCredit = request.at("total_credit").get<float>();
            receivedRequests.emplace_back(host, supporter, job, workTime, status, totalCredit);
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
void Users::Member::add_available_job(Period &available_time, Skill &skill)
{
    AvailableJob availableJob = AvailableJob(this->username, available_time, skill);
    this->available_jobs.push_back(availableJob);
}

// add available time
void Users::Member::add_available_time(string &startTime, string &endTime)
{
    Period available_time = Period(startTime, endTime);
    this->available_times.push_back(available_time);
}

void Users::Member::add_block_list(string &username)
{
    this->block_list.push_back(username);
}


// remove
void Users::Member::remove_skill(string &skill_name)
{
    for (int i = 0; i < this->skills.size(); i++)
    {
        if (this->skills[i].get_skill_name() == skill_name)
        {
            this->skills.erase(this->skills.begin() + i);
        }
    }
}

// void Users::Member::remove_available_job(Period &available_time, Skill &skill)
// {
//     for (int i = 0; i < this->available_jobs.size(); i++)
//     {
//         if (this->available_jobs[i].get_available_time().get_start_time_string() == available_time.get_start_time_string() && this->available_jobs[i].get_available_time().get_end_time_string() == available_time.get_end_time_string() && this->available_jobs[i].get_skill().get_skill_name() == skill.get_skill_name())
//         {
//             this->available_jobs.erase(this->available_jobs.begin() + i);
//         }
//     }
// }

void Users::Member::remove_available_time(string &startTime, string &endTime)
{
    for (int i = 0; i < this->available_times.size(); i++)
    {
        if (this->available_times[i].get_start_time_string() == startTime && this->available_times[i].get_end_time_string() == endTime)
        {
            this->available_times.erase(this->available_times.begin() + i);
        }
    }
}

void Users::Member::remove_block_list(string &username)
{
    for (int i = 0; i < this->block_list.size(); i++)
    {
        if (this->block_list[i] == username)
        {
            this->block_list.erase(this->block_list.begin() + i);
        }
    }
}

void Users::Member::show_member_info(std::string role) {
    if (role == "member") {    
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        
        std::cout << "Skills: " << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "Available times: " << std::endl;
        for (Period &available_time : this->available_times)
        {   
            std::cout << "Period 1" << std::endl;
            std::cout << available_time.get_start_time_string() << std::endl;
            std::cout << available_time.get_end_time_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    else if (role == "admin" || role == "self")
    {
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Password :" << this->password << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        std::cout << "Credit: " << this->credit << std::endl;
        std::cout << "Skills: " << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
        }
        std::cout << "Available times: " << std::endl;
        for (Period &available_time : this->available_times)
        {
            std::cout << available_time.get_start_time_string() << std::endl;
            std::cout << available_time.get_end_time_string() << std::endl;
        }
        std::cout << std::endl;
        for (std::string &block_member : this->block_list)
        {
            std::cout << block_member << std::endl;
        }
    }
    else if (role == "guest") {    
        std::cout << "Username: " << this->username << std::endl;
        std::cout << "Full name: " << this->full_name << std::endl;
        std::cout << "Phone number: " << this->phone_number << std::endl;
        std::cout << "Home address: " << this->home_address << std::endl;
        std::cout << "Email: " << this->email << std::endl;
        std::cout << "City: " << this->city << std::endl;
        
        std::cout << "Skills: " << std::endl;
        for (Skill &skill : this->skills)
        {
            std::cout << skill.get_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << "Available times: " << std::endl;
        for (Period &available_time : this->available_times)
        {   
            std::cout << "Period 1" << std::endl;
            std::cout << available_time.get_start_time_string() << std::endl;
            std::cout << available_time.get_end_time_string() << std::endl;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}



// overwrite json functions, will be moved to another file later

void to_json(json &j, const Request &r)
{
    j = json{{"host", r.get_host()}, {"supporter", r.get_supporter()}, {"job", r.get_job()}, {"work_time", r.get_work_time_object()}, {"status", static_cast<int>(r.get_status())}, {"total_credit", r.get_total_credit()}};
}

void to_json(json &j, const AvailableJob &h)
{
    j = json{{"supporterName", h.get_supporter_name()}, {"availableTime", h.get_available_time()}, {"skill", h.get_skill()}};
}

void to_json(json &j, const Period &p)
{
    j = json{{"start_time", p.get_start_time_string()}, {"end_time", p.get_end_time_string()}};
}

void to_json(json &j, const Skill &s)
{
    j = json{{"skill_name", s.get_skill_name()}, {"consumed_per_hour", s.get_consumed_per_hour()}, {"minimum_rating", s.get_mininum_rating()}};
}

void from_json(const json &j, AvailableJob &job)
{
    string supporterName = j.at("supporterName").get<string>();
    Period availableTime = j.at("availableTime").get<Period>();
    Skill skill = j.at("skill").get<Skill>();
    job = AvailableJob(supporterName, availableTime, skill);
}

void from_json(const json &j, Skill &s)
{
    string skillName = j.at("skill_name").get<string>();
    float consumedPerHour = j.at("consumed_per_hour").get<float>();
    float minimumRating = j.at("minimum_rating").get<float>();
    s = Skill(skillName, consumedPerHour, minimumRating);
}

void from_json(const json &j, Period &p)
{
    string startTime = j.at("start_time").get<string>();
    string endTime = j.at("end_time").get<string>();
    p = Period(startTime, endTime);
}
