// MolarMass.cpp
// This program should loop through the csv file Atomic Masses.csv and sum the masses of elements

#include <fstream>
#include <iostream>
#include <string>

int main()
{

    double runningSum = 0, atmMass;
    std::string identifier; //Make this value the value from the SMILE
    identifier = 'H';
    std::string symbol, name, atmNum, str;
    std::ifstream elementInfo; //Specifying file to be opened as variable elementInfo
    elementInfo.open("AtomicMasses");

    if (!elementInfo)
    {
        std::cout << "Error reading file\n";
        getline(std::cin, str);
        std::cin.get();
        exit(1);
    }

    while (!elementInfo.eof())
    {
        getline(elementInfo, str, '\n');

        elementInfo >> symbol;
        //getline(elementInfo, name, ',');
        //getline(elementInfo, atmNum, ' ');


        if (symbol == identifier)
        {
            std::cout << "hi";
            elementInfo >> atmMass;
            runningSum += atmMass;
        }
    }
    std::cout << runningSum;

    elementInfo.close();
}
