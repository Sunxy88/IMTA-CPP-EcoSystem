#include "CritterAccessoryDecorator.h"
#include "CritterWithShell.h"

CritterWithShell::CritterWithShell(CritterAccessoryInterface* component_,float* speedMalus_) : CritterAccessoryDecorator(component_),speedMalus(speedMalus_),collisionResistance(collisionResistance_{}

float CritterWithShell::CalculateSpeed() const override {
    return this->component->CalculateSpeed()*speedMalus;
}

float CritterWithShell::CalculateCollisionResistance() const override {
    return this->component->CalculateCollisionResistance()*collisionResistance;
}

float CritterWithShell::CalculateCamouflageCapacity() const override {
    return this->component->CalculateCamouflageCapacity();
}