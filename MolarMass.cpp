// MolarMass.cpp
// This program should loop through the csv file Atomic Masses.csv and sum the masses of elements
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
//#include <sstream>


int main() 
{
	std::string line; // Holds the line in the file
	std::string element; //The variable for the element being searched


	//This temporarily allows for an element to be entered for testing. 
	std::cin >> element;
	//This should be removed after testing


	ofstream myfile ("AtomicMasses.csv"); //XKCD Undelclared Identifier

	if (myfile.is_open())
	{
		while (myfile.good()) // The resources I found online had this. Not quite sure of the nuances, but it seems to work
		{
			getline(myfile, line);
			if (std::string::find(element) != 0);
			{
				//Function that finds a certain element in the line (in this case, the third)
				std::string::columnValue;
					for (i = 1, i <= 3, i++);
				{
					std::string::find(",");

				}
				
				
			}
		}
	}
	else 
	{
		std::cout << "Unable to open file\n";
	}
		myfile.close(); //Closes the file
	
	_getch();

	return 0;
