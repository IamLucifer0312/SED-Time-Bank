#include "admin.hpp"

Users::Admin::Admin() : User("admin", "") {}
Users::Admin::Admin(const std::string &password) : User("admin", password) {}