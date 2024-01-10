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

/*HostReview::HostReview(int &hostRating){
    this->hostRating = hostRating;
}

SupporterReview::SupporterReview(int &skillRating, int supporterRating){
    this->skillRating = skillRating;
    this->supporterRating = supporterRating;
}*/

//getter
const string Review::get_comment() const{
    return comment;
}
/*const int HostReview::get_host_rating() const{
    return host_rating;
}*/

