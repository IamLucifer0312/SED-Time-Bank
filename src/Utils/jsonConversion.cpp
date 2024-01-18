#include "JsonConversion.hpp"

// overwrite json functions, will be moved to another file later

void to_json(json &j, const Request &r) {
    j = json{
        {"host", r.get_host()},
        {"supporter", r.get_supporter()},
        {"job", r.get_job()},
        {"work_time", r.get_work_time_object()},
        {"status", static_cast<int>(r.get_status())},
        {"total_credit", r.get_total_credit()}
    };
}

void to_json(json &j, const AvailableJob &h)
{
    j = json{{"supporterName", h.get_supporter_name()},
    {"availableTime", h.get_available_time()},
    {"skill", h.get_skill()}};
}

void to_json(json &j, const Period &p)
{
    j = json{{"start_time", p.get_start_time_string()}, {"end_time", p.get_end_time_string()}};
}

void to_json(json &j, const Skill &s)
{
    j = json{{"skill_name", s.get_skill_name()}, {"consumed_per_hour", s.get_consumed_per_hour()}, {"minimum_rating", s.get_mininum_rating()}};
}

void from_json(const json &j, AvailableJob &job)
{
    string supporterName = j.at("supporterName").get<string>();
    Period availableTime = j.at("availableTime").get<Period>();
    Skill skill = j.at("skill").get<Skill>();
    job = AvailableJob(supporterName, availableTime, skill);
}

void from_json(const json &j, Skill &s)
{
    string skillName = j.at("skill_name").get<string>();
    float consumedPerHour = j.at("consumed_per_hour").get<float>();
    float minimumRating = j.at("minimum_rating").get<float>();
    s = Skill(skillName, consumedPerHour, minimumRating);
}

void from_json(const json& j, Period& p)
{
    string startTime = j.at("start_time").get<string>();
    string endTime = j.at("end_time").get<string>();
    p = Period(startTime, endTime);
};