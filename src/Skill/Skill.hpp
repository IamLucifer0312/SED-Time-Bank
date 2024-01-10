#include <string>
#include <cmath>

// Check if the file is already included.
#ifndef SKILL_HPP
#define SKILL_HPP

class Skill
{
private:
    std::string skillName;
    float consumedPerHour;
    float mininumRating;

    float limitToRange(float number, float minVal, float maxVal) {
        return std::min(maxVal, std::max(minVal, number));
    }
public:
    // default constructor
    Skill();
    // constructor
    Skill(
        const std::string &skillName,
        const float &consumedPerHour,
        const float &mininumRating
    );

    void set_minimum_rating(const float &mininumRating);

    // Getter methods
    const std::string get_skill_name() const;
    const float get_consumed_per_hour() const;
    const float get_mininum_rating() const;
    const Skill* get_ptr() const;

    std::string get_string() const;
};

#endif 
