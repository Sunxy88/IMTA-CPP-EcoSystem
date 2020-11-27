//
// Created by Xi Sung on 2020/11/27.
//

#include "Sheep.h"
#include "Environment.h"
#include "vector"
using std::vector;

int * Sheep::GetColor() {
    return color;
}

float * Sheep::NextMove(CritterInterface critter) {
    vector<CritterInterface> critters = Environment::GetInstance().CritterInterface();
    float average_direction[2] = {0.0, 0.0};
    int count = 0;

    vector<CritterInterface>::iterator itr;
    for (itr = critters.begin(); itr != critters.end(); critters++) {
        float * current_direction = *itr->GetDirection();
        average_direction[0] += current_direction[0];
        average_direction[1] += current_direction[1];
        count++;
    }

    average_direction[0] /= count;
    average_direction[1] /= count;

    return average_direction;
}