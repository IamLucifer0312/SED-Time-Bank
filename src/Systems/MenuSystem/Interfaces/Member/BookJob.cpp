#include "../../MenuSystem.hpp"

void MenuSystem::book_job() {
    string supporterName;
    std::cout << "Enter supporter username: ";
    std::getline(std::cin, supporterName);
    
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
    make_request(availableJobs[sizeValue - 1], availableJobs[sizeValue - 1].availableTime);
    std::cout << "Successfully booked job.\n";
    std::getline(std::cin, supporterName);
};