#include <iostream>
#include "AvailableJob.hpp"
#include <string>

// default constructor
AvailableJob::AvailableJob() {
    this->supporterName = "";
    this->startTime = "";
    this->endTime = "";
    this->skill = nullptr;
}


// constructor
AvailableJob::AvailableJob(
    const std::string &supporterName,
    string &startTime,
    string &endTime,
    Skill* skill
) : AvailableJob() {
    this->supporterName = supporterName;
    this->startTime = startTime;
    this->endTime = endTime;
    this->skill = skill;
}

// setter
void AvailableJob::set_supporter_name(const string &supporterName)
{
    this->supporterName = supporterName;
}

void AvailableJob::set_start_time(const string &startTime)
{
    this->startTime = startTime;
}

void AvailableJob::set_end_time(const string &endTime)
{
    this->endTime = endTime;
}

void AvailableJob::set_skill(Skill &skill)
{
    this->skill = &skill;
}

// getter

const string AvailableJob::get_supporter_name() const
{
    return supporterName;
}

const string AvailableJob::get_start_time() const
{
    return startTime;
}

const string AvailableJob::get_end_time() const
{
    return endTime;
}


const Skill* AvailableJob::get_skill() const
{
    return skill;
}


