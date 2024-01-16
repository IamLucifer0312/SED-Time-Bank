#include <iostream>
#include "Member.hpp"
#include "Functions/SerializeDeserialize.cpp"
#include "Functions/ShowInfo.cpp"

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
    return received_requests;
}

std::vector<Request> &Users::Member::get_sent_requests()
{
    return sent_requests;
}

std::vector<Request> &Users::Member::get_approved_sent_requests()
{
    return approved_sent_requests;
}

std::vector<Request> &Users::Member::get_approved_received_requests()
{
    return approved_received_requests;
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
void Users::Member::add_available_job(const Period &availableTime, Skill &skill)
{
    AvailableJob availableJob = AvailableJob(this->username, availableTime, skill);
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

void Users::Member::add_sent_request(Request &request)
{
    this->sent_requests.push_back(request);
}

void Users::Member::add_received_request(Request &request)
{
    this->received_requests.push_back(request);
}

void Users::Member::add_approved_sent_request(Request &request)
{
    this->approved_sent_requests.push_back(request);
}

void Users::Member::add_approved_received_request(Request &request)
{
    this->approved_received_requests.push_back(request);
}

void Users::Member::add_host_review(HostReview &review)
{
    this->host_reviews.push_back(review);
}

void Users::Member::add_supporter_review(SupporterReview &review)
{
    this->supporter_reviews.push_back(review);
}

void Users::Member::add_credit(float addingCredit) {
    credit += addingCredit;
}

// remove

void Users::Member::subtract_credit(float subtractingCredit) {
    credit -= subtractingCredit;
}

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

bool Users::Member::is_overlap(time_t startTime, time_t endTime)
{
    for (Period &available_time : this->available_times)
    {
        if (endTime < available_time.get_start_time() || available_time.get_end_time() < startTime)
        {
            return false;
        }
        if (static_cast<int>(difftime(available_time.get_start_time(), startTime)) <= 1800)
        {
            return true;
        }
    }
    return false;
}

bool Users::Member::have_skill(std::string skill_name)
{
    for (Skill &skill: skills)
        {
            if (skill_name == skill.get_skill_name())
            {return true;}
        }
    
    return false;
}