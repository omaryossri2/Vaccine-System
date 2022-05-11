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

    //setters
    void setNumOfUsers(int i) {
        numOfUsers = i;
    }
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
    int getNumOfUsers() {
        return numOfUsers;
    }
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
    void dec_numOfUsers() {
        numOfUsers--;
    }
    void UpdateData(int numOfUsers, string name, string country, int reqDoses);
};