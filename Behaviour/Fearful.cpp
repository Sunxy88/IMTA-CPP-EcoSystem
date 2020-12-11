//
// Created by Xi Sung on 2020/11/27.
//

#include "Fearful.h"
#include "../Environment.h"
#include "vector"
#define FEAR_THRESHOLD 6

float * Fearful::NextMove(BaseCritter* critter) {
    std::vector<BaseCritter> detected_critters = critter->Detect(&vector<BaseCritter>());
    int number = detected_critters.size();
    const float* direction = critter->GetDirection();
    const float* position = critter->GetPosition();
    float dir[2];
    if (number > FEAR_THRESHOLD) {
        dir[0] = position[0] * 2 - direction[0];
        dir[1] = position[1] * 2 - direction[1];
    }
    return dir;
}

int * Fearful::GetColor() {
    return color;
}