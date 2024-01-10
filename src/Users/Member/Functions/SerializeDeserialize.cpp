#include "../member.hpp"

Skill* Users::Member::get_skill_by_name(string &skillName)
{
    for (auto &skill : skills)
    {
        if (skill.get_skill_name() == skillName)
        {
            return new Skill(skill);
        }
    }
    return nullptr;
}

// Serialization function for Member class
void Users::Member::serialize(json &j) const
{
    j = {
        {"username", username},
        {"password", password},
        {"full_name", full_name},
        {"phone_number", phone_number},
        {"home_address", home_address},
        {"email", email},
        {"city", city},
        {"credit", credit}
        // Add more member variables to serialize
    };

    // Creating a JSON array for skills
    json skillsArray;
    for (const auto &skill : skills)
    {
        json singleSkill;
        singleSkill["skill_name"] = skill.get_skill_name();
        singleSkill["consumed_per_hour"] = skill.get_consumed_per_hour();
        singleSkill["minimum_rating"] = skill.get_mininum_rating();
        skillsArray.push_back(singleSkill);
    }

    // Adding the skills array to the JSON object
    j["skills"] = skillsArray;

    // Creating a JSON array for available times
    json availableTimesArray;
    for (const Period &availableTime : available_times)
    {
        json singleAvailableTime;
        singleAvailableTime["start_time"] =  availableTime.get_start_time_string();
        singleAvailableTime["end_time"] =  availableTime.get_end_time_string();
        availableTimesArray.push_back(singleAvailableTime);
    }

    // Adding the available times array to the JSON object
    j["available_times"] = availableTimesArray;

    json blockListArray;
    for (const auto &block_member : block_list)
    {
        blockListArray.push_back(block_member);
    }
    j["block_list"] = blockListArray;

    // Available Jobs
    json availableJobsArray;
    for (const auto &availableJob : available_jobs)
    {
        json singleAvailableJob;
        singleAvailableJob["supporter_name"] = availableJob.get_supporter_name();
        singleAvailableJob["skill_name"] = availableJob.get_skill()->get_skill_name();
        singleAvailableJob["start_time"] = availableJob.get_start_time();
        singleAvailableJob["end_time"] = availableJob.get_end_time();
        availableJobsArray.push_back(singleAvailableJob);
    }
    j["available_jobs"] = availableJobsArray;
}

// Deserialization function for Member class
void Users::Member::deserialize(const json &j)
{
    username = j.at("username").get<string>();
    password = j.at("password").get<string>();
    full_name = j.at("full_name").get<string>();
    phone_number = j.at("phone_number").get<string>();
    home_address = j.at("home_address").get<string>();
    email = j.at("email").get<string>();
    city = j.at("city").get<string>();
    credit = j.at("credit").get<float>();
    // Deserialize other member variables

    // Deserialize skills array
    if (j.find("skills") != j.end())
    {
        const json &skillsArray = j.at("skills");
        for (const auto &skill : skillsArray)
        {
            std::string skillName = skill.at("skill_name").get<std::string>();
            float consumedPerHour = skill.at("consumed_per_hour").get<float>();
            float minimumRating = skill.at("minimum_rating").get<float>();
            skills.emplace_back(skillName, consumedPerHour, minimumRating);
        }
    }

    // Deserialize available times array
    if (j.find("available_times") != j.end())
    {
        const json &availableTimesArray = j.at("available_times");
        for (const auto &availableTime : availableTimesArray)
        {
            std::string startTime = availableTime.at("start_time").get<std::string>();
            std::string endTime = availableTime.at("end_time").get<std::string>();
            available_times.emplace_back(startTime, endTime);
        }
    }

    // Deserialize available jobs array (not implemented yet)
    // Desirialize block list array
    if (j.find("block_list") != j.end())
    {
        const json &blockListArray = j.at("block_list");
        for (const auto &block_member : blockListArray)
        {
            block_list.push_back(block_member);
        }
    }

    // Deserialize available jobs array
    if (j.find("available_jobs") != j.end())
    {
        const json &availableJobsArray = j.at("available_jobs");
        std::string startTime = "";
        std::string endTime = "";
        for (const auto &availableJob : availableJobsArray)
        {
            std::string supporterName = availableJob.at("supporter_name").get<std::string>();
            std::string skillName = availableJob.at("skill_name").get<std::string>();
            startTime = availableJob.at("start_time").get<std::string>();
            endTime = availableJob.at("end_time").get<std::string>();

            Skill* skill = get_skill_by_name(skillName);            
            available_jobs.emplace_back(supporterName, startTime, endTime, skill);
            delete skill;
            
        }
    }

}