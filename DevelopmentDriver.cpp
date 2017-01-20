//This class is meant to provide a shell for functions that are meant for implementation in
//classes that are yet to be fully functional.
#include <string>
#include <vector>
#include <iostream>

struct Branch
{
    std::string branchSMILES; // The SMILES representation of the branch
    int branchPoint; // index of the point where the branch connects to the parent branch
    // value is -1 if parent branch
};

//pre: molecule is a valid SMILES notation i.e. CC(CCC(C)=O)C which is 5-methyl-2-oxohexane

//post: a vector<Branch> is returned that contains each chain and the point it branches off of
//i.e. [CCC, -1], [CCC(C)=O, 1]
std::vector<Branch> filterBranching(std::string molecule);

int main()
{
    std::vector<Branch> branches;
    branches = filterBranching("CC(CCC(C)=O)CCC(C)C(C(C)C)C");

    for(int i = 0; i < branches.size(); i++)
        std::cout << branches[i].branchSMILES << ", " << branches[i].branchPoint << "\n";
}

std::vector<Branch> filterBranching(std::string molecule)
{
    std::vector<Branch> tmp;
    //your code here

    //Hint#1
    tmp.push_back(Branch()); //adds a Branch struct to the end of the vector
    
    for(int i = 0; i < molecule.size(); i++)
        if(molecule[i] == '(') //accesses each character in the string and sees if it is the ( char
        {
            //do something
        }

    //Hint#2
    tmp[0].branchPoint = -1; // tmp[0] is accessing the vector tmp at the index of 0,
    // aka the starting index. the period is accessing the scope of the struct and both
    // branchPoint and branchSMILES can be accessed and mutated like any other variable in this way
    tmp[0].branchSMILES = "CC(=O)C";

    //Hint#3
    std::string dummy = (molecule.substr(3,8)); // the substr function returns a string where
    // the first value is the starting index in the string and the second value is the number
    // of characters the new string spans
    std::cout << dummy << std::endl;
    std::cout << dummy.erase(2,4) << std::endl;
    dummy += "=O";
    std::cout << dummy << std::endl;
    // look at http://www.cplusplus.com/reference/string/string/ for more functions
    return tmp;
}
