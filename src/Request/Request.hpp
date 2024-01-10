#include "../AvailableJob/AvailableJob.hpp"
#include "../Period/Period.hpp"
#include <string>
#include <cstring>

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
    string hostUsername;
    string supporterUsername;
    AvailableJob job;
    Period workTime;
    Status status;
    float totalCredit;

public:
    // default constructor
    Request();

    // constructor
    Request(const string &hostUsername, const AvailableJob &job, const Period &workTime);

    // setter
    void set_host(string &hostUsername);
    void set_job(AvailableJob job);
    void set_work_time(Period workTime);
    void set_status(Status status);
    void set_total_credit(float totalCredit);

    // getter
    const string get_host() const;
    const string get_supporter() const;
    const AvailableJob get_job() const;
    const string get_job_name() const;
    const Period get_work_time_object() const;
    const string get_work_time_string() const;
    const Status get_status() const;
    const float get_total_credit() const;

};

#endif // REQUEST_HPP