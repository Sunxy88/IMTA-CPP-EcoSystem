#include "CritterAccessoryDecorator.h"
#include "CritterInterface.h"

class CritterWithFin : public CritterAccessoryDecorator{

private:
    float speedBonus;

public:
    CritterWithFin(CritterInterface* component_,float speedBonus_);
    float CalculateSpeed();
    float CalculateCollisionResistance();
    float CalculateCamouflageCapacity();

};
