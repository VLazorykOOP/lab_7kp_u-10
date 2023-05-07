#pragma once
#include<iostream>
using namespace std;
class Car {
public:
	string marka;
	int number_of_seats;
	string state;
	Car() {
		this->marka ="";
		this->number_of_seats = 0;
		this->state = "";
	}
	~Car() {}
	void setCar(string marka, int number_of_seats,string state) {
		this->marka = marka;
		this->number_of_seats = number_of_seats;
		this->state = state;
	}
	void showCar() {
		cout << "====================" << endl;
		cout << "       Car:        " << endl;
		cout << "====================" << endl;
		cout << "Marka: " << marka << endl;
		cout << "Number of seats: " << number_of_seats << endl;
		cout << "State: " << state << endl;
		cout << "====================" << endl;
	}
};