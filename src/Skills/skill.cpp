#include "Skill.hpp"

// default constructor
Skill::Skill()
{
    this->skillName = "";
    this->consumedPerHour = 0;
    this->mininum_rating = limitToRange(0, 0, 5);
}

// constructor
Skill::Skill(
    const std::string &skillName,
    const float &consumedPerHour,
    const float &mininum_rating
) {
    this->skillName = skillName;
    this->consumedPerHour = consumedPerHour;
    this->mininum_rating = limitToRange(mininum_rating, 0, 5);
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
    return mininum_rating;
}

std::string Skill::get_string() const
{
    return "Skill: " + skillName + "\n" +
           "  Consumed per hour: " + std::to_string(consumedPerHour) + "\n" +
           "  Minimum rating: " + std::to_string(mininum_rating) + "\n";
}


void Skill::set_minimum_rating(const float &mininum_rating)
{
    this->mininum_rating = limitToRange(mininum_rating, 0, 5);
}