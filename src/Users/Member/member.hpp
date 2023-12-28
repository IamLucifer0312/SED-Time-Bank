#include <string>
#include <map>
#include "../../../nlohmann/json.hpp"
#include "../User/User.hpp"

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
        //     : User(username, password)
        // {
        //     this->full_name = full_name;
        //     this->phone_number = phone_number;
        //     this->home_address = home_address;
        //     this->email = email;
        //     this->city = city;
        // }

        // Getter methods
        const string get_full_name() const;

        const string get_phone_number() const;

        const string get_home_address() const;

        const string get_email() const;

        const string get_city() const;

        const float get_credit() const;

        // Setter methods
        void set_full_name(const string &full_name);

        void set_phone_number(const string &phone_number);

        void set_home_address(const string &home_address);

        void set_email(const string &email);

        void set_city(const string &city);

        void set_credit(const float &credit);

        // extract data from map
        void from_map(std::map<string, string> map);

        // convert data to map
        std::map<string, string> to_map_member() const;

        // Serialization function for Member class
        void serialize(json &j) const;

        // Deserialization function for Member class
        void deserialize(const json &j);
        // {
        //     username = j.at("username").get<string>();
        //     password = j.at("password").get<string>();
        //     full_name = j.at("full_name").get<string>();
        //     phone_number = j.at("phone_number").get<string>();
        //     home_address = j.at("home_address").get<string>();
        //     email = j.at("email").get<string>();
        //     city = j.at("city").get<string>();
        //     // Deserialize other member variables
        // }
    };

} // namespace Users

#endif // MEMBER_HPP