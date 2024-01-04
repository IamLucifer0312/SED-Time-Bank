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
    Period workTime;
    Status status;
    float totalCredit;

public:
    // default constructor
    Request();

    // constructor
    Request(string &host, AvailableJob &job, Period &workTime, Status &status);

    // setter
    void set_host(string &host);
    void set_job(AvailableJob job);
    void set_work_time(Period workTime);
    void set_status(Status status);
    void set_total_credit(float totalCredit);

    // getter
    string get_host();
    string get_supporter();
    AvailableJob get_job();
    string get_work_time();
    Status get_status();
    float get_total_credit();

};

#endif // REQUEST_HPP