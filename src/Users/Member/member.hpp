#include <string>
#include <vector>
#include <map>
#include "../../../nlohmann/json.hpp"
#include "../User/User.hpp"
#include "../../Skill/Skill.hpp"
#include "../../AvailableJob/AvailableJob.hpp"
#include "../../Request/Request.hpp"
#include "../../Period/Period.hpp"
#include <ctime>



using json = nlohmann::json;
using std::string;
using std::vector;

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
        vector<Skill> skills;
        vector<AvailableJob> available_jobs;
        vector<Period> available_times;
        vector<Request*> receivedRequests;
        vector<Request*> sentRequests;
        vector<string> block_list;

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

        const std::vector<Period> get_available_times() const;

        const std::vector<AvailableJob> get_available_jobs() const;
        
        const std::vector<Request*> get_received_requests() const;

        const std::vector<Request*> get_sent_requests() const;

        const std::vector<string> get_block_list() const;



        // Setter methods
        void set_full_name(const string &full_name);

        void set_phone_number(const string &phone_number);

        void set_home_address(const string &home_address);

        void set_email(const string &email);

        void set_city(const string &city);

        void set_credit(const float &credit);

        void set_password(const string &password);

        // add 
        void add_skill(string &skill_name, float &consumed_per_hour, float &minimum_rating );
        void add_available_job(Period &availableTime, Skill &skill);
        void add_available_time(string &startTime, string &endTime);
        void add_block_list(string &username);

        // remove
        void remove_skill(string &skill_name);
        // void remove_available_job(Period &available_time, Skill &skill);
        void remove_available_time(string &startTime, string &endTime);
        void remove_block_list(string &username);

        // extract data from map
        void from_map(std::map<string, string> map);

        // convert data to map
        std::map<string, string> to_map_member() const;

        // Serialization function for Member class
        void serialize(json &j) const;

        // Deserialization function for Member class
        void deserialize(const json &j);
        Skill get_skill_by_name(string &skillName);
        Period get_time_by_start_end(string &startTime, string &endTime);
        
        // show member info
        void show_member_info(std::string role);

        // check overlap available time
        bool is_overlap(time_t startTime, time_t endTime);

    };

} // namespace Users

#endif // MEMBER_HPP