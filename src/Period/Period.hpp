#include <string>
#include <ctime>

using std::string;

// Checl if file is already included
#ifndef PERIOD_HPP
#define PERIOD_HPP

class Period
{
public:
    time_t startTime;
    time_t endTime;

    // default constructor
    Period();

    // constructor
    Period(string startTime, string endTime);

    // function to convert a date or time string to time_t.
    time_t parse_date_time(const string datetimeString);

    // function to convert a time_t to a date or time string.
    string format_date_time(time_t time);

    // setter
    void set_start_time(string startTime);

    // getter
    time_t get_start_time();
};

#endif // PERIOD_HPP