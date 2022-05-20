#include<iostream>
#include "./Models/Headers/User.h"

#include<map>
#include <cstring>

using namespace std;

map<string, User*>::iterator GetUserIterator(map<string, User*>& users, const string& username) {
    map<string, User*>::iterator it;

    it = users.find(username);

    return it;
}

bool UserExists(map<string, User*>& users, map<string, User*>::iterator it) {
    if(it == users.end()) {
        cout << "Username doesn't exist";
        return false;
    }

    return true;
}

bool Login(map<string, User*>& users, string &nationalId, string &password) {
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

bool Signup(map<string, User*>& users) {
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
    User admin;
    admin.setRole("admin");

    map<string, int> requests;

    requests.insert(make_pair("2022/01/13:12:05_30206120103878_1", 1));
    requests.insert(make_pair("2022/01/12:12:05_30206120103875_1", 1));
    requests.insert(make_pair("2022/01/12:12:06_30206120103876_1", 1));
    requests.insert(make_pair("2022/01/14:12:05_30206120103879_1", 1));

    vector<string> v = admin.PopulateTodayPatients(requests);

    admin.CheckPatients(requests, admin, v);

    admin.EndList(requests, admin, v);

    for (string s : v) {
        cout << s << endl;
    }
}
