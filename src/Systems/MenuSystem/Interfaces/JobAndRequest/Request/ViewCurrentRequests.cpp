#include "../../../MenuSystem.hpp"
#include "ViewSentRequest.cpp"
#include "ViewReceivedRequest.cpp"

#include <string>

using std::cin;
using std::cout;

void MenuSystem::view_current_requests()
{
    std::cout << "Which type of request would you like to view ?\n"
              << "1. Sent requests\n"
              << "2. Received requests\n"
              << "0. Back\n";
    switch (prompt_choice(0, 2))
    {
    case 1:
        view_sent_request();
        break;
    case 2:
        view_received_request();
        break;
    case 0:
        break;
    }
}