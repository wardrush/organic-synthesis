//
// Created by Michael on 12/16/2016.
//

#ifndef ORGOMATIC_BONDLIST_H
#define ORGOMATIC_BONDLIST_H

#include <string>
#include <vector>

//custom error
struct noSuchBond:std::exception{
    char const *what() const noexcept{
        return "That atom had no bonds";
    }
};

class BondList
{
private:
    struct Node
    {
        size_t pos;
        size_t bVal; // bond value, 1 = single bond, 2 = double bond
        Node *next;
    };
    typedef Node *NodePtr;

    std::vector<NodePtr> central; //A list of head pointers representing each atom
public:
    BondList();
    BondList(size_t size);
    void addPoint();
    void formBond(size_t posC, size_t con); //posC is the atom to add the bond to, con is the other atom to connect to
    void formBond(size_t posC, size_t con, size_t bondValue);
    void removePoint(size_t posC);
    void breakBond(size_t posC, size_t con);
    void alterBondValue(size_t posC, size_t con, size_t val); //val is the new value to change to
    size_t checkHybrid(size_t pos);
};


#endif //ORGOMATIC_BONDLIST_H
