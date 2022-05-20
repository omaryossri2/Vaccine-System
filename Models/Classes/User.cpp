#include "../Headers/User.h"
#include<iostream>
#include "map"
#include "string"
#include <vector>
#include "unordered_map"
#include "queue"
#include "list"
#include "string.h"

using namespace std;

User::User(string fName,string LName,string nationalId,string password,string governate,
           string role,char gender,int age,bool vaccinated,Vaccine vaccine,int numOfDoses) {
    this->fName = fName;
    this->LName = LName;
    this->nationalId = nationalId;
    this->password = password;
    this->governate = governate;
    this->role = role;
    this->gender = gender;
    this->age = age;
    this->vaccine = vaccine;
}
User::User() {
    this->fName = "";
    this->LName = "";
    this->nationalId = "";
    this->password = "";
    this->governate = "";
    this->role = "";
    this->gender = 'o';
    this->age = 0;
}

void User::AddData() {
    string s;
    char c;
    int i;
    bool b;
    cout << "Welcome to the vaccine system" << endl;
    cout << "Fill this form" << endl;
    cout << "-----------------------------" << endl;

    cout << "Please enter first name : ";
    cin >> s; setFName(s);

    cout << "Please enter last name : ";
    cin >> s; setLName(s);

    cout << "Please enter password : ";
    cin >> s; setPassword(s);

    cout << "Please enter governate : ";
    cin >> s; setNationalId(s);

    cout << "Please enter gender (m/f) : ";
    cin >> c; setGender(c);

    cout << "Please enter age (whole number) : ";
    cin >> i; setAge(i);

}
void User:: UpdateData(string fName, string LName, string nationalId, string password, string governate, string role, char gender, int age, bool vaccinated, Vaccine vaccine, int numOfDoses) {
    setFName(fName);
    setLName(LName);
    setNationalId(nationalId);
    setPassword(password);
    setGovernate(governate);
    setRole(role);
    setGender(gender);
    setVaccine(vaccine);
}
void User::UpdateData_Prompts() {
    char wish;
    int choice;
    string s;
    cout << "Do you wish to update any attributes? (y/n) \n";
    cin >> wish;
    while(wish == 'y') {
        cout << "PRESS 1 To change first name \n";
        cout << "PRESS 2 To change last name \n";
        cout << "PRESS 3 To change password \n";
        cout << "PRESS 4 To change governate \n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter new first name : ";
                cin >> s;
                setFName(s);
                break;
            case 2:
                cout << "Enter new last name : ";
                cin >> s;
                setLName(s);
                break;
            case 3:
                cout << "Enter new password : ";
                cin >> s;
                setPassword(s);
                break;
            case 4:
                cout << "Enter new governate : ";
                cin >> s;
                setGovernate(s);
                break;
        }
        cout << "Values updated successflly \n";
        cout << "Do you wish to update anything else (y/n)? \n";
        cin >> wish;
    }
}


void User::DeleteData(map<string, User*>& users, const User& user) {
    if (IsAdmin(user)) {
        int input = 0;

        if (users.empty()) {
            cout << "There are no users\n";
        } else {
            cout << "---------------------------------------------------" << endl;
            cout << endl;

            cout << "1) Delete a certain user " << endl;
            cout << "2) Delete all users " << endl;
            cin >> input;


            switch (input) {
                case 1:
                {
                    string n_id;
                    cout << "---------------------------------------------------" << endl;

                    cout << " enter the id of the user you want to delete ";
                    cin >> n_id;
                    DeleteOne(users, user, n_id);
                    break;
                }
                case 2:
                {
                    DeleteAll(users, user);
                    break;
                }
                default:
                {
                    cout << " you entered invalid number";
                }

            }
        }
    } else {
        DeleteOne(users, user, user.nationalId);
    }
}
void User::DeleteOne(map<string, User*>& users, const User& currentUser, const string& nationalId) {
    std::map<string, User*>::iterator it;

    if(!IsAdmin(currentUser) && currentUser.nationalId != nationalId) {
        cout  << "You don't have enough permissions to delete another user\n";
        return;
    }

    it = users.find(nationalId);

    if(it == users.end()) {
        cout << "User Doesn't Exist\n";
        return;
    }

    users.erase(it);
    cout << "User with national id: " << nationalId << " deleted successfully\n";
}

void User::DeleteAll(map<string, User*>& users, const User& currentUser) {
    if(!IsAdmin(currentUser)) {
        cout << "You are not authorized to delete all users\n";
        return;
    }

    int count = users.size();

    users.clear();

    cout << "Deleted " << count << " users successfully\n";
}

bool User::IsAdmin(const User& user) {
    cout  << "Current user role is " << user.role << endl;

    if(user.role != "admin") {
        return false;
    }

    return true;
}

void User::CheckPatients(map<string, int>& requests, User& u, vector<string>& v)
{
    // di htb2a fl main bns2al al admin kol shwya lw 3ayz ydakhal users anhom gom
    if (IsAdmin(u)) {

        string nid;
        char ans;
        vector<string>::iterator it;

        while (true) {
            cout << "Enter The National ID of The Patient: ";
            cin >> nid;

            cout << "Is the national id entered: " << nid << " correct? ";
            cin >> ans;

            if (tolower(ans) == 'n')
            {
                cout << "Please RE-enter National Id";
                continue;
            }

            it = std::find(v.begin(), v.end(), nid);
            if(it != v.end()) {
                v.erase(it);
                //delete pending status in unorderedmap
                //add fulfilled status in unorderedmap

                cout << "Patient Fulfilled" << endl;
            } else {
                cout << "This Patient Is Not Due Today" << endl;
                continue;
            }

            cout << "Are there other Patients For Today? ";
            cin >> ans;

            if (tolower(ans) == 'n')
            {
                break;
            }
        }
    }
}

