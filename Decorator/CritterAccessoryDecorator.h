#include "CritterAccessoryInterface.h"

class CritterAccessoryDecorator : public CritterAccessoryInterface

{
protected:
    
    CritterAccessoryInterface* component;

public:
    CritterAccesssoryDecorator(CritterAccessoryInterface* component_ ){}
    //~CritterAccessoryDecorator(){} faut il le mettre ?
    float CalculateSpeed();
    float CalculateCollisionResistance();
    float CalculateCamouflageCapacity();

}