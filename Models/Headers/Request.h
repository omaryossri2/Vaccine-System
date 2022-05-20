#include<iostream>
#include "map"
#include "unordered_map"
#include "queue"
#include "list"
#include "Vaccine.h"

using namespace std;

class Request {
private:
    string userNationalId;
    int state;
    Vaccine vaccine;
    char* date;

public:
    Request(const string &userNationalId, int state, const Vaccine &vaccine, char *date);

    static int GetNumberOfUserRequestsWithStatus(vector<list<Request>::iterator>& requestsIterators, int status);
    static void DeleteUserRequestWithStatus(list<Request>& requests, vector<list<Request>::iterator>& requestsIterators, int status);
    static list<Request>::iterator CreateRequest(list<Request>& request, string& userNationalId, int state, Vaccine& vaccine);

    string& getUserNationalId() {
        return userNationalId;
    }

    void setUserNationalId(const string &userNationalId) {
        this->userNationalId = userNationalId;
    }

    int getState() const {
        return state;
    }

    void setState(int state) {
        this->state = state;
    }

    const Vaccine &getVaccine() const {
        return vaccine;
    }

    void setVaccine(const Vaccine &vaccine) {
        this->vaccine = vaccine;
    }

    char *getDate() const {
        return date;
    }

    void setDate(char *date) {
        this->date = date;
    }

    ~Request() {
    }
};
