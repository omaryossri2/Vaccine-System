#include "forward_list"
#include "../Headers/Request.h"
#include "ctime"

using namespace std;

Request::Request(const string &userNationalId, int state, const Vaccine &vaccine, char *date) : userNationalId(userNationalId), state(state), vaccine(vaccine), date(date) {

}

list<Request>::iterator Request::CreateRequest(list<Request>& request, string& userNationalId, int state, Vaccine& vaccine) {
    time_t now = time(0);
    char* date = ctime(&now);

    Request r = Request(userNationalId, state, vaccine, date);

    return request.insert(request.end(), r);
}

int Request::GetNumberOfUserRequestsWithStatus(vector<list<Request>::iterator>& requestsIterators, int status) {
    int count = 0;

    for(auto it : requestsIterators) {
        auto req = *it;

        if(req.getState() == status)
            count++;
    }

    return count;
}

void Request::DeleteUserRequestWithStatus(list<Request>& requests, vector<list<Request>::iterator>& requestsIterators, int status) {
    for(auto it : requestsIterators) {
        auto req = *it;

        if(req.getState() == status) {
            requests.erase(it);
            break;
        }
    }
}
