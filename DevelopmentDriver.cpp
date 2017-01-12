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
    branches = filterBranching("");

    for(int i = 0; i < branches.size(); i++)
        std::cout << branches[i].branchSMILES << ", " << branches[i].branchPoint << "/n";
}

std::vector<Branch> filterBranching(std::string molecule)
{
    std::vector tmp;
    //do things
    return tmp;
}
