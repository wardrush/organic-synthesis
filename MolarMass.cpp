// MolarMass.cpp
// This program should loop through the csv file Atomic Masses.csv and sum the masses of elements

#include <fstream>
#include <iostream>
#include <string>

int main() {

double runningSum;
double atmMass;
double atmNum;
std::string identifier; //Make this value the value from the SMILE
std::string symbol, name;
std::ifstream elementInfo("AtomicMasses.csv"); //Specifying file to be opened as variable elementInfo


if (elementInfo.good()) {
	while (getline(elementInfo, symbol, ',')) {
		getline(elementInfo, atmMass, ',');
		getline(elementInfo, name, ',');
		getline(elementInfo, atmNum, ' ');
	}
	if (symbol == identifier) {
		runningSum += atmMass;
	}
}
		else {} //null

}

//Make an array or find some way of storing these values to search through
	
elementInfo.close();

}

else {
	std::cout << "Error\n";
}

std::cout << runningSum;

return 0;

}





