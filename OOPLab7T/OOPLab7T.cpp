#include <iostream>
#include <clocale>
#include <fstream>
#include <vector>
#include"Tour.h"
#include "Car.h"
#include"Dispetcher.h"
using namespace std;
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
            Dispetcher d;
            d.readCarFromFile();
            d.readDriverFromFile();
            d.readTourFromFile();
            d.setCarToDriverToTour();
            break;
        }
        case '3': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '4');
}

