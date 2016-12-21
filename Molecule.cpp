//
// Created by Michael on 12/19/2016.
//

#include "Molecule.h"

Molecule::Molecule()
{
}

Molecule::Molecule(std::string s)
{
    std::string tmpAtom;
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
}
}

double Molecule::calculateMolecularWeight()
{
    return 0;
}