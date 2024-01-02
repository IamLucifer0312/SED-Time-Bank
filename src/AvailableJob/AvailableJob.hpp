#include "../Users/Member/member.hpp"
#include "../Period/Period.hpp"
#include "../Skill/Skill.hpp"
#include <vector>

using std::vector;

// Check if file is already included
#ifndef AVAILABLEJOB_HPP
#define AVAILABLEJOB_HPP

class AvailableJob
{
private:
    Users::Member supporter;
    Period availableTime;
    vector<Skill> skills;
    public:
    // default constructor
    AvailableJob();

    // constructor
    AvailableJob(
        const Users::Member &supporter,
        const Period &availableTime,
        const vector<Skill> &skills
    );

    // setter
    void set_supporter(const Users::Member &supporter);
    void set_available_time(const Period &availableTime);
    void set_skills(const vector<Skill> &skills);

    // getter
    const Users::Member get_supporter() const;
    const Period get_available_time() const;
    const vector<Skill> get_skills() const;



};

#endif // AVAILABLEJOB_HPP

