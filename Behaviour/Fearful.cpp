//
// Created by Xi Sung on 2020/11/27.
//

#include "Fearful.h"
#include "../Environment.h"
#include "vector"

Fearful::Fearful(){}
Fearful::~Fearful(){}

void Fearful::NextMove(CritterInterface* critter, float direction[2], std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    int number = critters.size();
    
    const float* position = critter->GetPosition();
    float orientation = 0;
    if (number >= FEAR_THRESHOLD) {
        // Get the mean of  the orientations to other detected critters
        for (int i = 0; i < number; ++i) {
            orientation += atan2(critters.at(i)->GetPosition()[1] - position[1], critters.at(i)->GetPosition()[0] - position[0]);
        }
        orientation /= number;

        // Get opposite angle and store it in direction array
        orientation += M_PI;
        direction[0] = cos(orientation);
        direction[1] = sin(orientation);
    }
}

int * Fearful::GetColor() {
    return color;
}

BehaviourInterface* Fearful::clone(){
    return new Fearful(*this);
}