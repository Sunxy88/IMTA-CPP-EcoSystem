//
// Created by Xi Sung on 2020/11/27.
//
#include <math.h>
#include "float.h"
#include "limits.h"
#include "Kamikaze.h"

int * Kamikaze::GetColor() {
    return color;
}

float * Kamikaze::NextMove(CritterInterface critter) {
    CritterInterface * critters = critter.Detect();
    float nearest_critter[2] = critters[0]->GetPosition();
    float current_position[2] = critter->GetPosition();
    float distance = getDistance(current_position, nearest_critter);
    float temporary_distance;
    int num = sizeof(critters) / sizeof(critters[0]);

    for (int i = 1; i < num; ++i) {
        float * temporary_position = critters[i].GetPosition();
        temporary_distance = getDistance(current_position, temporary_position);
        if (temporary_distance > distance) {
            nearest_critter = temporary_position;
            distance = temporary_distance;
        }
    }

    return nearest_critter;
}

float getDistance(float * p1, float * p2) {
    return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5)
}