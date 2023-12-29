#include "admin.hpp"

Users::Admin::Admin() : User("admin", "") {}
Users::Admin::Admin(const std::string &password) : User("admin", password) {}

// Serialization function for Member class
void Users::Admin::serialize(json &j) const
{
    j = {
        {"username", username},
        {"password", password},
    };
}

// Deserialization function for Member class
void Users::Admin::deserialize(const json &j)
{
    username = j.at("username").get<string>();
    password = j.at("password").get<string>();
}
