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
    size_t position; // stores what number the atom is in the molecule
    size_t hybridization; // stores the hybridization of the atom, a value of 3 is sp3,
// 3 is sp2 and so forth
    bool allylic; //True if in an allylic position, false otherwise
    bool benzylic;// True if in an benzylic position, false otherwise
    int formalCharge; // Records the formal charge of the atom
public:
    //default constructor
    Atom(): position(0), element("C"), hybridization(3), allylic(false), benzylic(false),
    formalCharge(0){}
    //alt constructor
    Atom(std::string e, size_t p, size_t h, int f): element(e), hybridization(h),
    position(p), formalCharge(f), allylic(false), benzylic(false){}
    //Element accessor
    std::string getElement(){return  element;}
    //Hybridization accessor
    size_t getHybrid(){return  hybridization;}
    //Allylic accessor
    bool isAllylic(){return  allylic;}
    //Benzylic accessor
    bool isBenzylic(){return  benzylic;}
    //formalCharge accessor
    int getFormalCharge(){return  formalCharge;}
    // position accessor
    size_t getPos(){return  position;}
    // hybriization mutator
    void setHybrid(size_t h) {hybridization = h;}
    // position mutator
    void setPos(size_t p) {position = p;}
};

#endif //ORGOMATIC_ATOM_H
