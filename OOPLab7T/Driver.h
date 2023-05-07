#pragma once
#include<iostream>
using namespace std;
class Driver {
public:
	int id;
	string firstName;
	string lastName;
	int age;
	int drives_count;
	double rate;
	string state;
	string zayavka;
	int car_id;
	Driver() {
		this->id = 0;
		this->firstName = "";
		this->lastName = "";
		this->age = 0;
		this->drives_count = 0;
		this->rate = 0.0;
		this->state = "";
		this->zayavka = "";
		this->car_id = 0;
	}
	~Driver() {}
	void setDriver(int id, int car_id, string firstName, string lastName, int age, int driver_count, double rate, string state, string zayavka) {
		this->id = id;
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
		this->drives_count = driver_count;
		this->rate = rate;
		this->state = state;
		this->zayavka = zayavka;
		this->car_id = car_id;
	}
	void setZayavka(string zayavka) {
		this->zayavka = zayavka;
	}
	void showDriver() {
		cout << "====================" << endl;
		cout << "       Driver:        " << endl;
		cout << "====================" << endl;
		cout << "id: " <<id << endl;
		cout << "Car_id: " << car_id << endl;
		cout << "FirstName: " << firstName << endl;
		cout << "LastName: " << lastName << endl;
		cout << "Age: " << age << endl;
		cout << "Drives_count: " << drives_count << endl;
		cout << "Rate: " << rate << endl;
		cout << "State: " << state << endl;
		cout << "Zayavka: " << zayavka << endl;
		cout << "====================" << endl;
	}
	friend ostream& operator<<(ostream& out, Driver& d) {
		out << d.id << " " << d.car_id << " " << d.firstName << " " << d.lastName << " " << d.age << " " << d.drives_count << " " << d.rate << " " << d.state << " " << d.zayavka;
		return out;
	}
	int getId() {
		return this->id;
	}
	string getState() {
		return this->state;
	}
	void setCarId(int car_id) {
		this->car_id = car_id;
	}
	int getCarId() {
		return this->car_id;
	}
	void setState(string state) {
		this->state = state;
	}
};