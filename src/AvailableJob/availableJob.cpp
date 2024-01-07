#include <iostream>
#include "AvailableJob.hpp"
#include <string>

// default constructor
AvailableJob::AvailableJob()
{
    this->supporterName = "";
    this->availableTime = Period();
    this->skill = Skill();
}

// constructor
AvailableJob::AvailableJob(
    const std::string &supporterName,
    const Period &availableTime,
    const Skill &skill) : AvailableJob()
{
    this->supporterName = supporterName;
    this->availableTime = availableTime;
    this->skill = skill;
}

// setter
void AvailableJob::set_supporter_name(const string &supporterName)
{
    this->supporterName = supporterName;
}

void AvailableJob::set_available_time(const Period &availableTime)
{
    this->availableTime = availableTime;
}

void AvailableJob::set_skill(const Skill &skill)
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

// copy constructor
AvailableJob::AvailableJob(const AvailableJob &other)
{
    this->supporterName = other.supporterName;
    this->availableTime = other.availableTime;
    this->skill = other.skill;
}