vector<string> User::PopulateTodayPatients(map<string, int>& requests) {
    vector<string> list1;
    map<string, int>::iterator it;

    for (it = requests.begin(); it != requests.end(); it++) {
        if (list1.size() == 20)
            break;

        vector<string> splitRequest = SplitRequestKey(const_cast<string &>(it->first));
        string status = splitRequest.at(2);

        if (status.compare("1") == 0) {
            list1.push_back(splitRequest.at(1));
        }
    }

    return list1;
}

void User::EndList(const map <string, int>& requested, const User& u, vector<string>& v)
{
    //di htb2a fl main abl ml program y2fl bnshel al fl list w nzbt al status bta3hom
    if (IsAdmin(u)) {
        char ans;
        vector<string>::iterator it;
        cout << "Are you sure there are no other patients today? ";
        cin >> ans;

        if (tolower(ans) == 'n')
        {
            return;
        }

        for (const string& s : v) {
            //delete pending status in unorderedmap
            //add missed status in unorderedmap

            cout << "Marking as missed: " << s << endl;
        }

        v.clear();
    }
}


vector<string> User::SplitRequestKey(string& key) {
    vector<string> s;

    char keyChar[key.length() + 1];
    strcpy(keyChar, key.c_str());

    char *token = strtok(keyChar, "_");

    int i = 0;

    while (token != NULL) {
        s.emplace_back(token);
        token = strtok(NULL, "_");
    }

    return s;
}

//void User::ViewData(map<string, User*>& users, User& user, ArrList<User> Q, ArrList<Vaccine> v) {
//    if (role == "user") {
//        cout << "First Name :  " << fName << " \n";
//        cout << "Last Name :  " << LName << " \n";
//        cout << "National ID:  " << nationalId << " \n";
//        cout << "Gender:  " << gender << " \n";
//        cout << "Age:  " << age << " \n";
//        cout << "Governate:  " << governate << " \n";
//        cout << "Gender:  " << gender << " \n";
//        if (vaccinated) {
//            cout << "You are vaccinated with  :  " << vaccine.getName() << "\n";
//            cout << "Number of doses taken  :  " << numOfDoses << "\n";
//            cout << "Number of doses required  :  " << vaccine.getReqDoses() << "\n";
//        }
//        else
//        {
//            cout << "You are not vaccinated yet " << "\n";
//        }
//    }
//    else {
//        int input = 0;
//        cout << "---------------------------------------------------" << endl;
//        cout << endl;
//
//        cout << "1) view a certain user " << endl;
//        cout << "2) view all users " << endl;
//        cin >> input;
//
//        if (input == 1) {
//
//
//            string n_id;
//            cout << "---------------------------------------------------" << endl;
//
//            cout << " enter the id of the user you want to delete ";
//            cin >> n_id;
//            for (int j = 0; j < users.Length(); j++) {
//
//                if (n_id == users.At(j).nationalId && user.role == "user") {
//
//                    cout << "First Name :  " << users.At(j).fName << " \n";
//                    cout << "Last Name :  " << users.At(j).LName << " \n";
//                    cout << "National ID:  " << users.At(j).nationalId << " \n";
//                    cout << "Gender:  " << users.At(j).gender << " \n";
//                    cout << "Age:  " << users.At(j).age << " \n";
//                    cout << "Governate:  " << users.At(j).governate << " \n";
//                    cout << "Gender:  " << users.At(j).gender << " \n";
//                    if (vaccinated) {
//                        cout << "You are vaccinated with  :  " << users.At(j).vaccine.getName() << "\n";
//                        cout << "Number of doses taken  :  " << numOfDoses << "\n";
//                        cout << "Number of doses required  :  " << users.At(j).vaccine.getReqDoses() << "\n";
//                    }
//                    else
//                    {
//                        cout << "You are not vaccinated yet " << "\n";
//                    }
//
//                }
//            }
//        }
//        else if (input == 2) {
//
//
//            for (int i = 0; i < users.Length(); i++)
//            {
//                if (users.At(i).role == "user") {
//
//                    cout << "First Name :  " << users.At(i).fName << " \n";
//                    cout << "Last Name :  " << users.At(i).LName << " \n";
//                    cout << "National ID:  " << users.At(i).nationalId << " \n";
//                    cout << "Gender:  " << users.At(i).gender << " \n";
//                    cout << "Age:  " << users.At(i).age << " \n";
//                    cout << "Governate:  " << users.At(i).governate << " \n";
//                    cout << "Gender:  " << users.At(i).gender << " \n";
//                    if (vaccinated) {
//                        cout << "You are vaccinated with  :  " << users.At(i).vaccine.getName() << "\n";
//                        cout << "Number of doses taken  :  " << numOfDoses << "\n";
//                        cout << "Number of doses required  :  " << users.At(i).vaccine.getReqDoses() << "\n";
//                    }
//                    else
//                    {
//                        cout << "You are not vaccinated yet " << "\n";
//                    }
//                }
//            }
//        }
//    }
//}