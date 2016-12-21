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
    friend std::ostream& operator<<(std::ostream&, const Molecule&);
    std::string SMILES;
    std::vector<Atom> atomList;
    BondList bonds;
    bool isOrganic(std::string a) {
        return false;
    }

    bool isAtom(std::string a) {
        return false;
    }

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
