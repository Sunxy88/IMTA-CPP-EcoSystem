//
// Created by Xi Sung on 2020/11/27.
//

#include "Sheep.h"
#include "vector"
using std::vector;

int * Sheep::GetColor() {
    return color;
}

void Sheep::NextMove(CritterInterface* critter, float direction[2], std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    int number = critters.size();
    
    if(number > 0){
    
    float orientation = 0;
    
        // Get the mean of  the orientations to other detected critters
        for (int i = 0; i < number; ++i) {
            orientation += atan(critters.at(i)->GetDirection()[1] / critters.at(i)->GetDirection()[0]);
        }
        orientation /= number;

        // Get opposite angle and store it in direction array
        
        direction[0] = cos(orientation);
        direction[1] = sin(orientation);
    
    }
}

BehaviourInterface* Sheep::clone(){
    return new Sheep(*this);
}