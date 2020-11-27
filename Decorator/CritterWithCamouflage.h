#include "CritterAccessoryDecorator.h"

class CritterWithCamouflage : public CritterAccessoryDecorator{

private:
    float* camouflageCapacity;

public:
    CritterWithCamouflage(CritterAccessoryInterface* component_,float* camouflageCapacity_)
    float CalculateSpeed();
    float CalculateCollisionResistance();
    float CalculateCamouflageCapacity();

}