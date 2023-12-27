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

        // constructor
        User(const string &username, const string &password);

        // getter methods
        const string get_username() const;

        // authenticate password
        bool authenticate(const string &pwd) const;

        // extract data from map
        virtual void from_map(std::map<string, string> map);

        // convert data to map
        virtual std::map<string, string> to_map();
    };

};

#endif // USER_HPP