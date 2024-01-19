#include "User.hpp"

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

