#include <iostream>
#include <clocale>
#include <fstream>
#include <vector>
#include"Tour.h"
#include "Car.h"
#include"Dispetcher.h"
using namespace std;

void Dispetcher_t();

int main()
{
    char ch = '4';
    do {
        cout << "Choose who are you :" << endl;
        cout << "1. Dispetcher" << endl;
        cout << "2. Driver" << endl;
        cout << "3. Exit" << endl;
        cout << " >>> ";
        ch = cin.get();
        cin.get();
        switch (ch) {
        case '1': {
            Dispetcher_t();
            break;
        }
        case '3': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '4');
}

void Dispetcher_t()
{
    Dispetcher d;
    d.readCarFromFile();
    d.readDriverFromFile();
    d.readTourFromFile();

    char ch = '3';
    do {
        cout << "Choose option :" << endl;
        cout << "1. Set Car to the Driver to the Route." << endl;
        cout << "2. Cancel Driver." << endl;
        cout << "3. Forward to Main Menu." << endl;
        cout << " >>> ";
        ch = cin.get();
        cin.get();
        switch (ch) {
        case '1': {
            d.setCarToDriverToTour();
            break;
        }
        case '2': {
            d.cancel_driver();
            break;
        }
        case '3':
        {
            main();
        }
        }
        ch = cin.get();
    } while (ch != '3');
}

