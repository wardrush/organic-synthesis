//
// Created by Michael on 12/19/2016.
//

#include "Molecule.h"
#include <cmath>

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
            if(atomList.size() > 0)
                bonds.formBond(atomList.size() - 1, atomList.size() - branches[i].branchPoint);
        }
        else
        {
            convertToMolecule(branches[i].branchSMILES);
            //manually attach
            if(atomList.size() > 0)
                bonds.formBond(atomList.size() - 1, atomList.size() - branches[i].branchPoint);
        }
        i++;
    }
    fillInHydrogens();
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
                Atom a(tmpAtom, atomList.size(), 3, 0);
                atomList.push_back(a);
                bonds.addPoint();
                if(atomList.size() > 0)
                    bonds.formBond(atomList.size() - 1, atomList.size() - 2);
            }
            else
                throw notAnAtom();
            if(tmpAtom.size() > 1)
                i++;
        }
        else if(step == '[') //[NH2+]
        {
            tmpAtom = simpleSMILES[i+1];
            i++;
            int charge = 0;
            while(simpleSMILES[i+1] != ']')
            {
                if(simpleSMILES[i+1] == '+' || simpleSMILES[i+1] == '-')
                {
                    if(isdigit(simpleSMILES[i+2]))
                        charge = simpleSMILES[i+2] - '0';
                    else
                        charge = 1;
                    if(simpleSMILES[i+1] == '-')
                        charge *= -1;
                }
                if(simpleSMILES[i+1] == 'H' && simpleSMILES[i+2] != 'o')
                {
                    //do nothing for now
                }
                else if(isalpha(simpleSMILES[i+1]))
                    tmpAtom += simpleSMILES[i+1];
                i++;
            }
            Atom a(tmpAtom, atomList.size(), 3, charge);
            atomList.push_back(a);
            bonds.addPoint();
            if(atomList.size() > 0)
                bonds.formBond(atomList.size() - 1, atomList.size() - 2);
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
    for(size_t i = 0; i < atomList.size(); i++)
    {
        //the hybrid stored in the atom is the hybrid it is supposed to be while the bonds store what it currently is
        if(bonds.checkHybrid(i) < atomList[i].getHybrid())
        {
            double numH = atomList[i].getHybrid() - bonds.checkHybrid(i) + std::abs(atomList[i].getFormalCharge());
            for(int j = 0; j < numH; j++)
            {
                Atom a("H", atomList.size(), 0, 0);
                atomList.push_back(a);
                bonds.addPoint();
                bonds.formBond(i, atomList.size() - 1);
            }
        }
    }
}
double Molecule::calculateMolecularWeight()
{
    return 0;
}

bool Molecule::isOrganic(std::string a)
{
    return true;
}
