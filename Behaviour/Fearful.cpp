//
// Created by Xi Sung on 2020/11/27.
//

#include "Fearful.h"
#include "../Environment.h"
#include "vector"
#define FEAR_THRESHOLD 6 // The threshold of run away

float * Fearful::NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    int number = critters.size();
    const float* direction = critter->GetDirection();
    const float* position = critter->GetPosition();
    float dir[2];
    // To the opposite direction
    if (number > FEAR_THRESHOLD) {
        dir[0] = position[0] * 2 - direction[0];
        dir[1] = position[1] * 2 - direction[1];
    }
    return dir;
}

int * Fearful::GetColor() {
    return color;
}