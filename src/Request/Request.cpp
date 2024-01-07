#include "Request.hpp"

// default constructor
Request::Request() : host(nullptr), supporter(nullptr), job(AvailableJob()), workTime(Period()), status(PENDING), totalCredit(0)
{
}

// constructor
Request::Request(string &host, AvailableJob &job, Period &workTime, Status &status)
{
    this->host = host;
    this->supporter = job.get_supporter_name();
    this->job = job;
    this->workTime = workTime;
    this->status = status;
    this->totalCredit = workTime.get_duration_by_hour() * job.get_skill().get_consumed_per_hour();
}

// setter
void Request::set_host(string &host)
{
    this->host = host;
}

void Request::set_job(AvailableJob job)
{
    this->job = job;
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

// getter
string Request::get_host()
{
    return host;
}

string Request::get_supporter()
{
    return supporter;
}

AvailableJob Request::get_job()
{
    return job;
}

Period Request::get_work_time()
{
    return workTime;
}

Status Request::get_status()
{
    return status;
}

float Request::get_total_credit()
{
    return totalCredit;
}

