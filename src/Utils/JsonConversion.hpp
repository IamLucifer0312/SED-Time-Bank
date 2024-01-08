#include "../../nlohmann/json.hpp"
#include "../Request/Request.hpp"
#include "../AvailableJob/AvailableJob.hpp"
#include "../Period/Period.hpp"
#include "../Skill/Skill.hpp"
#include <string>
#include <ctime>

using json = nlohmann::json;
using std::string;

// Check if the file is already included.
#ifndef JSONCONVERSION_HPP
#define JSONCONVERSION_HPP

// overwrite json functions, will be moved to another file later

// to_json functions

void to_json(json &j, const Request &r); 

void to_json(json &j, const AvailableJob &h);

void to_json(json &j, const Period &p);

void to_json(json &j, const Skill &s);

// from_json functions

void from_json(const json &j, Skill &s);

void from_json(const json& j, Period& p);

void from_json(const json &j, AvailableJob &job);



#endif // JSONCONVERSION_HPP