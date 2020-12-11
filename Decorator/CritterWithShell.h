#include "CritterAccessoryDecorator.h"

class CritterWithShell : public CritterAccessoryDecorator{

private:
    float speedMalus;
    float collisionResistance;

public:
    CritterWithShell(CritterAccessoryInterface* component_,float speedMalus_,float collisionResistance_);
    float CalculateSpeed() override;
    float CalculateCollisionResistance() override;
    float CalculateCamouflageCapacity() override;

};