//
// Created by Michael on 12/16/2016.
//

#include <iostream>
#include "BondList.h"

BondList::BondList()
{

}

BondList::BondList(size_t size)
{
    for(size_t i = 0; i < size; i++)
        addPoint();
}

void BondList::addPoint()
{
    central.push_back(nullptr);
}

void BondList::formBond(size_t posC, size_t con)
{
    formBond(posC, con, 1);
}
//Add a bond to the end of the existing bond list
void BondList::formBond(size_t posC, size_t con, size_t bondValue)
{
    NodePtr tmpPtr;
    for(size_t i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            tmpPtr = central[posC];
            if(central[posC] == nullptr)
            {
                central[posC] = new Node;
                tmpPtr = central[posC];
            }
            else
            {
                while(tmpPtr->next != nullptr)
                    tmpPtr = tmpPtr->next;
                tmpPtr->next = new Node;
                tmpPtr = tmpPtr->next;
            }
        }
        else
        {
            tmpPtr = central[con];
            if(central[con] == nullptr)
            {
                central[con] = new Node;
                tmpPtr = central[con];
            }
            else
            {
                while(tmpPtr->next != nullptr)
                    tmpPtr = tmpPtr->next;
                tmpPtr->next = new Node;
                tmpPtr = tmpPtr->next;
            }
        }
        tmpPtr->bVal = bondValue;
        tmpPtr->next = nullptr;
        if(i == 0)
            tmpPtr->pos = con;
        else
            tmpPtr->pos = posC;
    }
}

void BondList::removePoint(size_t posC)
{
    while(central[posC] != nullptr)
        breakBond(posC,central[posC]->pos);
    central.erase(central.begin() + posC);
}

void BondList::breakBond(size_t posC, size_t con)
{
    NodePtr tmpPtr, backPtr;
    for(size_t i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            tmpPtr = central[posC];
            backPtr = central[posC];
        }

        else
        {
            tmpPtr = central[con];
            backPtr = central[con];
        }

        if(tmpPtr == nullptr)
            throw noSuchBond();
        else
        if(i == 0)
        {
            if(tmpPtr->pos == con)
            {
                central[posC] = tmpPtr->next;
                delete tmpPtr;
            } else
            {
                tmpPtr = tmpPtr->next;
                while(tmpPtr->pos != con)
                {
                    tmpPtr = tmpPtr->next;
                    backPtr = backPtr->next;
                }
            }
        }
        else
        {
            if(tmpPtr->pos == posC)
            {
                central[con] = tmpPtr->next;
                delete tmpPtr;
            } else
            {
                tmpPtr = tmpPtr->next;
                while(tmpPtr->pos != posC)
                {
                    tmpPtr = tmpPtr->next;
                    backPtr = backPtr->next;
                }
            }
        }
        if(tmpPtr->next == nullptr)
            backPtr->next = nullptr;
        else
            backPtr->next = tmpPtr->next;
        delete tmpPtr;
    }
}

void BondList::alterBondValue(size_t posC, size_t con, size_t val)
{
    NodePtr tmpPtr;
    for(size_t i = 0; i < 2; i++)
    {
        if(i == 0)
            tmpPtr = central[posC];
        else
            tmpPtr = central[con];
        if(tmpPtr == nullptr)
            throw noSuchBond();
        else
            while(tmpPtr->next != nullptr)
                tmpPtr = tmpPtr->next;
        tmpPtr->bVal = val;
    }
}

size_t BondList::checkHybrid(size_t pos)
{
    NodePtr  tmpPtr;
    size_t count = 1;
    tmpPtr = central[pos];
    if(tmpPtr == nullptr)
        return 0;
    while(tmpPtr->next != nullptr)
    {
        tmpPtr = tmpPtr->next;
        count++;
    }
    return count;
}