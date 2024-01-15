#include "../AvailableJob/AvailableJob.hpp"
#include "../Period/Period.hpp"
#include <string>

using std::string;

// Check if the file is already included
#ifndef REQUEST_HPP
#define REQUEST_HPP

enum Status
{
    PENDING,
    ACCEPTED,
    REJECTED
};

class Request
{
private:
    string host;
    string supporter;
    AvailableJob job;
    string tempSkillName;
    Period workTime;
    Status status;
    float totalCredit = 0;

public:
    // default constructor
    Request();

    // constructor
    Request(const string &hostUsername, const AvailableJob &job, const Period &workTime, const Status &status, const string tempSkillName);

    // setter
    void set_host(string &host);
    void set_job(AvailableJob job);
    void set_work_time(Period workTime);
    void set_status(Status status);

    Status string_to_status(string str);
    void set_total_credit(float totalCredit);

    // getter
    const string get_host() const;
    const string get_supporter() const;
    AvailableJob& get_job();
    string get_temp_skill_name() const;
    const Period get_work_time() const;
    const Status get_status() const;
    const string get_status_string() const;
    const float get_total_credit() const;

    // operator
    bool operator==(const Request &request) const;
};

#endif // REQUEST_HPP