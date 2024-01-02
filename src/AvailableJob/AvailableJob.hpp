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
    const Users::Member* supporter;
    Period availableTime;
    Skill skill;
    public:
    // default constructor
    AvailableJob();

    // constructor
    AvailableJob(
        const Users::Member &supporter,
        const Period &availableTime,
        const Skill &skill
    );

    // setter
    void set_supporter(const Users::Member &supporter);
    void set_available_time(const Period &availableTime);
    void set_skill(const Skill &skill);

    // getter
    const Users::Member get_supporter() const;
    const Period get_available_time() const;
    const Skill get_skill() const;



};

#endif // AVAILABLEJOB_HPP

