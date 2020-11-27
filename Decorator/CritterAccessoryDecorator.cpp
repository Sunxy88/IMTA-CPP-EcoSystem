#include "CritterAccessoryDecorator.h"
#include "CritterAccessoryInterface.h"

CritterAccessoryDecorator::CritterAccessoryDecorator(CritterAccessoryInterface* component_ ) : component(component_){}

float CritterAccessoryDecorator::CalculateSpeed() const override {
    return this->component->CalculateSpeed();
}

float CritterAccessoryDecorator::CalculateCollisionResistance() const override {
    return this->component->CalculateCollisionResistance();
}

float CritterAccessoryDecorator::CalculateCamouflageCapacity() const override {
    return this->component->CalculateCamouflageCapacity();
}