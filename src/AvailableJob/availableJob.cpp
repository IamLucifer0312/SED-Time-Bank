#include "AvailableJob.hpp"

// default constructor
AvailableJob::AvailableJob()
{
    this->supporter = Users::Member();
    this->availableTime = Period();
    this->skills = {};
}

// constructor
AvailableJob::AvailableJob(
    const Users::Member &supporter,
    const Period &availableTime,
    const vector<Skill> &skills
) {
    this->supporter = supporter;
    this->availableTime = availableTime;
    this->skills = supporter.get_skills();
}

// setter
void AvailableJob::set_supporter(const Users::Member &supporter)
{
    this->supporter = supporter;
}

void AvailableJob::set_available_time(const Period &availableTime)
{
    this->availableTime = availableTime;
}

void AvailableJob::set_skills(const vector<Skill> &skills)
{
    this->skills = skills;
}

// getter

const Users::Member AvailableJob::get_supporter() const
{
    return supporter;
}

const Period AvailableJob::get_available_time() const
{
    return availableTime;
}

const vector<Skill> AvailableJob::get_skills() const
{
    return skills;
}


