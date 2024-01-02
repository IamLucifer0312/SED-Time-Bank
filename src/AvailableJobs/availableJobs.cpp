#include "AvailableJobs.hpp"

// default constructor
AvailableJobs::AvailableJobs()
{
    this->supporter = Users::Member();
    this->availableTime = Period();
    this->skills = {};
}

// constructor
AvailableJobs::AvailableJobs(
    const Users::Member &supporter,
    const Period &availableTime,
    const vector<Skill> &skills
) {
    this->supporter = supporter;
    this->availableTime = availableTime;
    this->skills = supporter.get_skills();
}

// setter
void AvailableJobs::set_supporter(const Users::Member &supporter)
{
    this->supporter = supporter;
}

void AvailableJobs::set_available_time(const Period &availableTime)
{
    this->availableTime = availableTime;
}

void AvailableJobs::set_skills(const vector<Skill> &skills)
{
    this->skills = skills;
}

// getter

const Users::Member AvailableJobs::get_supporter() const
{
    return supporter;
}

const Period AvailableJobs::get_available_time() const
{
    return availableTime;
}

const Skill AvailableJobs::get_skills() const
{
    return skills;
}


