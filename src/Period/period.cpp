#include "Period.hpp"

// default constructor
Period::Period()
{
    this->startTime = 0;
    this->endTime = 0;
}

// constructor
Period::Period(string startTime, string endTime)
{
    this->startTime = parse_date_time(startTime.c_str(), "%Y-%m-%d %H:%M:%S");
    this->endTime = parse_date_time(endTime.c_str(), "%Y-%m-%d %H:%M:%S");
}

// function to convert a date or time string to time_t.
time_t Period::parse_date_time(const string datetimeString)
{
    const string format = "%Y-%m-%d %H:%M:%S";
    struct tm tm;
    // function to convert a date or time string to time_t.
    if (strptime(datetimeString, format, &tm) != NULL)
    {
        time_t t = mktime(&tm);

        // Check if mktime() succeeded.
        if (t != (time_t)-1)
        {
            return t;
        }
    }
    return 0;
}

// function to convert a time_t to a date or time string.
string Period::format_date_time(time_t time)
{
    const string format = "%Y-%m-%d %H:%M:%S";
    char buffer[80];
    struct tm *tm_info;

    tm_info = localtime(&time);

    strftime(buffer, sizeof(buffer), format, tm_info);
    return buffer;
}

// setter
void Period::set_start_time(string startTime)
{
    this->startTime = parse_date_time(startTime);
}

// getter
time_t Period::get_start_time()
{
    return this->startTime;
}