#pragma once

#include "string"
using namespace std;

class Vaccine
{
private:
    int numOfUsers;
    string name;
    string country;
    int reqDoses;

public:
    //constructors
    Vaccine();
    Vaccine(int numOfUsers, string name, string country, int reqDoses);

    void setName(string s) {
        name = s;
    }
    void setCountry(string s) {
        country = s;
    }
    void setReqDoses(int i) {
        reqDoses = i;
    }

    //getters
    string getName() {
        return name;
    }
    string getCountry() {
        return country;
    }
    int getReqDoses() {
        return reqDoses;
    }

    //methods
    void UpdateData( string name, string country, int reqDoses);
};