#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "../../Classes/Review/Review.hpp"

// Check if the file is already included.
#ifndef MENUSYSTEM_HPP
#define MENUSYSTEM_HPP

// INCLUDES
#include "../UserSystem/UserSystem.hpp"

// user classes
#include "../../Users/Users.hpp"

class MenuSystem
{
private:
    bool quit;
    UserSystem userSystem;
    bool loggedIn;
    std::string member_username;

public:
    // constructor
    MenuSystem();

    // prompt user's choice from min to max
    int prompt_choice(unsigned min, unsigned max);

    // main menu loop
    void main_loop();

    // login and register menu
    void login_menu(string role);
    void register_menu();

    // guest menu
    void guest_menu();

    // member menu
    void member_menu();

    // admin menu
    void admin_menu();

    // view supporters for guests
    void guest_view_supporter();

    // show members
    void show_members(string role);
    void show_members_for_city(std::string city);
    void show_members_for_time(std::string startTime, std::string endTime);

    // clear screen method
    void clear_screen();

    void update_member_info(std::string information);

    // interfaces
    void member_view_my_info(std::string information);
    void block_member_interface();

    // check username and change password of members for admin
    void change_new_password(std::string member_username);

    // check username and block user
    void block_member(std::string member_username);
    void unblock_member(std::string member_username);
    bool is_blocked(Users::Member member);

    // find supporter
    void find_supporter_city();
    void find_all_supporter();
    void find_supporter_interface();
    void find_supporter_availableTime();

    // make request
    void make_request(const AvailableJob &job, Period &workTime);

    // view received request
    void view_received_request();

    // view sent request
    void view_sent_request();

    // accept or reject a request
    void accept_or_reject_request(vector<Request> &requests_list);

    // book job
    void book_job(vector<Users::Member> tempSupporterList);

    // check block list for the username
    bool check_block_list(const string member_username);

    // remove_request
    bool remove_request(Request &request, vector<Request> &requests_list);

    // update available job
    void update_available_job();

    // update available time
    void update_available_time();

    // add credit
    void add_credit();

    // view requests
    void view_current_requests();
    void view_approved_requests();

    // review
    void review_supporter(vector<Request> &requests_list);
    void review_host(vector<Request> &requests_list);

    friend class UserSystem;
};

#endif // MENUSYSTEM_HPP