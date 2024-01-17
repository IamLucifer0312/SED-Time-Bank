#include "../Member.hpp"

void Users::Member::calculate_avg_host_rating()
{
    double sum = 0;
    for (auto &review : host_reviews)
    {
        sum += review.get_host_rating();
    }
    avg_host_rating = sum / host_reviews.size();
}

void Users::Member::calculate_avg_supporter_rating()
{
    double sum = 0;
    for (auto &review : supporter_reviews)
    {
        sum += review.get_supporter_rating();
    }
    avg_supporter_rating = sum / supporter_reviews.size();
}