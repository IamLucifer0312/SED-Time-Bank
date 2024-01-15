#include "Review.hpp"

//default constructor
Review::Review() : comment(""){}

HostReview::HostReview(){
    this->hostRating = 0;
}

SupporterReview::SupporterReview(){
    this->skillRating = 0;
    this->supporterRating = 0;
}

//constructor
Review::Review(string &comment){
    this->comment = comment;
}

HostReview::HostReview(string &comment, int &hostRating):Review(comment){
    this->hostRating = hostRating;
}

SupporterReview::SupporterReview(string &comment, int &skillRating, int &supporterRating):Review(comment){
    this->skillRating = skillRating;
    this->supporterRating = supporterRating;
}

//getter

const string Review::get_comment() const{
    return comment;
}

const int HostReview::get_host_rating() const{
    return hostRating;
}

const int SupporterReview::get_supporter_rating() const{
    return supporterRating;
}

const int SupporterReview::get_skill_rating() const{
    return skillRating;
}

//setter

void HostReview::set_host_rating(int &hostRating){
    this-> hostRating = hostRating;
}

void SupporterReview::set_supporter_rating(int &supporterRating){
    this-> supporterRating = supporterRating;
}

void SupporterReview::set_skill_rating(int &skillRating){
    this-> skillRating = skillRating;
}
