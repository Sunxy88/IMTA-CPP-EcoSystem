#include "CritterAccessoryDecorator.h"

class CritterWithFin : public CritterAccessoryDecorator{

private:
    float* speedBonus;

public:
    CritterWithFin(CritterAccessoryInterface* component_,float* speedBonus_)
    float CalculateSpeed();
    float CalculateCollisionResistance();
    float CalculateCamouflageCapacity();

}