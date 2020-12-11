
#pragma once

#ifndef  CRITTERACCESSORYDECORATOR_H
#define  CRITTERACCESSORYDECORATOR_H_


#include "CritterAccessoryInterface.h"

class CritterAccessoryDecorator : public CritterAccessoryInterface

{
protected:
    
    CritterAccessoryInterface* component;

public:
    CritterAccessoryDecorator(CritterAccessoryInterface* component_ );
    //~CritterAccessoryDecorator(){} faut il le mettre ?
    virtual float CalculateSpeed() = 0;
    virtual float CalculateCollisionResistance() = 0 ;
    virtual float CalculateCamouflageCapacity() = 0 ;

};

#endif