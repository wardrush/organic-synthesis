//
// Created by Michael on 12/19/2016.
//

#ifndef ORGOMATIC_MOLECULE_H
#define ORGOMATIC_MOLECULE_H

#include "Atom.h"
#include "BondList.h"
#include <vector>
#include <string>
#include <iostream>

class Molecule
{
private:
    struct Branch
    {
        std::string branchSMILES; // The SMILES representation of the branch
        int branchPoint; // index of the point where the branch connects to the parent branch
        // value is -1 if parent branch
    };
    friend std::ostream& operator<<(std::ostream&, const Molecule&);
    std::string SMILES;
    std::vector<Atom> atomList;
    BondList bonds;
    bool isOrganic(std::string a);
    std::vector<Branch> filterBranching(std::string molecule);
    void fillInHydrogens();
    void convertToMolecule(std::string SMILES);
    void simpleSMLIESconverter(std::string simpleSMILES);
    bool isSimple(std::string simpleSMILES);


public:
    Molecule();
    Molecule(std::string s);
    double calculateMolecularWeight();
};

inline std::ostream& operator<<(std::ostream &strm, const Molecule &m)
{
    return strm << "This will output the SMILES code";
}

#endif //ORGOMATIC_MOLECULE_H
