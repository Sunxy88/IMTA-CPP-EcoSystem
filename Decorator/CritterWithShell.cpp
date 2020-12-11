#include "CritterAccessoryDecorator.h"
#include "CritterWithShell.h"

CritterWithShell::CritterWithShell(CritterAccessoryInterface* component_,float speedMalus_,float collisionResistance_) : CritterAccessoryDecorator(component_),speedMalus(speedMalus_),collisionResistance(collisionResistance_){}

float CritterWithShell::CalculateSpeed(){
    return this->component->CalculateSpeed() * speedMalus;
}

float CritterWithShell::CalculateCollisionResistance(){
    return this->component->CalculateCollisionResistance() * collisionResistance ;
}

float CritterWithShell::CalculateCamouflageCapacity(){
    return this->component->CalculateCamouflageCapacity();  
}