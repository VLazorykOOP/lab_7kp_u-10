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
			string marka;
			int number_of_seats;
			string state;
			while (fin >> marka >> number_of_seats >> state) {
				Car temp;
				temp.setCar(marka, number_of_seats, state);
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
			int age;
			int drives_count;
			double rate;
			string state;
			string zayavka;
			while (fin >> firstName >> lastName >> age >> drives_count >> rate >> state >> zayavka) {
				Driver temp;
				temp.setDriver(firstName, lastName, age, drives_count, rate, state, zayavka);
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
			string tour_name;
			string departure_time;
			string arrival_time;
			while (fin >> tour_name >> departure_time >> arrival_time) {
				Tour temp;
				temp.setTour(tour_name, departure_time, arrival_time);
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
	}
};