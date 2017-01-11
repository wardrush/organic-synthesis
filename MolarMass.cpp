// MolarMass.cpp
// This program should loop through the csv file Atomic Masses.csv and sum the masses of elements

#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>

int main() 
{

	double runningSum = 0, atmMass;
	std::string identifier; //Make this value the value from the SMILE
	identifier = 'H';
	std::string symbol, name, atmNum;
	std::ifstream elementInfo("AtomicMasses.csv"); //Specifying file to be opened as variable elementInfo
	elementInfo.open("");

	if (elementInfo.good()) 
	{
		while (!elementInfo.eof())
		{


			getline(elementInfo, symbol, ',');
			
			//getline(elementInfo, name, ',');
			//getline(elementInfo, atmNum, ' ');

			if (symbol == identifier)
			{
				elementInfo >> atmMass;
				runningSum += atmMass;
			}
			else {} //null
		}
	}
	else {
		std::cerr << "Error/n";
	}
	//Make an array or find some way of storing these values to search through
	
	elementInfo.close();

	//std::cout << runningSum;
	_getch();
	return 0;


}


