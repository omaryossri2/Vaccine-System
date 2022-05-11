#include "../Headers/User.h"
#include<iostream>

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
    this->vaccinated = vaccinated;
    this->vaccine = vaccine;
    this->numOfDoses = numOfDoses;
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
    this->vaccinated = false;
    this->numOfDoses = 0;
}
void User:: UpdateData(string fName, string LName, string nationalId, string password, string governate, string role, char gender, int age, bool vaccinated, Vaccine vaccine, int numOfDoses) {
    setFName(fName);
    setLName(LName);
    setNationalId(nationalId);
    setPassword(password);
    setGovernate(governate);
    setRole(role);
    setGender(gender);
    setVaccinated(vaccinated);
    setVaccine(vaccine);
    setNumOfDoses(numOfDoses);
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


void User::DeleteData(ArrList<User> users, User user, ArrList<User> Q, ArrList<Vaccine> v) {
    for (int i = 0; i < users.Length(); i++) {
        if (user.nationalId == users.At(i).nationalId) {
            return;
        }

        if (user.role == "Admin") {


            int input = 0; char check = 0;
            if (users.Length() == 0) {
                cout << "There are no users\n";
            }
            else {
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
                        for (int j = 0; j < users.Length(); j++) {

                            if (n_id == users.At(j).nationalId && user.role == "user") {
                                users.deleteAt(j);
                                if (user.vaccinated) {

                                    user.vaccine.dec_numOfUsers();
                                }

                                //if ( user.numOfDoses < user.vaccine.get_reqDoses()) {

                                //al msh vaccinated hal byb2a 3ndo null fl vaccine wla laa?
                                //if (!user.vaccinated )
                                //for (int j = 0; j < v.Length(); j++) {


                                //}
                            }
                        }
                        break;
                    }
                    case 2:
                    {

                        for (int i = 0; i < users.Length(); i++)
                        {
                            if (users.At(i).role == "user")
                                users.deleteAt(i);
                        }
                        for (int i = 0; i < v.Length(); i++)
                        {
                            v.At(i).setNumOfUsers(users.Length());
                            //di sa7 wla laa?
                        }

                        break;
                    }
                    default:
                    {
                        cout << " you entered invalid number";
                    }

                }
            }
        } else {

            if (user.vaccinated) {

                user.vaccine.dec_numOfUsers();
            }

            users.deleteAt(i);
        }
    }
}
void User::ViewData(ArrList<User> users, User user, ArrList<User> Q, ArrList<Vaccine> v) {
    if (role == "user") {
        cout << "First Name :  " << fName << " \n";
        cout << "Last Name :  " << LName << " \n";
        cout << "National ID:  " << nationalId << " \n";
        cout << "Gender:  " << gender << " \n";
        cout << "Age:  " << age << " \n";
        cout << "Governate:  " << governate << " \n";
        cout << "Gender:  " << gender << " \n";
        if (vaccinated) {
            cout << "You are vaccinated with  :  " << vaccine.getName() << "\n";
            cout << "Number of doses taken  :  " << numOfDoses << "\n";
            cout << "Number of doses required  :  " << vaccine.getReqDoses() << "\n";
        }
        else
        {
            cout << "You are not vaccinated yet " << "\n";
        }
    }
    else {
        int input = 0;
        cout << "---------------------------------------------------" << endl;
        cout << endl;

        cout << "1) view a certain user " << endl;
        cout << "2) view all users " << endl;
        cin >> input;

        if (input == 1) {


            string n_id;
            cout << "---------------------------------------------------" << endl;

            cout << " enter the id of the user you want to delete ";
            cin >> n_id;
            for (int j = 0; j < users.Length(); j++) {

                if (n_id == users.At(j).nationalId && user.role == "user") {

                    cout << "First Name :  " << users.At(j).fName << " \n";
                    cout << "Last Name :  " << users.At(j).LName << " \n";
                    cout << "National ID:  " << users.At(j).nationalId << " \n";
                    cout << "Gender:  " << users.At(j).gender << " \n";
                    cout << "Age:  " << users.At(j).age << " \n";
                    cout << "Governate:  " << users.At(j).governate << " \n";
                    cout << "Gender:  " << users.At(j).gender << " \n";
                    if (vaccinated) {
                        cout << "You are vaccinated with  :  " << users.At(j).vaccine.getName() << "\n";
                        cout << "Number of doses taken  :  " << numOfDoses << "\n";
                        cout << "Number of doses required  :  " << users.At(j).vaccine.getReqDoses() << "\n";
                    }
                    else
                    {
                        cout << "You are not vaccinated yet " << "\n";
                    }

                }
            }
        }
        else if (input == 2) {


            for (int i = 0; i < users.Length(); i++)
            {
                if (users.At(i).role == "user") {

                    cout << "First Name :  " << users.At(i).fName << " \n";
                    cout << "Last Name :  " << users.At(i).LName << " \n";
                    cout << "National ID:  " << users.At(i).nationalId << " \n";
                    cout << "Gender:  " << users.At(i).gender << " \n";
                    cout << "Age:  " << users.At(i).age << " \n";
                    cout << "Governate:  " << users.At(i).governate << " \n";
                    cout << "Gender:  " << users.At(i).gender << " \n";
                    if (vaccinated) {
                        cout << "You are vaccinated with  :  " << users.At(i).vaccine.getName() << "\n";
                        cout << "Number of doses taken  :  " << numOfDoses << "\n";
                        cout << "Number of doses required  :  " << users.At(i).vaccine.getReqDoses() << "\n";
                    }
                    else
                    {
                        cout << "You are not vaccinated yet " << "\n";
                    }
                }
            }
        }
    }
}