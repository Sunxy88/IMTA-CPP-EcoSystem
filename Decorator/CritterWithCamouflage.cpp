#include "CritterAccessoryDecorator.h"
#include "CritterWithCamouflage.h"

CritterWithCamouflage::CritterWithCamouflage(CritterAccessoryInterface* component_,float* camouflageCapacity_) : CritterAccessoryDecorator(component_),camouflageCapacity(camouflageCapacity_){}

float CritterWithCamouflage::CalculateSpeed() const override {
    return this->component->CalculateSpeed();
}

float CritterWithCamouflage::CalculateCollisionResistance() const override {
    return this->component->CalculateCollisionResistance();
}

float CritterWithCamouflage::CalculateCamouflageCapacity() const override {
    return this->component->CalculateCamouflageCapacity()*camouflageCapacity;
}