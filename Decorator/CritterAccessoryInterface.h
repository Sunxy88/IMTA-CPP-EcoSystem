
#pragma once

#ifndef  CRITTERACCESSORYINTERFACE_H
#define  CRITTERACCESSORYINTERFACE_H_


class CritterAccessoryInterface : public CritterInterface
{
public:
    CritterAccessoryInterface();
    virtual ~CritterAccessoryInterface();
    virtual float CalculateSpeed() = 0;
    virtual float CalculateCollisionResistance() = 0;
    virtual float CalculateCamouflageCapacity() = 0;

};

#endif 
