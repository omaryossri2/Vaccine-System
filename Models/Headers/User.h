#include<iostream>
#include "map"
#include "Vaccine.h"
using namespace std;

class User
{
private:
    string fName;
    string LName;
    string nationalId;
    string password;
    string governate;
    string role;
    char gender;
    int age;
    Vaccine vaccine;

    bool IsAdmin(const User& user);

public:
    //constructors
    User();
    User(string fName, string LName, string nationalId, string password, string governate, string role, char gender, int age, bool vaccinated, Vaccine vaccine, int numOfDoses);

    //methods
//    void ViewData(ArrList<User> users, User user, ArrList<User> Q, ArrList<Vaccine> v); // prints all data by entred by the user with proper messages
    void UpdateData(string fName, string LName, string nationalId, string password, string governate, string role, char gender, int age, bool vaccinated, Vaccine vaccine, int numOfDoses); // updates everything
    void UpdateData_Prompts(); //asks the user which attributes they wish to update and updates them
    void DeleteData(const map<string, User>& users, const User& user);
    void DeleteOne(map<string, User> users, const User& currentUser, const string& nationalId);
    void DeleteAll(map<string, User> users, const User& currentUser);

    //setters
    void setFName(string s) {
        fName = s;
    }
    void setLName(string s) {
        LName = s;
    }
    void setNationalId(string s) {
        nationalId = s;
    }
    void setPassword(string s) {
        password = s;
    }
    void setGovernate(string s) {
        governate = s;
    }
    void setRole(string s) {
        role = s;
    }
    void setGender(char c) {
        gender = c;
    }
    void setAge(int i) {
        age = i;
    }
    void setVaccine(Vaccine v) {
        vaccine = v;
    }

    //getters
    string getFName() {
        return fName;
    }
    string getLName() {
        return LName;
    }
    string getNationalId() {
        return nationalId;
    }
    string getPassword() {
        return password;
    }
    string getGovernate() {
        return governate;
    }
    string getRole() {
        return role;
    }
    char getGender() {
        return gender;
    }
    int getAge() {
        return age;
    }

    Vaccine getVaccine() {
        return vaccine;
    }
};
