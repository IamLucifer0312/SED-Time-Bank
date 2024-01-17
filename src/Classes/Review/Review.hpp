#include <string>
#include <cstring>

using std::string;

// Check if the file is already included
#ifndef REVIEW_HPP
#define REVIEW_HPP

class Review {
protected:
    string comment;
    
public:
    //default constructor
    Review();

    //constructor
    Review(string &comment);

    // getter
    const string get_comment() const;
    
};

class HostReview : public Review {
    private:
        int hostRating;

    public:
        //default constructor
        HostReview();

        //constructor
        HostReview(string &comment, int &hostRating);

        // getter
        const int get_host_rating() const;

        // setter
        void set_host_rating(int &hostRating);
};

class SupporterReview : public Review {
    private:
        int skillRating;
        int supporterRating;

    public:
        //default constructor
        SupporterReview();

        //constructor
        SupporterReview(string &comment, int &skillRating, int &supporterRating);

        // getter
        const int get_supporter_rating() const;
        const int get_skill_rating() const;
        // setter
        void set_supporter_rating(int &supporterReview);
        void set_skill_rating(int &skillRating);

};


#endif // REQUEST_HPP