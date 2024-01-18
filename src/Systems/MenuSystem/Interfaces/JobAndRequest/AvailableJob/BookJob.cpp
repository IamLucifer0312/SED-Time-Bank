#include "../../../MenuSystem.hpp"

void MenuSystem::book_job() {
    string supporterName;
    std::cout << "Enter supporter username: ";
    std::getline(std::cin, supporterName);
    
    // need error handling here:
    int arraySize = userSystem.database.find_member(supporterName).get_available_jobs().size();
    vector<AvailableJob> availableJobs = userSystem.database.find_member(supporterName).get_available_jobs();
    for (size_t i = 0; i < arraySize; i++)
    {
        std::cout << i + 1 << std::endl;
        availableJobs[i].showInfo();
        std::cout << std::endl;
    }
    int answer = prompt_choice(1, arraySize);
    size_t sizeValue = static_cast<size_t>(answer);

    float totalCredit = availableJobs[sizeValue - 1].get_skill().get_consumed_per_hour() * availableJobs[sizeValue - 1].get_available_time().get_duration_by_hour();

    if( totalCredit > userSystem.get_current_member().get_credit()){
        std::cout << "You don't have enough credit to book this job.\n";
        std::cout << "You need " << totalCredit << " credit to book this job.\n";
        std::cout << "Your current credit is " << userSystem.get_current_member().get_credit() << std::endl;
        std::cout << "0. Back\n";
        switch(prompt_choice(0, 0)) {
            case 0:
                break;
        }
        return;
    }

    make_request(availableJobs[sizeValue - 1], availableJobs[sizeValue - 1].availableTime);
    std::cout << "Successfully booked job.\n";
    std::getline(std::cin, supporterName);
};