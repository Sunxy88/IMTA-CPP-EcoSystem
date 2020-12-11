


#include "CritterAccessoryDecorator.h"
#include "CritterAccessoryInterface.h"

CritterAccessoryDecorator::CritterAccessoryDecorator(CritterAccessoryInterface* component_ ) : component(component_){}

float CritterAccessoryDecorator::CalculateSpeed(){
    return this->component->CalculateSpeed();
}

float CritterAccessoryDecorator::CalculateCollisionResistance(){
    return this->component->CalculateCollisionResistance();
}

float CritterAccessoryDecorator::CalculateCamouflageCapacity(){
    return this->component->CalculateCamouflageCapacity();
}