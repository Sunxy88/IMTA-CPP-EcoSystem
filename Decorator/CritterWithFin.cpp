#include "CritterAccessoryDecorator.h"
#include "CritterWithFin.h"

CritterWithFin::CritterWithFin(CritterAccessoryInterface* component_,float* speedBonus_) : CritterAccessoryDecorator(component_),speedBonus(speedBonus_){}

float CritterWithFin::CalculateSpeed() const override {
    return this->component->CalculateSpeed()*speedBonus;
}

float CritterWithFin::CalculateCollisionResistance() const override {
    return this->component->CalculateCollisionResistance();
}

float CritterWithFin::CalculateCamouflageCapacity() const override {
    return this->component->CalculateCamouflageCapacity();
}