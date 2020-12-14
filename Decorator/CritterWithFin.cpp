#include "CritterAccessoryDecorator.h"
#include "CritterWithFin.h"

CritterWithFin::CritterWithFin(CritterInterface* component_,float speedBonus_) : CritterAccessoryDecorator(component_),speedBonus(speedBonus_){}

float CritterWithFin::CalculateSpeed(){
    return this->component->CalculateSpeed()* speedBonus;
}

float CritterWithFin::CalculateCollisionResistance(){
    return this->component->CalculateCollisionResistance();
}

float CritterWithFin::CalculateCamouflageCapacity(){
    return this->component->CalculateCamouflageCapacity();
}