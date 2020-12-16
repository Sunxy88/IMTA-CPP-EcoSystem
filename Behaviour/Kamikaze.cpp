//
// Created by Xi Sung on 2020/11/27.
//
#include <math.h>
#include "float.h"
#include "limits.h"
#include "vector"
#include "Kamikaze.h"

using namespace std;

Kamikaze::Kamikaze(){}
Kamikaze::~Kamikaze(){}
int * Kamikaze::GetColor() {
    return color;
}

void Kamikaze::NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    int num = critters.size();
    
    // We don't need to check if there is no critters around
    if(num > 0){
    
    const float * nearest_critter = critters.at(0)->GetDirection();
    const float * current_position = critter->GetPosition();
    float distance = getDistance(current_position, nearest_critter);
    float temporary_distance;
    
    for (int i = 0; i < num; ++i) { 
        float temporary_position[2] = {critters[i]->GetPosition()[0], critters[i]->GetPosition()[1]};
        temporary_distance = getDistance(current_position, temporary_position);
        if (temporary_distance <= distance) {
            
             float orientation = atan2(temporary_position[1] - current_position[1], temporary_position[0] - current_position[0]);
            critter->GetModifiableDir()[0] = cos(orientation);
            critter->GetModifiableDir()[1] = sin(orientation);
           
            distance = temporary_distance;
        }
    }
    }
    
    
}

float Kamikaze::getDistance(const float * p1, const float * p2) {
    return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
}

BehaviourInterface* Kamikaze::clone(){
    return new Kamikaze(*this);
}