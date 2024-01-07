#include "../Period/Period.hpp"
#include "../Skill/Skill.hpp"
#include <vector>
#include <string>
using std::string;



using std::vector;

// Check if file is already included
#ifndef AVAILABLEJOB_HPP
#define AVAILABLEJOB_HPP

class AvailableJob
{
private:
    string supporterName;
    Period availableTime;
    Skill skill;
    public:
    // default constructor
    AvailableJob() : supporterName("") {};

    // constructor
    AvailableJob(
        const string &supporterName,
        const Period &availableTime,
        const Skill &skill
    ) {};

    // setter
    void set_supporter_name(const string &supporterName);
    void set_available_time(const Period &availableTime);
    void set_skill(const Skill &skill);

    // getter
    const string get_supporter_name() const;
    const Period get_available_time() const;
    const Skill get_skill() const;



};

#endif // AVAILABLEJOB_HPP

