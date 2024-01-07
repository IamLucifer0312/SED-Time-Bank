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
    this->startTime = parse_date_time(startTime.c_str());
    this->endTime = parse_date_time(endTime.c_str());
    this->durationByHour = calculate_duration_by_hour();
}

// function to convert a date or time string to time_t.

time_t Period::parse_date_time(const string datetimeString) {
    const string format = "%Y-%m-%d %H:%M:%S";

    // Initialize a std::tm structure to hold the parsed date and time
    std::tm timeStruct = {};

    // Create an input string stream and parse the date string using std::get_time
    std::istringstream ss(datetimeString);
    ss >> std::get_time(&timeStruct, format.c_str());

    // Check for parsing errors
    if (ss.fail()) {
        std::cerr << "Error parsing date string\n";
        return -1; // Indicates an error
    }

    // Convert the std::tm structure to a time_t value using std::mktime
    time_t timeValue = std::mktime(&timeStruct);

    // Check for conversion errors
    if (timeValue == -1) {
        std::cerr << "Error converting std::tm to time_t\n";
        return -1; // Indicates an error
    }

    // Return the resulting time_t value
    return timeValue;
}


// function to convert a time_t to a date or time string.
string Period::format_date_time(time_t time) const
{
    const string format = "%Y-%m-%d %H:%M:%S";
    char buffer[80];
    struct tm *tm_info;

    tm_info = localtime(&time);

    strftime(buffer, sizeof(buffer), format.c_str(), tm_info);
    return buffer;
}

// function to calculate duration by hour
float Period::calculate_duration_by_hour()
{
    // Calculate the difference in seconds
    double diffSeconds = difftime(endTime, startTime);

    // Convert seconds to hours
    return static_cast<float>(diffSeconds) / 3600.0;
}

// setter
void Period::set_start_time(string startTime)
{
    this->startTime = parse_date_time(startTime);
}

void Period::set_end_time(string endTime)
{
    this->endTime = parse_date_time(endTime);
}

// getter
const string Period::get_start_time_string() const
{
    return format_date_time(startTime);
}

const string Period::get_end_time_string() const 
{
    return format_date_time(endTime);
}

time_t Period::get_start_time()
{
    return startTime;
}

time_t Period::get_end_time()
{
    return endTime;
}

float Period::get_duration_by_hour()
{
    return durationByHour;
}