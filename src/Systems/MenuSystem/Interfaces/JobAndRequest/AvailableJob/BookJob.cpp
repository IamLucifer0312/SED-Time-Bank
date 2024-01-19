#include "../../../MenuSystem.hpp"

void MenuSystem::book_job(vector<Users::Member> tempSupporterList)
{
    string supporterName;
    bool isFound = false;
    while (!isFound)
    {
        std::cout << "Enter supporter username: ";
        std::getline(std::cin, supporterName);

        // check if supporter exists
        for (auto &supporter : tempSupporterList)
        {
            if (supporter.get_username() == supporterName)
            {
                isFound = true;
                break;
            }
        }

        if (!isFound)
        {
            std::cout << "Supporter not found. Please enter the correct supporter name on the list.\n";
            std::cout << "1. Try again.\n";
            std::cout << "0. Exit.\n";
            switch (prompt_choice(0, 1))
            {
            case 1:
                break;
            case 0:
                return;
            }
        }
    }

    // need error handling here:
    int arraySize = userSystem.database.find_member(supporterName).get_available_jobs().size();
    vector<AvailableJob> availableJobs = userSystem.database.find_member(supporterName).get_available_jobs();
    for (size_t i = 0; i < arraySize; i++)
    {
        std::cout << i + 1 << std::endl;
        availableJobs[i].showInfo();
        std::cout << std::endl;
    }

    std::cout << "Choose a job (number) you would like to book: " << std::endl;
    int answer = prompt_choice(1, arraySize);
    size_t sizeValue = static_cast<size_t>(answer);

    float totalCredit = availableJobs[sizeValue - 1].get_skill().get_consumed_per_hour() * availableJobs[sizeValue - 1].get_available_time().get_duration_by_hour();

    if (totalCredit > userSystem.get_current_member().get_credit())
    {
        std::cout << "You don't have enough credit to book this job.\n";
        std::cout << "You need " << totalCredit << " credit to book this job.\n";
        std::cout << "Your current credit is " << userSystem.get_current_member().get_credit() << std::endl;
        std::cout << "Press any key to continue.\n";
        std::cin.get();
        return;
    }

    make_request(availableJobs[sizeValue - 1], availableJobs[sizeValue - 1].availableTime);
    clear_screen();
    std::cout << "Successfully booked job.\n";
    std::cout << "Press any key to continue.\n";
    std::cin.get();
};