//
// Created by Xi Sung on 2020/11/27.
//
#include <math.h>
#include "float.h"
#include "limits.h"
#include "vector"
#include "Kamikaze.h"


Kamikaze::Kamikaze(){}
Kamikaze::~Kamikaze(){}
int * Kamikaze::GetColor() {
    return color;
}

float * Kamikaze::NextMove(CritterInterface *critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    float nearest_critter[2] = {critters[0]->GetDirection()[0], critters[0]->GetDirection()[1]};
    float current_position[2] = {};
    current_position[0] = critter->GetPosition()[0];
    current_position[1] = critter->GetPosition()[1];
    float *result =  {0, 0};
    int num = critters.size();
    if(num > 0) {
        float distance = getDistance(current_position, nearest_critter);
        float temporary_distance;
   
        for (int i = 1; i < num; ++i) {
            float temporary_position[2] = {critters[i]->GetPosition()[0], critters[i]->GetPosition()[1]};
            temporary_distance = getDistance(current_position, temporary_position);
            // Choose the nearest critter
            if (temporary_distance > distance) {
                result[0] = temporary_position[0];
                result[1] = temporary_position[1];
                distance = temporary_distance;
            }
        }
    }

    return result;
}

// Calculate the distance between two coordinate.
float Kamikaze::getDistance(const float * p1, const float * p2) {
    return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
}

BehaviourInterface* Kamikaze::clone(){
    return new Kamikaze(*this);
}