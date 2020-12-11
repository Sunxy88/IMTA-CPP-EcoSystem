#include "CritterAccessoryDecorator.h"
#include "CritterWithCamouflage.h"

CritterWithCamouflage::CritterWithCamouflage(CritterAccessoryInterface* component_,float camouflageCapacity_) : CritterAccessoryDecorator(component_),camouflageCapacity(camouflageCapacity_){}

float CritterWithCamouflage::CalculateSpeed(){
    return this->component->CalculateSpeed();
}

float CritterWithCamouflage::CalculateCollisionResistance(){
    return this->component->CalculateCollisionResistance();
}

float CritterWithCamouflage::CalculateCamouflageCapacity(){
    return this->component->CalculateCamouflageCapacity()*camouflageCapacity;
}