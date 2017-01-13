//
// Created by Michael on 12/19/2016.
//

#include "Molecule.h"

Molecule::Molecule()
{

}

Molecule::Molecule(std::string s): SMILES(s)
{
    convertToMolecule(SMILES);
}
void Molecule::convertToMolecule(std::string SMILES)
{
    std::vector<Branch> branches;
    branches = filterBranching(SMILES);

    if(atomList.size() == 0)
    {
        simpleSMLIESconverter(branches[0].branchSMILES);
        branches.erase(branches.begin());
    }

    int i = 0;
    while(i < branches.size())
    {
        if(isSimple(branches[i].branchSMILES))
        {
            simpleSMLIESconverter(branches[i].branchSMILES);
            //manually attach
        }
        else
        {
            convertToMolecule(branches[i].branchSMILES);
            //manually attach
        }
        i++;
    }
}
bool Molecule::isSimple(std::string simpleSMILES)
{
    return  true;
}
void Molecule::simpleSMLIESconverter(std::string simpleSMILES)
{
    /* std::string tmpAtom;
    char step;

    for(int i = 0; i < s.size(); i++)
    {
        tmpAtom = "";
        step = s[i];
        if(isalpha(step))
        {
            if(i+1 < s.size())
            {
                if(s[i+1] == 'l' || s[i+1] == 'r')
                {
                    tmpAtom = s[i];
                    tmpAtom += s[i+1];
                }
                else
                    tmpAtom = s[i];
            }
            else
                    tmpAtom = s[i];
            if(isOrganic(tmpAtom))
            {
                Atom a(tmpAtom, 3, size_t(i), 0);
                atomList.push_back(a);
            }
            else
                throw notAnAtom();
            if(tmpAtom.size() > 1)
                i++;
        }
        else if(step == '[') //problems with where the cursor is
        {
            tmpAtom = s[i+1];
            i++;
            while(s[i+1] != ']')
            {
                if(s[i+1] == 'H' && s[i+2] != 'o')
                {
                    for(size_t j = 0; j < s[i+2] - '0'; i++)
                    {
                        Atom a("H", 1, i+1+j, 0);
                        atomList.push_back(a);
                    }
                }
                else if(isalpha(s[i+1]))
                    tmpAtom += s[i+1];
                else if(s[i+1] != ']')
                    tmpAtom = "";
            }
        }
    }*/
}
std::vector<Branch> Molecule::filterBranching(std::string molecule)
{
    std::vector<Branch> tmp;
    tmp.push_back(Branch());
    tmp[0].branchPoint = -1;
    tmp[0].branchSMILES = "CC(=O)C";
    return tmp;
}
void Molecule::fillInHydrogens()
{

}
double Molecule::calculateMolecularWeight()
{
    return 0;
}

bool Molecule::isOrganic(std::string a)
{
    return false;
}
