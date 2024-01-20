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
    };

};

#endif // USER_HPP