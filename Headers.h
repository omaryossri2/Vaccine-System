#pragma once
#include<iostream>
#include "ArrList.h"
#include <map>
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
	bool vaccinated;
	Vaccine vaccine;
	int numOfDoses;

public:
	//constructors
	User();
	User(string fName, string LName, string nationalId, string password, string governate, string role, char gender, int age, bool vaccinated, Vaccine vaccine, int numOfDoses);
	
	//methods
	void ViewData(ArrList<User> users, User user, ArrList<User> Q, ArrList<Vaccine> v); // prints all data by entred by the user with proper messages
	void UpdateData(string fName, string LName, string nationalId, string password, string governate, string role, char gender, int age, bool vaccinated, Vaccine vaccine, int numOfDoses); // updates everything
	void UpdateData_Prompts(); //asks the user which attributes they wish to update and updates them
	void DeleteData(ArrList<User> users, User user, ArrList<User> Q, ArrList<Vaccine> v); // allows the user to set all its attributes to null
	
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
	void setVaccinated(bool b) {
		vaccinated = b;
	}
	void setVaccine(Vaccine v) {
		vaccine = v;
	}
	void setNumOfDoses(int i) {
		numOfDoses = i;
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
	bool getVaccinated() {
		return vaccinated;
	}
	Vaccine getVaccine() {
		return vaccine;
	}
	int getNumOfDoses() {
		return numOfDoses;
	}		
};
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