#include "../User/User.hpp"
#include "../../../nlohmann/json.hpp"

using json = nlohmann::json;
using std::string;

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

        // serialize and deserialize
        void serialize(json &j) const;
        void deserialize(const json &j);

    };
} // namespace Users

#endif // ADMIN_HPP