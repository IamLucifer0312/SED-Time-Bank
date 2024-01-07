#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>

using std::string;

// Checl if file is already included
#ifndef PERIOD_HPP
#define PERIOD_HPP

class Period
{
public:
    time_t startTime;
    time_t endTime;
    float durationByHour;


    // default constructor
    Period();

    // constructor
    Period(string startTime, string endTime);

    // function to convert a date or time string to time_t.
    time_t parse_date_time(const string datetimeString);

    // function to convert a time_t to a date or time string.
     string format_date_time(time_t time) const;

    // function to calculate duration by hour
    float calculate_duration_by_hour();

    // setter
    void set_start_time(string startTime);

    void set_end_time(string endTime);

    // getter
    const string get_start_time_string() const;

    const string get_end_time_string() const;

    time_t get_start_time();

    time_t get_end_time();

    float get_duration_by_hour();

};

#endif // PERIOD_HPP