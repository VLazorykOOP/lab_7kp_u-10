#pragma once
#include<iostream>
#include<vector>
#include <fstream>
#include<exception>
#include"Car.h"
#include"Driver.h"
#include"Tour.h"
using namespace std;
class Dispetcher {
public:
	vector<Car> car;
	vector<Driver> driver;
	vector<Tour> tour;
	void readCarFromFile() {
		try {
			ifstream fin("Cars.txt");
			int id;
			string marka;
			int number_of_seats;
			string state;
			while (fin >> id >> marka >> number_of_seats >> state) {
				Car temp;
				temp.setCar(id, marka, number_of_seats, state);
				car.push_back(temp);
			}
			fin.close();	
		}
		catch (exception& e) {
			cout << "Error: " << e.what();
		}
		for (Car temp : car) {
			temp.showCar();
		}
	}
	void readDriverFromFile() {
		try {
			ifstream fin("Drivers.txt");
			string firstName;
			string lastName;
			int id;
			int age;
			int drives_count;
			double rate;
			string state;
			string zayavka;
			int car_id;
			while (fin >> id >>car_id>> firstName >> lastName >> age >> drives_count >> rate >> state >> zayavka) {
				Driver temp;
				temp.setDriver(id ,car_id, firstName, lastName, age, drives_count, rate, state, zayavka);
				driver.push_back(temp);
			}
			fin.close();
		}
		catch (exception& e) {
			cout << "Error: " << e.what();
		}
		for (Driver temp : driver) {
			temp.showDriver();
		}
	}
	void readTourFromFile() {
		try {
			ifstream fin("Tours.txt");
			int id;
			int driver_id;
			string tour_name;
			string departure_time;
			string arrival_time;
			string state;
			while (fin >> id >>driver_id>> tour_name >> departure_time >> arrival_time >> state) {
				Tour temp;
				temp.setTour(id,driver_id, tour_name, departure_time, arrival_time, state);
				tour.push_back(temp);
			}
			fin.close();
		}
		catch (exception& e) {
			cout << "Error: " << e.what();
		}
		for (Tour temp : tour) {
			temp.showTour();
		}
	}
	void setCarToDriverToTour() {
		int car_id;
		int driver_id;
		int tour_id;
		cout << "Choose Car (id): ";
		while (cin >> car_id) {
			bool f1 = false;
			for (Car temp : car) {
				if (temp.getState() == "GOTOVO") {
					f1 = true;
					break;
				}
				else {
					continue;
				}
			}
			if (f1) {
				break;
			}
		}
		cout << "Choose Driver (id): ";
		while (cin >> driver_id) {
			bool f1 = false;
			for (Driver temp : driver) {
				if (temp.getState() == "GOTOV") {
					f1 = true;
					break;
				}
				else {
					continue;
				}
			}
			if (f1) {
				break;
			}
		}
		cout << "Choose Tour (id): ";
		while (cin >> tour_id) {
			bool f1 = false;
			for (Tour temp : tour) {
				if (temp.getState() == "NEB") {
					f1 = true;
					break;
				}
				else {
					continue;
				}
			}
			if (f1) {
				break;
			}
		}
	}
};