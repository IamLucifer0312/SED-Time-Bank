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

namespace nlohmann {
    template <>
    // struct adl_serializer<YourType> {
    //     static void to_json(json& j, const YourType& obj);
    //     static void from_json(const json& j, YourType& obj);
    // };

    struct adl_serializer<Skill> {
        static void to_json(json& j, const Skill& obj);
        static void from_json(const json& j, Skill& obj);
    };

}


void to_json(json &j, const Request &r); 

void to_json(json &j, const AvailableJob &h);

void to_json(json &j, const Period &p);

// void to_json(json &j, const Skill &s);


void from_json(const json &j, Skill &s);

void from_json(const json& j, Period& p);

void from_json(const json &j, AvailableJob &job);



#endif // JSONCONVERSION_HPP