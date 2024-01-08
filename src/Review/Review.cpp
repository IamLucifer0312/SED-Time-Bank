#include "Review.hpp"

//default constructor
Review::Review() : comment(""){}

HostReview::Review::Review(){
    this->comment = "";
    //this->hostRating = 0;

}


//constructor
Review::Review(string &comment){
    this->comment = comment;
}

//getter
const string Review::get_comment() const{
    return comment;
}
const int Review::HostReview::get_host_rating() const{
    return host_rating;
}

