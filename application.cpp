#include<iostream>
#include "./Models/Headers/User.h"
#include "forward_list"

using namespace std;

void SeedData(unordered_map<string, User> &users, list<Request> &requests) {
    User admin;
    User worker;

    Vaccine vacc;

    vacc.UpdateData("Strangeness", "UK", 2);

    admin.setNationalId("1");
    admin.setPassword("123");
    admin.setRole("admin");
    users.insert(make_pair(admin.getNationalId(), admin));

    worker.setNationalId("2");
    worker.setPassword("123");
    worker.setRole("worker");
    users.insert(make_pair(worker.getNationalId(), worker));

    for (int i = 0; i < 8 ; ++i) {
        User u;
        u.setVaccine(vacc);
        u.setRole("user");
        u.setNationalId("3020612010387" + to_string(i));
        u.setPassword("123");

        auto it = Request::CreateRequest(requests, u.getNationalId(), 1, u.getVaccine());
        u.addRequest(it);

        users.insert(make_pair(u.getNationalId(), u));
    }
}

unordered_map<string, User>::iterator GetUserIterator(unordered_map<string, User>& users, const string& username) {
    unordered_map<string, User>::iterator it;

    it = users.find(username);

    return it;
}

bool UserExists(unordered_map<string, User>& users, unordered_map<string, User>::iterator it) {
    if(it == users.end()) {
        cout << "National id doesn't exist in system\n";
        return false;
    }

    return true;
}

User* Login(unordered_map<string, User>& users, string &nationalId, string &password) {
    auto it = GetUserIterator(users, nationalId);

    if(!UserExists(users, it)) {
        return NULL;
    }

    if(it->second.getPassword() != password) {
        cout << "Password incorrect \n";
        return NULL;
    }

    cout << "Logged in successfully \n";
    return &(it->second);
}

bool Signup(unordered_map<string, User>& users) {
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
    users.insert(make_pair(u.getNationalId(), u));

    return true;
}

void PrintWelcomePrompt() {
    cout << "Welcome to the vaccine tracking system" << "\n\n";
    cout << "Choose an option from the following" << "\n\n";
    cout << "1. Login \n";
}

User* LoginWithPrompts(unordered_map<string, User>& users) {
    string nationalId;
    string password;

    cout << "Enter your national ID: ";
    cin >> nationalId;
    cout << "Enter your password: ";
    cin >> password;

    return Login(users, nationalId, password);
}

int main() {
    unordered_map<string, User> users;
    list<Request> requests;
    User* loggedInUser;

    SeedData(users, requests);

    while(true) {
        PrintWelcomePrompt();

        string loginInput;
        cin >> loginInput;

        while (loginInput != "1") {
            cout << "Sorry, invalid input. Please try again. \n";
            cin >> loginInput;
        }

        loggedInUser = LoginWithPrompts(users);

        while (!loggedInUser) {
            loggedInUser = LoginWithPrompts(users);
        }

        cout << "Your role is: " << (*loggedInUser).getRole() << "\n";

        if ((*loggedInUser).getRole() == "admin") {
            int input;
            cout << "1. Delete user data\n2. View user data.\n3. View Requests\n";
            cin >> input;
            if(input == 1) {

                User::DeleteData(users, *loggedInUser, requests);

            } else if(input == 2) {

                for(auto user : users) {
                    User u = user.second;

                    cout << u.getNationalId() << " " << u.getVaccinationStatus() << "\n";
                }

            } else {

                for(auto req : requests) {
                    cout << req.getUserNationalId() << " " << req.getState() << "\n";
                }

            }
        } else if ((*loggedInUser).getRole() == "worker") {
            cout << "Populating your patients data for the day\n";
            vector<Request> v = User::PopulateTodayPatients(requests);
            cout << "Populating data done. Number of patients today is " << v.size() << "\n";

            cout << "Enter the IDs presented to you. When finally done, enter 'n' as an id.\n";
            User::CheckPatients(users, requests, *loggedInUser, v);
            User::EndList(users, requests, *loggedInUser, v);
        } else {
            int numberOfPendingRequests = Request::GetNumberOfUserRequestsWithStatus((*loggedInUser).getRequests(), 1);

            if (numberOfPendingRequests > 0) {
                cout << "You already have pending requests.\n";
            } else {
                cout << "1. Submit request\n";
            }
        }

        cout << "GoodBye!" << endl;
    }
}
