#include "../Member.hpp"

Skill Users::Member::get_skill_by_name(string &skillName)
{
    for (auto &skill : skills)
    {
        if (skill.get_skill_name() == skillName)
        {
            return skill;
        }
    }
    return Skill();
}

Period Users::Member::get_time_by_start_end(string &startTime, string &endTime)
{
    for (auto &availableTime : available_times)
    {
        if (availableTime.get_start_time_string() == startTime && availableTime.get_end_time_string() == endTime)
        {
            return availableTime;
        }
    }
    return Period();
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
    for (Period availableTime : available_times)
    {
        json singleAvailableTime;
        singleAvailableTime["start_time"] = availableTime.get_start_time_string();
        singleAvailableTime["end_time"] = availableTime.get_end_time_string();
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
        singleAvailableJob["skill_name"] = availableJob.get_skill().get_skill_name();
        singleAvailableJob["start_time"] = availableJob.get_available_time().get_start_time_string();
        singleAvailableJob["end_time"] = availableJob.get_available_time().get_end_time_string();
        availableJobsArray.push_back(singleAvailableJob);
    }
    j["available_jobs"] = availableJobsArray;

    // Sent Requests
    json sentRequestsArray;
    for (Request sentRequest : sent_requests)
    {
        json singleSentRequest;
        singleSentRequest["host"] = sentRequest.get_host();

        AvailableJob &job = sentRequest.get_job();

        json singleJob;
        singleJob["supporter_name"] = sentRequest.get_job().get_supporter_name();
        singleJob["skill_name"] = sentRequest.get_job().get_skill().get_skill_name();
        singleJob["start_time"] = sentRequest.get_job().get_available_time().get_start_time_string();
        singleJob["end_time"] = sentRequest.get_job().get_available_time().get_end_time_string();

        singleSentRequest["job"] = singleJob;

        json singleWorkTime;
        singleWorkTime["start_time"] = sentRequest.get_work_time().get_start_time_string();
        singleWorkTime["end_time"] = sentRequest.get_work_time().get_end_time_string();

        singleSentRequest["work_time"] = singleWorkTime;

        singleSentRequest["status"] = static_cast<int>(sentRequest.get_status());
        singleSentRequest["total_credit"] = sentRequest.get_total_credit();
        
        sentRequestsArray.push_back(singleSentRequest);
    }

    j["sent_requests"] = sentRequestsArray;
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

            available_jobs.emplace_back(supporterName, get_time_by_start_end(startTime, endTime), get_skill_by_name(skillName));
        }
    }

    // Deserialize sent requests array
    if (j.find("sent_requests") != j.end())
    {
        const json &sentRequestsArray = j.at("sent_requests");
        for (const auto &sentRequest : sentRequestsArray)
        {
            std::string host = sentRequest.at("host").get<std::string>();

            std::string supporterName = sentRequest.at("job").at("supporter_name").get<std::string>();
            std::string skillName = sentRequest.at("job").at("skill_name").get<std::string>();
            std::string startTime = sentRequest.at("job").at("start_time").get<std::string>();
            std::string endTime = sentRequest.at("job").at("end_time").get<std::string>();
            Period availableTime = Period(startTime, endTime);
            Skill tempSkill = Skill();
            AvailableJob job = AvailableJob(supporterName, availableTime, tempSkill);

            std::string workStartTime = sentRequest.at("work_time").at("start_time").get<std::string>();
            std::string workEndTime = sentRequest.at("work_time").at("end_time").get<std::string>();
            Period workTime = Period(workStartTime, workEndTime);

            Status status = static_cast<Status>(sentRequest.at("status").get<int>());
            float totalCredit = sentRequest.at("total_credit").get<float>();

            sent_requests.emplace_back(host, job, workTime, status, skillName);
        }
    }
}