//
// Created by Xi Sung on 2020/11/27.
//
#include "memory"
#include "Careful.h"
#include "algorithm"
#include "vector"

using namespace std;

Careful::Careful(){}
Careful::~Careful(){}

void Careful::NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    int number = critters.size();
    
    if(number > 0){
    const float* position = critter->GetPosition();
    float orientation = 0;
    
        // Get the mean of  the orientations to other detected critters
        for (int i = 0; i < number; ++i) {
            orientation += atan2(critters.at(i)->GetPosition()[1] - position[1], critters.at(i)->GetPosition()[0] - position[0]);
        }
        orientation /= number;

        // Get opposite angle and store it in direction array
        orientation += M_PI;
        critter->GetModifiableDir()[0] = cos(orientation);
        critter->GetModifiableDir()[1] = sin(orientation);
    }
}

int * Careful::GetColor() {
    return color;
}

BehaviourInterface* Careful::clone(){
    return new Careful(*this);
}