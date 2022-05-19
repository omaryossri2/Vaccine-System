#include<iostream>
#include "./Models/Headers/User.h"
#include<map>

using namespace std;


int main() {
    map<string, User*> users;
    User u;
    u.setPassword("123");
    u.setNationalId("1");

    users.insert(make_pair("1", new User()));
    User hamada;
    hamada.AddData();
    cout << users.size();
}

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
}
