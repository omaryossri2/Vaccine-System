#include "../Headers/Vaccine.h"
using namespace std;

Vaccine::Vaccine() {
    this->numOfUsers = 0;
    this->name = "";
    this->country = "";
    this->reqDoses = 0;
}

Vaccine::Vaccine(int numOfUsers, string name, string country, int reqDoses) {
    this->numOfUsers = numOfUsers;
    this->name = name;
    this->country = country;
    this->reqDoses = reqDoses;
}

void Vaccine::UpdateData(int numOfUsers, string name, string country, int reqDoses) {
    setNumOfUsers(numOfUsers);
    setName(name);
    setCountry(country);
    setReqDoses(reqDoses);
}