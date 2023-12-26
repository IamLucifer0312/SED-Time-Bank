#include "user.hpp"

// default constructor
Users::User::User()
{
    this->username = "";
    this->password = "";
}

// constructor
Users::User::User(const string &username, const string &password)
{
    this->username = username;
    this->password = password;
}

// get username
const string Users::User::get_username() const
{
    return this->username;
}

// authenticate password
// TODO: send error when password is wrong
bool Users::User::authenticate(const string &pwd) const
{
    return this->password == pwd;
}

// extract data from map
void Users::User::from_map(std::map<string, string> map)
{
    this->username = map["username"];
    this->password = map["password"];
}

// convert data to map
std::map<string, string> Users::User::to_map()
{
    std::map<string, string> map;
    map.emplace("username", this->username);
    map.emplace("password", this->password);
    return map;
}
