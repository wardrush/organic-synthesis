//This class is meant to provide a shell for functions that are meant for implementation in
//classes that are yet to be fully functional.
#include <string>
#include <vector>
#include <iostream>

struct Branch
{
    std::string branchSMILES; // The SMILES representation of the branch
    int branchPoint = -1; // index of the point where the branch connects to the parent branch
    // value is -1 if parent branch
};

//pre: molecule is a valid SMILES notation i.e. CC(CCC(C)=O)C which is 5-methyl-2-oxohexane

//post: a vector<Branch> is returned that contains each chain and the point it branches off of
//i.e. [CCC, -1], [CCC(C)=O, 1]
std::vector<Branch> filterBranching(std::string molecule);
std::vector<int> locations(std::string sample, char testChar);
int findClosestPrevEndpoint(int currentIndex, std::vector<int> endResults);

int main()
{
    std::vector<Branch> branches;
    branches = filterBranching("CC(CCC(C)=O)CCC(C)C(C(C)C)C"); //for testing

    for(int i = 0; i < branches.size(); i++)
        std::cout << branches[i].branchSMILES << ", " << branches[i].branchPoint << "\n"; //outputs all the items of the vector,
	//each on a new line
	/*Expected output
	_________________
	CCCCCCC, -1
	CCC(C)=O, 1
	C, 4
	C(C)C, 5
	_________________
	*/
	system("pause");
	return 0;
}

std::vector<Branch> filterBranching(std::string molecule) // molecule = SMILES representation of molecule
{
    std::vector<Branch> tmp;
	std::string tmpBranch; //a dummy for you to concatenate on to
    //your code here

	//your SMILES string variable is the molecule variable this function is passed

	char startBranch = '(';
	char endBranch = ')';


	std::vector<int> startResults = locations(molecule, startBranch);
	std::vector<int> endResults = locations(molecule, endBranch);

	/* You currently have stored, given the example string Start Points of S<2,6,15,19,21> and End Points of E<8,11,17,23,25>
	The first thing you need to do is figure out what is outside any parenthesis and concatenate those together. So a skeleton of
	that would look like
	________________________________________________________________________________________________________-
	int iterator = 0;
	bool isOutside = true;
	std::string outside; // a temporary variable to hold the portion of SMILES outside of parenthesis in an instance
	int degreesOfParenthesis = 0; // tells you how many levels of parenthesis you are in
	while(iterator < molecule.size)
	{
		outside = "";

		//the objective is to locate the substrings of the main branch(anyhing outside parenthesis) and push them together
		//in this case you want to add CC + CCC + C + C by the end of the loop so when you go from 0 to 1 degreesOfParenthesis
		//you want the take the substring of the SMILES that starts immediately after the prior endpoint, or 0 if there is no prior
		//endpoint and have it span the right amount of characters by using the eq. startPoint - endPoint - 1 for the length of char
		//argument in the substring function. i.e. outside = molecule.substr(indexOfPriorEndpoint + 1, startPoint - endPoint - 1)
		//I'll have written a helper function called findClosestPrevEndpoint that will return the indexOfPriorEndpoint you need
		//first in the substr function. The only other thing you need to test for is the end of the string where you can just substring
		//from molecule.substr(indexOfPriorEndpoint + 1) without a second argument because if you do not specify it goes to the end.

		//Substring and concatenating example:

		std::string a = "cornwall", b;
		b = a.substr(4) // b = "wall"
		b = a.substrin(3, 2) // b = "nw"
		b += a.substr(0,4) // b = "nwcorn"


		//set isOutside to false when degrees is > 0 and true when degrees > 0

		tmpBranch += outside;
		iterator++;
	}

	tmp[0].branchpoint = -1;
	tmp[0].branchSMILES = tmpBranch;
	___________________________________________________________________________________________
	*/

    //Hint
    tmp[0].branchPoint = -1; // tmp[0] is accessing the vector tmp at the index of 0,
    // aka the starting index. the period is accessing the scope of the struct and both
    // branchPoint and branchSMILES can be accessed and mutated like any other variable in this way
    tmp[0].branchSMILES = "CC(=O)C";

    // look at http://www.cplusplus.com/reference/string/string/ for more functions
    return tmp;
}

std::vector<int> locations(std::string sample, char testChar) //replaced testString w/ sample, names of variables here should be the
	//same as when the function is declared above
{
	std::vector<int> characterLocations;
	for (int i = 0; i < sample.size(); i++)
	{
		if (sample[i] == testChar)
		{
			characterLocations.push_back(i); // gives the indicies of the instances of the chosen characters
		}
	}
	return characterLocations;
}

int findClosestPrevEndpoint(int currentIndex, std::vector<int> endResults) // function returns 0 if there are no prior endpoints, otherwise it returns the index
	// of the closest prior ')'
{
	if(endResults[0] > currentIndex)
		return 0;
	for(int i = 0; i < endResults.size(); i++)
		if(endResults[i] < currentIndex && (i == endResults.size() - 1 || endResults[i+1] > currentIndex))
		   return endResults[i];
	return -1;
}
