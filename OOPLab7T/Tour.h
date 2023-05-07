#pragma once
#include<iostream>
using namespace std;
class Tour {
public:
	int id;
	string tour_name;
	string departure_time;
	string arrival_time;
	string state;
	int driver_id;
	Tour() {
		this->id = 0;
		this->tour_name = "";
		this->departure_time = "";
		this->arrival_time = "";
		this->state = "";
		this->driver_id = 0;
	}
	~Tour() {}
	void setTour(int id, int driver_id, string tour, string depature_t, string arrival_t, string state) {
		this->id = id;
		this->tour_name = tour;
		this->departure_time = depature_t;
		this->arrival_time = arrival_t;
		this->state = state;
		this->driver_id = driver_id;
	}
	void showTour() {
		cout << "====================" << endl;
		cout << "       Tour:        " << endl;
		cout << "====================" << endl;
		cout << "id: " << id<< endl;
		cout << "driver_id: " << driver_id << endl;
		cout << "Name: " << tour_name << endl;
		cout << "Departue time: " << departure_time << endl;
		cout << "Arrival time: " << arrival_time << endl;
		cout << "State: " << state << endl;
		cout << "====================" << endl;
	}
	friend ostream& operator<<(ostream& out, Tour& t) {
		out << t.id << " " << t.driver_id << " " << t.tour_name << " " << t.departure_time << " " << t.arrival_time << " " << t.state;
		return out;
	}
	int getId() {
		return this->id;
	}
	string getState() {
		return this->state;
	}
	void setDriverId(int driver_id) {
		this->driver_id = driver_id;
	}
	void setState(string state) {
		this->state = state;
	}
};