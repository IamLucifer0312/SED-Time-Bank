#include <string>
#include <map>

// Check if the file is already included.
#ifndef USER_HPP
#define USER_HPP

using std::string;

namespace Users
{
    class User
    {
    protected:
        string username;
        string password;

    public:
        // default constructor
        User();
        // {
        //     this->username = "";
        //     this->password = "";
        // }

        // constructor
        User(const string &username, const string &password);
        // {
        //     this->username = username;
        //     this->password = password;
        // }

        const string get_username() const;
        // {
        //     return this->username;
        // }

        bool authenticate(const string &pwd) const;
        //     {
        //         return this->password == pwd;
        //     }

        // extract data from map
        virtual void from_map(std::map<string, string> map);
        // {
        //     this->username = map["username"];
        //     this->password = map["password"];
        // }

        // convert data to map
        virtual std::map<string, string> to_map();
        // {
        //     std::map<string, string> map;
        //     map.emplace("username", this->username);
        //     map.emplace("password", this->password);
        //     return map;
        // }
    };

};

#endif // USER_HPP