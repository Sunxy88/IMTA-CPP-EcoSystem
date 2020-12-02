//
// Created by Xi Sung on 2020/11/27.
//

#include "Fearful.h"
#define FEAR_THRESHOLD 6

float * Fearful::NextMove(CritterInterface critter) {
    CritterInterface * detected_critters = critter.Detect();
    int number = sizeof(detected_critters) / sizeof(critter);
    float direction[2] = critter.GetDirection();
    float position[2] = critter.GetPosition();
    if (number > FEAR_THRESHOLD) {
        direction[0] = position[0] * 2 - direction[0];
        direction[1] = position[1] * 2 - direction[1];
    }
    return direction;
}

int * Fearful::GetColor() {
    return color;
}