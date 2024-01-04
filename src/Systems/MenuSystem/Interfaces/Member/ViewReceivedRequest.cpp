#include "../../MenuSystem.hpp"
#include <vector>
#include "../../../../Request/Request.hpp"

using std::cout;

void MenuSystem::view_received_request()
{
    vector<Request *> requests_list = this->userSystem.get_current_member().get_received_requests();

    for (Request* request: requests_list) {
        
        cout << "Username: " << request->get_host() << endl;
    }

    cout << "Enter the i of the request you want to accept or reject: ";
}