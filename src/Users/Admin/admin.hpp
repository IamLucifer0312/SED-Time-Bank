#include "../User/user.hpp"

// Check if the file is already included.
#ifndef ADMIN_HPP
#define ADMIN_HPP

namespace Users
{
    class Admin : public User
    {
    public:
        Admin() : User("admin", "") {}
        Admin(const string &password) : User("admin", password) {}
    };
} // namespace Users

#endif // ADMIN_HPP