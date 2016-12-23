// MolarMass.cpp
// This program should loop through the csv file Atomic Masses.csv and sum the masses of elements
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
//#include <sstream>


int main() 
{
	string line; // Holds the line in the file
	string element; //The variable for the element being searched

	ofstream myfile ("AtomicMasses.csv"); // Opens the file

	if (myfile.is_open())
	{
		while (myfile.good()) // The resources I found online had this. Not quite sure of the nuances, but it seems to work
		{
			getline(myfile, line);// Gets the current line in the file
			if (element == line)
			{
				//Find a way to search through the different columns of a csv file for the atomic mass
			}
		}
	}

		myfile.close();


	else 
	{
		std::cout << "Unable to open file\n";
	}

	return 0;
}
