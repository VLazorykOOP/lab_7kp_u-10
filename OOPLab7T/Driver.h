#pragma once
#include<iostream>
using namespace std;
class Driver {
public:
	string firstName;
	string lastName;
	int age;
	int drives_count;
	double rate;
	string state;
	string zayavka;
	Driver() {
		this->firstName = "";
		this->lastName = "";
		this->age = 0;
		this->drives_count = 0;
		this->rate = 0.0;
		this->state = "";
		this->zayavka = "";
	}
	~Driver() {}
	void setDriver(string firstName, string lastName, int age, int driver_count, double rate, string state, string zayavka) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
		this->drives_count = driver_count;
		this->rate = rate;
		this->state = state;
		this->zayavka = zayavka;
	}
	void setZayavka(string zayavka) {
		this->zayavka = zayavka;
	}
	void showDriver() {
		cout << "====================" << endl;
		cout << "       Driver:        " << endl;
		cout << "====================" << endl;
		cout << "FirstName: " << firstName << endl;
		cout << "LastName: " << lastName << endl;
		cout << "Age: " << age << endl;
		cout << "Drives_count: " << drives_count << endl;
		cout << "Rate: " << rate << endl;
		cout << "State: " << state << endl;
		cout << "Zayavka: " << zayavka << endl;
		cout << "====================" << endl;
	}

};