#pragma once
#include<iostream>
using namespace std;
class Car {
public:
	int id;
	string marka;
	int number_of_seats;
	string state;
	Car() {
		this->id = 0;
		this->marka ="";
		this->number_of_seats = 0;
		this->state = "";
	}
	~Car() {}
	void setCar(int id, string marka, int number_of_seats,string state) {
		this->id = id;
		this->marka = marka;
		this->number_of_seats = number_of_seats;
		this->state = state;
	}
	void showCar() {
		cout << "====================" << endl;
		cout << "       Car:        " << endl;
		cout << "====================" << endl;
		cout << "id: " << id << endl;
		cout << "Marka: " << marka << endl;
		cout << "Number of seats: " << number_of_seats << endl;
		cout << "State: " << state << endl;
		cout << "====================" << endl;
	}
	friend ostream& operator<<(ostream& out, Car& c) {
		out << c.id << " " << c.marka << " " << c.number_of_seats << " " << c.state;
		return out;
	}
	string getState() {
		return this->state;
	}
	int getId(){
		return this->id;
	}
	void setState(string state) {
		this->state = state;
	}
};