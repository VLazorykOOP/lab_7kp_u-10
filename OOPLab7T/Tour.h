#pragma once
#include<iostream>
using namespace std;
class Tour {
public:
	string tour_name;
	string departure_time;
	string arrival_time;
	Tour() {
		this->tour_name = "";
		this->departure_time = "";
		this->arrival_time = "";
	}
	~Tour() {}
	void setTour(string tour, string depature_t,string arrival_t) {
		this->tour_name = tour;
		this->departure_time = depature_t;
		this->arrival_time = arrival_t;
	}
	void showTour() {
		cout << "====================" << endl;
		cout << "       Tour:        " << endl;
		cout << "====================" << endl;
		cout << "Name: " << tour_name << endl;
		cout << "Departue time: " << departure_time << endl;
		cout << "Arrival time: " << arrival_time << endl;
		cout << "====================" << endl;
	}
};