//
// Created by Michael on 12/15/2016.
//
#include <string>

#ifndef ORGOMATIC_ATOM_H
#define ORGOMATIC_ATOM_H

class Atom
{
private:
    std::string element; //stores the abbreviation of the atom i.e. "Br"
    size_t hybridization; // stores the hybridization of the atom, a value of 4 is sp3,
// 3 is sp2 and so forth
    bool allylic; //True if in an allylic position, false otherwise
    bool benzylic;// True if in an benzylic position, false otherwise
    int formalCharge; // Records the formal charge of the atom
public:
    //default constructor
    Atom();
    //Element accessor
    std::string getElement();
    //Hybridization accessor
    size_t getHybrid();
    //Allylic accessor
    bool isAllylic();
    //Benzylic accessor
    bool isBenzylic();
    //formalCharge accessor
    int getFormalCharge();
};

#endif //ORGOMATIC_ATOM_H
