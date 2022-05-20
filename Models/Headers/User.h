#pragma once

#include<iostream>
#include "Vaccine.h"
#include "unordered_map"
#include "queue"
#include "list"
#include "Request.h"

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
    vector<list<Request>::iterator> requestPointers;

    static bool IsAdmin(const User& user);

public:
    //constructors
    User();
    User(string fName, string LName, string nationalId, string password, string governate, string role, char gender, int age, bool vaccinated, Vaccine vaccine, int numOfDoses);

    //methods
    void AddData();
//    void ViewData(ArrList<User> users, User user, ArrList<User> Q, ArrList<Vaccine> v); // prints all data by entred by the user with proper messages
    void UpdateData(string fName, string LName, string nationalId, string password, string governate, string role, char gender, int age, bool vaccinated, Vaccine vaccine, int numOfDoses); // updates everything
    void UpdateData_Prompts(); //asks the user which attributes they wish to update and updates them
    void DeleteData(unordered_map<string, User>& users, const User& user);
    void DeleteOne(unordered_map<string, User>& users, const User& currentUser, const string& nationalId);
    void DeleteAll(unordered_map<string, User>& users, const User& currentUser);
    static void CheckPatients(unordered_map<string, User>& users, list<Request>& requests, User& u, vector<Request>& v);
    static void EndList(unordered_map<string, User>& users, list<Request>& requests, const User& u, vector<Request>& v);
    static vector<Request> PopulateTodayPatients(list<Request>& requests);

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
    void setVaccine(Vaccine& v) {
        vaccine = v;
    }

    void addRequest(list<Request>::iterator request) {
        requestPointers.push_back(request);
    }

    void deleteRequest(list<Request>::iterator request) {
        auto it = std::find(requestPointers.begin(), requestPointers.end(), request);

        if (it != requestPointers.end()) {
            requestPointers.erase(it);
        }
    }

    //getters
    string getFName() {
        return fName;
    }
    string getLName() {
        return LName;
    }
    string& getNationalId() {
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

    Vaccine& getVaccine() {
        return vaccine;
    }

    vector<list<Request>::iterator>& getRequests() {
        return requestPointers;
    }
};
