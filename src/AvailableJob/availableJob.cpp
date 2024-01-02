#include "AvailableJob.hpp"

// default constructor
AvailableJob::AvailableJob()
{
    this->supporter = nullptr;
    this->availableTime = Period();
    this->skill = Skill();
}

// constructor
AvailableJob::AvailableJob(
    const Users::Member &supporter,
    const Period &availableTime,
    const Skill &skill
) {
    this->supporter = &supporter;
    this->availableTime = availableTime;
    this->skill = skill;
}

// setter
void AvailableJob::set_supporter(const Users::Member &supporter)
{
    this->supporter = &supporter;
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

const Users::Member AvailableJob::get_supporter() const
{
    return *supporter;
}

const Period AvailableJob::get_available_time() const
{
    return availableTime;
}

const Skill AvailableJob::get_skill() const
{
    return skill;
}


