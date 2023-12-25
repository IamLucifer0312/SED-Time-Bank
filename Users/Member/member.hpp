#include <string>
#include <map>
#include "../../nlohmann/json.hpp"
#include "../User/user.hpp"

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

    public:
        // default constructor
        Member();
        // {
        //     this->full_name = "";
        //     this->phone_number = "";
        //     this->home_address = "";
        //     this->email = "";
        //     this->city = "";
        // }

        // constructor
        Member(
            const string &username,
            const string &password,
            const string &full_name,
            const string &phone_number,
            const string &home_address,
            const string &email,
            const string &city);
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
        // {
        //     return full_name;
        // }

        const string get_phone_number() const;
        // {
        //     return phone_number;
        // }

        const string get_home_address() const;
        // {
        //     return home_address;
        // }

        const string get_email() const;
        // {
        //     return email;
        // }

        const string get_city() const;
        // {
        //     return city;
        // }

        // extract data from map
        void from_map(std::map<string, string> map);
        // {
        //     User::from_map(map);
        //     this->full_name = map["full_name"];
        //     this->phone_number = map["phone_number"];
        //     this->home_address = map["home_address"];
        //     this->email = map["email"];
        //     this->city = map["city"];
        // }

        // convert data to map
        std::map<string, string> to_map_member() const;
        // {
        //     std::map<string, string> map = to_map_member();
        //     map.emplace("full_name", this->full_name);
        //     map.emplace("phone_number", this->phone_number);
        //     map.emplace("home_address", this->home_address);
        //     map.emplace("email", this->email);
        //     map.emplace("city", this->city);
        //     return map;
        // }

        // Serialization function for Member class
        void serialize(json &j) const;
        // {
        //     j = {
        //         {"username", username},
        //         {"password", password},
        //         {"full_name", full_name},
        //         {"phone_number", phone_number},
        //         {"home_address", home_address},
        //         {"email", email},
        //         {"city", city}
        //         // Add more member variables to serialize
        //     };
        // }

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