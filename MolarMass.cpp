// MolarMass.cpp
// This program should loop through the csv file Atomic Masses.csv and sum the masses of elements

#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>


int main() {

double runningSum = 0;
std::string identifier; //Make this value the value from the SMILE

std::string symbol, atmMass, name, atmNum;
std::ifstream myfile("C:\Users\Ward Rushton\Documents\Visual Studio 2015\Repos\organic-synthesis\AtomicMasses.csv");

if (myfile.good()) {
while (getline(myfile, symbol, ',')) {
	std::cout << "Symbol: " << symbol << " ";

	getline(myfile, atmMass, ',');
	std::cout << "Atomic Mass: " << atmMass << " ";

	getline(myfile, name, ',');
	std::cout << "name: " << name << " ";

		getline(myfile, atmNum);
	std::cout << "Atomic Number: " << atmNum << " ";
}

//Make an array or find some way of storing these values to search through
	
myfile.close();

}
else std::cout << "Error\n";

_getch();
return 0;

}


