#include <iostream>
#include "AvailableJob.hpp"
#include <string>

// default constructor
AvailableJob::AvailableJob() {
    this->supporterName = "";
}


// constructor
AvailableJob::AvailableJob(
    const std::string &supporterName,
    Period availableTime,
    Skill skill
) : AvailableJob() {
    this->supporterName = supporterName;
    this->availableTime = availableTime;
    this->skill = skill;
}

// setter
void AvailableJob::set_supporter_name(const string &supporterName)
{
    this->supporterName = supporterName;
}

void AvailableJob::set_available_time(Period &availableTime)
{
    this->availableTime = availableTime;
}

void AvailableJob::set_skill(Skill &skill)
{
    this->skill = skill;
}

// getter

const string AvailableJob::get_supporter_name() const
{
    return supporterName;
}

const Period AvailableJob::get_available_time() const
{
    return availableTime;
}


const Skill AvailableJob::get_skill() const
{
    return skill;
}

// operator
bool AvailableJob::operator==(const AvailableJob &availableJob) const
{
    return this->supporterName == availableJob.supporterName;
}

void AvailableJob::showInfo() {
    std::cout << "Supporter name: " << supporterName << std::endl;
    std::cout << skill.get_string() << std::endl;
    std::cout << "Start time:" << availableTime.get_start_time_string() << std::endl;
    std::cout << "End time:" << availableTime.get_end_time_string() << std::endl;
    std::cout << std::endl;
};

