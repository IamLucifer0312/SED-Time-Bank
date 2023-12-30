#include "Skill.hpp"

// default constructor
Skill::Skill()
{
    this->skillName = "";
    this->consumedPerHour = 0;
    this->mininumRating = limitToRange(0, 0, 5);
}

// constructor
Skill::Skill(
    const std::string &skillName,
    const float &consumedPerHour,
    const float &mininumRating
) {
    this->skillName = skillName;
    this->consumedPerHour = consumedPerHour;
    this->mininumRating = limitToRange(mininumRating, 0, 5);
}

// Getter methods
const std::string Skill::get_skill_name() const
{
    return skillName;
}

const float Skill::get_consumed_per_hour() const
{
    return consumedPerHour;
}

const float Skill::get_mininum_rating() const
{
    return mininumRating;
}

std::string Skill::get_string() const
{
    return "Skill: " + skillName + "\n" +
           "  Consumed per hour: " + std::to_string(consumedPerHour) + "\n" +
           "  Minimum rating: " + std::to_string(mininumRating) + "\n";
}


void Skill::set_minimum_rating(const float &mininumRating)
{
    this->mininumRating = limitToRange(mininumRating, 0, 5);
}