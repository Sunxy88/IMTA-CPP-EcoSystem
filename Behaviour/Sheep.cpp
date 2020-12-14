//
// Created by Xi Sung on 2020/11/27.
//

#include "Sheep.h"
#include "vector"
using std::vector;

int * Sheep::GetColor() {
    return color;
}

float * Sheep::NextMove(CritterInterface* critter, Environment & env) {
//    CritterInterface * critters = Environment::GetInstance().CritterInterface();
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(env.GetCritters());
//    int number_critters = sizeof(critters) / sizeof(critters[0]);
    int number_critters = critters.size();
    float average_direction[2] = {0.0, 0.0};

    for (int i = 0; i < number_critters; i++) {
        const float * current_direction = critters[i]->GetDirection();
        average_direction[0] += current_direction[0];
        average_direction[1] += current_direction[1];
    }

    average_direction[0] /= number_critters;
    average_direction[1] /= number_critters;

    return average_direction;
}