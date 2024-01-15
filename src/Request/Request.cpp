#include "Request.hpp"

// default constructor
Request::Request() : host(nullptr), supporter(nullptr), job(AvailableJob()), workTime(Period()), status(PENDING), totalCredit(0)
{
}

// constructor
Request::Request(const string &hostUsername, const AvailableJob &job, const Period &workTime, const Status &status, const string tempSkillName)
{
    this->host = hostUsername;
    this->supporter = job.get_supporter_name();
    this->job = job;
    this->workTime = workTime;
    this->status = status;
    this->totalCredit = workTime.get_duration_by_hour() * job.get_skill().get_consumed_per_hour();
    this->tempSkillName = tempSkillName;
}

// setter
void Request::set_host(string &host)
{
    this->host = host;
}

void Request::set_job(AvailableJob job)
{
    this->job = job;
    this->totalCredit = workTime.get_duration_by_hour() * job.get_skill().get_consumed_per_hour();

}

void Request::set_work_time(Period workTime)
{
    this->workTime = workTime;
}

void Request::set_status(Status status)
{
    this->status = status;
}

void Request::set_total_credit(float totalCredit)
{
    this->totalCredit = totalCredit;
}

// string to status
Status Request::string_to_status(string str)
{
    if (str == "PENDING")
        return PENDING;
    else if (str == "ACCEPTED")
        return ACCEPTED;
    else if (str == "REJECTED")
        return REJECTED;
    else
        return PENDING;
}

// getter
const string Request::get_host() const
{
    return host;
}

const string Request::get_supporter() const
{
    return supporter;
}

AvailableJob& Request::get_job()
{
    return job;
}

string Request::get_temp_skill_name() const
{
    return tempSkillName;
}

const Period Request::get_work_time() const
{
    return workTime;
}

const Status Request::get_status() const
{
    return status;
}

const string Request::get_status_string() const
{
    switch (status)
    {
    case PENDING:
        return "PENDING";
    case ACCEPTED:
        return "ACCEPTED";
    case REJECTED:
        return "REJECTED";
    default:
        return "UNKNOWN";
    }
}

const float Request::get_total_credit() const
{
    return totalCredit;
}


// operator
bool Request::operator==(const Request &request) const
{
    return (this->host == request.host
            && this->supporter == request.supporter 
            && this->job == request.job 
            && this->workTime == request.workTime 
            && this->status == request.status
            );
}