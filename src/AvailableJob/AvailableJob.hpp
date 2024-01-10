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
    string startTime;
    string endTime;
    Skill* skill;
    public:
    // default constructor
    AvailableJob();

    // constructor
    AvailableJob(
        const string &supporterName,
        string &startTime,
        string &endTime,
        Skill* skill
    );

    // setter
    void set_supporter_name(const string &supporterName);
    void set_start_time(const string &startTime);
    void set_end_time(const string &endTime);
    void set_skill(Skill &skill);

    // getter
    const string get_supporter_name() const;
    const string get_start_time() const;
    const string get_end_time() const;
    const Skill* get_skill() const;



};

#endif // AVAILABLEJOB_HPP

