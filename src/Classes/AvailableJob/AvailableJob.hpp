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
    AvailableJob();

    // constructor
    AvailableJob(
        const string &supporterName,
        Period availableTime,
        Skill skill
    );

    // setter
    void set_supporter_name(const string &supporterName);
    void set_available_time(Period &availableTime);
    void set_skill(Skill &skill);

    // getter
    const string get_supporter_name() const;
    const Period get_available_time() const;
    const Skill get_skill() const;

    // operator
    bool operator==(const AvailableJob &availableJob) const;

// show info
    void showInfo();
    friend class MenuSystem;

};

#endif // AVAILABLEJOB_HPP

