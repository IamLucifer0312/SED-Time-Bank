#include "../Users/Member/member.hpp"
#include "../AvailableJob/AvailableJob.hpp"
#include "../Period/Period.hpp"

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
    const Users::Member *host;
    const Users::Member *supporter;
    AvailableJob job;
    Period workTime;
    Status status;
    float totalCredit;

public:
    // default constructor
    Request();

    // constructor
    Request(const Users::Member &host, AvailableJob &job, Period &workTime, Status &status);

    // setter
    void set_host(Users::Member &host);
    void set_job(AvailableJob job);
    void set_work_time(Period workTime);
    void set_status(Status status);
    void set_total_credit(float totalCredit);

    // getter
    Users::Member get_host();
    Users::Member get_supporter();
    AvailableJob get_job();
    Period get_work_time();
    Status get_status();
    float get_total_credit();

};

#endif // REQUEST_HPP