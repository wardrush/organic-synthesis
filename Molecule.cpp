//
// Created by Michael on 12/19/2016.
//

#include "Molecule.h"

Molecule::Molecule()
{
    Branch b;
    b.branchSMILES= "l";
}

Molecule::Molecule(std::string simpleSMILES): SMILES(simpleSMILES)
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
    for(size_t i = 0; i < simpleSMILES.length(); i++)
        if(simpleSMILES[i] == '(')
            return false;
    return true;
}
void Molecule::simpleSMLIESconverter(std::string simpleSMILES)
{
    std::string tmpAtom;
    char step;

    for(int i = 0; i < simpleSMILES.size(); i++)
    {
        tmpAtom = "";
        step = simpleSMILES[i];
        if(isalpha(step))
        {
            if(i+1 < simpleSMILES.size())
            {
                if(simpleSMILES[i+1] == 'l' || simpleSMILES[i+1] == 'r')
                {
                    tmpAtom = simpleSMILES[i];
                    tmpAtom += simpleSMILES[i+1];
                }
                else
                    tmpAtom = simpleSMILES[i];
            }
            else
                    tmpAtom = simpleSMILES[i];
            if(isOrganic(tmpAtom))
            {
                Atom a(tmpAtom, pos, 3, 0);
                atomList.push_back(a);
                pos++;
            }
            else
                throw notAnAtom();
            if(tmpAtom.size() > 1)
                i++;
        }
        else if(step == '[') //problems with where the cursor is
        {
            tmpAtom = simpleSMILES[i+1];
            i++;
            while(simpleSMILES[i+1] != ']')
            {
                if(simpleSMILES[i+1] == 'H' && simpleSMILES[i+2] != 'o')
                {
                    if(isdigit(simpleSMILES[i+2]))
                    {
                        for (size_t j = 0; j < simpleSMILES[i + 2] - '0'; i++) {
                            Atom a("H", pos, 0, 0);
                            atomList.push_back(a);
                            pos++;
                        }
                    }
                    else
                    {
                        Atom a("H", pos, 0, 0);
                        atomList.push_back(a);
                        pos++;
                    }
                }
                else if(isalpha(simpleSMILES[i+1]))
                    tmpAtom += simpleSMILES[i+1];
            }
        }
    }
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
