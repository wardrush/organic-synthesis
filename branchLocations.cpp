//branchLocations.cpp 
//create two vectors from the given SMILES string that contain the indicies of the opening and closing parentheses

#include <iostream>
#include <vector>
#include <string>

std::vector<int> locations(std::string sample, char branch);

int main()
{
	std::string SMILES; //SMILES goes here

	std::string startBranch = "(";
	std::string endBranch = ")";


	std::vector<int> startResults = locations(SMILES, startBranch);
	std::vector<int> endResults = locations(SMILES, endBranch);

	system("pause");
	return 0;
}

std::vector<int> locations(std::string testString, char testChar)
{
	std::vector<int> characterLocations;
	for (int i = 0; i = > testString.size(); i++);
		if (testString[i] == testChar)
		{
			characterLocations.push_back(i); // gives the indicies of the instances of the chosen characters
		}
	return characterLocations;

}