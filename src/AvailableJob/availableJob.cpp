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


