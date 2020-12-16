//
// Created by Xi Sung on 2020/11/27.
//

#include "Sheep.h"
#include "vector"
using std::vector;


Sheep::Sheep(){}
Sheep::~Sheep(){}

int * Sheep::GetColor() {
    return color;
}

void Sheep::NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    int number = critters.size();
    
    if(number > 0){
    
    float orientation = 0;
    
        // Get the mean of  the orientations to other detected critters
        for (int i = 0; i < number; ++i) {
            orientation += atan2(critters.at(i)->GetDirection()[1] , critters.at(i)->GetDirection()[0]);
        }
        orientation /= number;

        // Get opposite angle and store it in direction array
        
        critter->GetModifiableDir()[0] = cos(orientation);
        critter->GetModifiableDir()[1] = sin(orientation);
    
    }
}

BehaviourInterface* Sheep::clone(){
    return new Sheep(*this);
}