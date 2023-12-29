#include "../User/User.hpp"

// Check if the file is already included.
#ifndef ADMIN_HPP
#define ADMIN_HPP

namespace Users
{
    class Admin : public User
    {
    public:
        // default constructor
        Admin();

        // constructor
        Admin(const string &password);
    };
} // namespace Users

#endif // ADMIN_HPP