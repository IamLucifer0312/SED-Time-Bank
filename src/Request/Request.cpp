#include "Request.hpp"

// default constructor
Request::Request() : hostUsername(""), supporterUsername(""), job(AvailableJob()), workTime(Period()), status(PENDING), totalCredit(0)
{
}

// constructor
Request::Request(const string &hostUsername, const AvailableJob &job, const Period &workTime)
{
    this->hostUsername = hostUsername;
    this->supporterUsername = job.get_supporter_name();
    this->job = job;
    this->workTime = workTime;
    this->status = Status::PENDING;
    this->totalCredit = workTime.get_duration_by_hour() * job.get_skill().get_consumed_per_hour();
}

// setter
void Request::set_host(string &hostUsername)
{
    this->hostUsername = hostUsername;
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
const string Request::get_host() const
{
    return hostUsername;
}

const string Request::get_supporter() const
{
    return supporterUsername;
}

const AvailableJob Request::get_job() const
{
    return job;
}

const string Request::get_job_name() const
{
    return job.get_skill().get_skill_name();
}

const Period Request::get_work_time_object() const
{
    return workTime;
}

const string Request::get_work_time_string() const 
{
    return workTime.get_start_time_string() + " - " + workTime.get_end_time_string();
}

const Status Request::get_status() const 
{
    return status;
}

const float Request::get_total_credit() const
{
    return totalCredit;
}

