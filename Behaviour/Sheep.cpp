//
// Created by Xi Sung on 2020/11/27.
//

#include "Sheep.h"
#include "vector"
using std::vector;

int * Sheep::GetColor() {
    return color;
}

float * Sheep::NextMove(CritterInterface critter) {
//    CritterInterface * critters = Environment::GetInstance().CritterInterface();
    std::vector<CritterInterface> critters = critter.Detect();
//    int number_critters = sizeof(critters) / sizeof(critters[0]);
    int number_critters = critters.size();
    float average_direction[2] = {0.0, 0.0};

    for (int i = 0; i < number_critters; i++) {
        float * current_direction = critters[i].GetDirection();
        average_direction[0] += current_direction[0];
        average_direction[1] += current_direction[1];
    }

    average_direction[0] /= number_critters;
    average_direction[1] /= number_critters;

    return average_direction;
}