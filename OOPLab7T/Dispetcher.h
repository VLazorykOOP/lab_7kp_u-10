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
	}
	void writeCarToFile() {
		try {
			ofstream fout("Cars.txt");
			for (Car temp : car) {
				fout << temp << endl;
			}
			fout.close();
		}
		catch (exception& e) {
			cout << "Error: " << e.what();
		}
	}
	void writeDriverToFile() {
		try {
			ofstream fout("Drivers.txt");
			for (Driver temp : driver) {
				fout << temp << endl;
			}
			fout.close();
		}
		catch (exception& e) {
			cout << "Error: " << e.what();
		}
	}
	void writeTourToFile() {
		try {
			ofstream fout("Tours.txt");
			for (Tour temp : tour) {
				fout << temp << endl;
			}
			fout.close();
		}
		catch (exception& e) {
			cout << "Error: " << e.what();
		}
	}
	void setCarToDriverToTour() {
		for (Car temp : car) {
			temp.showCar();
		}
		for (Driver temp : driver) {
			temp.showDriver();
		}
		for (Tour temp : tour) {
			temp.showTour();
		}
		int car_id;
		int driver_id;
		int tour_id;
		cout << "Choose Car (id): ";
		while (cin >> car_id) {
			bool f1 = false;
			for (auto it = car.begin(); it != car.end(); ++it) {
				if (it->getId() == car_id && it->getState() == "GOTOVO") {
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
			car_id = 0;
			cout << "Not correct id choose another : ";
		}
		cout << "Choose Driver (id): ";
		driver_id = checkDriver("GOTOV");

		cout << "Choose Tour (id): ";
		while (cin >> tour_id) {
			bool f1 = false;
			for (auto it = tour.begin(); it != tour.end(); ++it) {
				if (it->getId() == tour_id && it->getState() == "NEB") {
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
			tour_id = 0;
			cout << "Not correct id choose another : ";
		}
	
		for (auto it = car.begin(); it != car.end(); ++it) {
			if (it->getId() == car_id) {
				it->setState("BUSY");
				break;
			}
		}
		for (auto it = driver.begin(); it != driver.end(); ++it) {
			if (it->getId() == driver_id) {
				it->setCarId(car_id);
				it->setState("BUSY");
				it->showDriver();
				break;
			}
		}
		for (auto it = tour.begin(); it != tour.end(); ++it) {
			if (it->getId() == tour_id)
			{
				it->setDriverId(driver_id);
				it->setState("B");
				it->showTour();
				break;
			}
		}
		writeCarToFile();
		writeDriverToFile();
		writeTourToFile();
	}
	void cancel_driver(){
		int driver_id;
		cout << "Choose cancelled driver: ";
		cin >> driver_id;
		for (auto it = driver.begin(); it != driver.end(); ++it) {
			if (it->getId() == driver_id)
			{
				it->setState("CANCELLED");
			}
		}
		writeDriverToFile();
	}
	int checkDriver(string state){
		int driver_id;
		while (cin >> driver_id) {
			bool f1 = false;
			for (auto it = driver.begin(); it != driver.end(); ++it) {
				if (it->getId() == driver_id && it->getState() == state) {
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
			driver_id = 0;
			cout << "Not correct id choose another : ";
		}
		return driver_id;
	}
	void setPoznachka(){
		cout << "Choose your driver:";
		int driver_id;
		int car_id;
		driver_id = checkDriver("BUSY");
		for (auto it = tour.begin(); it != tour.end(); ++it) {
			if (it->getId() == driver_id) {
				it->setDriverId(0);
				it->setState("NEB");
				break;
			}
		}
		for (auto it = driver.begin(); it != driver.end(); ++it) {
			if (it->getId() == driver_id) {
				it->setState("GOTOV");
				car_id = it->getCarId();
				it->setCarId(0);
				break;
			}
		}
		for (auto it = car.begin(); it != car.end(); ++it) {
			if (it->getId() == car_id) {
				it->setState("GOTOVO");
				break;
			}
		}
		writeCarToFile();
		writeDriverToFile();
		writeTourToFile();
	}
	void remontZayava() {
		cout << "Choose your driver:";
		int driver_id;
		driver_id = checkDriver("GOTOV");
		int car_id;
		cout << "Choose car_id who broken:";
		cin >> car_id;
		for (auto it = driver.begin(); it != driver.end(); ++it) {
			if (it->getId() == driver_id) {
				it->setZayavka("YE");
			}
		}
		for (auto it = car.begin(); it != car.end(); ++it) {
			if (it->getId() == car_id) {
				it->setState("NAREMONT");
			}
		}
		writeCarToFile();
		writeDriverToFile();
	}
};