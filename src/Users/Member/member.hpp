#include <string>
#include <vector>
#include <map>
#include "../../../nlohmann/json.hpp"
#include "../User/User.hpp"
#include "../../Skill/Skill.hpp"

using json = nlohmann::json;
using std::string;

// Check if the file is already included.
#ifndef MEMBER_HPP
#define MEMBER_HPP

namespace Users
{
    class Member : public User
    {
    private:
        string full_name;
        string phone_number;
        string home_address;
        string email;
        string city;
        std::vector<Skill> skills;
        float credit;

    public:
        // default constructor
        Member();

        // constructor
        Member(
            const string &username,
            const string &password,
            const string &full_name,
            const string &phone_number,
            const string &home_address,
            const string &email,
            const string &city,
            const float &credit
            );

        // Getter methods
        const string get_full_name() const;

        const string get_phone_number() const;

        const string get_home_address() const;

        const string get_email() const;

        const string get_city() const;

        const float get_credit() const;

        const string get_password() const;

        const std::vector<Skill> get_skills() const;



        // Setter methods
        void set_full_name(const string &full_name);

        void set_phone_number(const string &phone_number);

        void set_home_address(const string &home_address);

        void set_email(const string &email);

        void set_city(const string &city);

        void set_credit(const float &credit);

        void set_password(const string &password);

        // add skill
        void add_skill(string &skill_name, float &consumed_per_hour, float &minimum_rating );

        // extract data from map
        void from_map(std::map<string, string> map);

        // convert data to map
        std::map<string, string> to_map_member() const;

        // Serialization function for Member class
        void serialize(json &j) const;

        // Deserialization function for Member class
        void deserialize(const json &j);
        
        // show member info
        void show_member_info(std::string role);

    };

} // namespace Users

#endif // MEMBER_HPP