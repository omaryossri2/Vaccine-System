#include<iostream>
#include "./Models/Headers/User.h"
#include "forward_list"

using namespace std;

unordered_map<string, User*>::iterator GetUserIterator(unordered_map<string, User*>& users, const string& username) {
    unordered_map<string, User*>::iterator it;

    it = users.find(username);

    return it;
}

bool UserExists(unordered_map<string, User*>& users, unordered_map<string, User*>::iterator it) {
    if(it == users.end()) {
        cout << "Username doesn't exist";
        return false;
    }

    return true;
}

bool Login(unordered_map<string, User*>& users, string &nationalId, string &password) {
    auto it = GetUserIterator(users, nationalId);

    if(!UserExists(users, it)) {
        return false;
    }

    if(it->second->getPassword() != password) {
        cout << "Password incorrect";
        return false;
    }

    cout << "Logged in successfully";
    return true;
}

bool Signup(unordered_map<string, User*>& users) {
    User u;
    string nationalIdInput;

    cout << "Please enter national id: ";
    cin >> nationalIdInput;

    auto it = GetUserIterator(users, nationalIdInput);

    while(UserExists(users, it)) {
        cout << "National Id Already Exists. Please input another one: ";
        cin >> nationalIdInput;
        it = GetUserIterator(users, nationalIdInput);
    }

    u.AddData();
    users.insert(make_pair(u.getNationalId(), &u));

    return true;
}

int main() {
    unordered_map<string, User> users;
    list<Request> requests;
    Vaccine vacc;
    vacc.UpdateData("Astrazeneca", "UK", 1);


    User admin;
    admin.setRole("admin");

    for (int i = 0; i < 8 ; ++i) {
        User u;
        u.setVaccine(vacc);
        u.setRole("admin");
        u.setNationalId("3020612010387" + to_string(i));

        auto it = Request::CreateRequest(requests, u.getNationalId(), 1, u.getVaccine());
        u.addRequest(it);

        users.insert(make_pair(u.getNationalId(), u));
    }

    vector<Request> v = User::PopulateTodayPatients(requests);

    User::CheckPatients(users, requests, admin, v);

    User::EndList(users, requests, admin, v);


    for(auto r : requests) {
        cout << "\n\n\n\n";
        cout << r.getUserNationalId() << " " << r.getState();
    }
}
