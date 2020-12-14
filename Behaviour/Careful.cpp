//
// Created by Xi Sung on 2020/11/27.
//
#include "memory"
#include "Careful.h"
#include "algorithm"
#include "vector"

using namespace std;

int* Careful::GetColor() {
    return color;
}

// Basic idea of this algorithm :
// calculate the number of critters in 4 quadrants (original point is current position)
// choose the quadrant where there are least critters
// set the direction to this quadrant.
float* Careful::NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    int quadrant1 = 0, quadrant2 = 0, quadrant3 = 0, quadrant4 = 0;
    const float * current_position = critter->GetPosition();
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    int numberOfCritters = critters.size();

    // Calculate the number of critters in 4 quadrants.
    for (int i = 0; i < numberOfCritters; ++i) {
        const float * nearby_critter = critters[i]->GetPosition();
        float x_difference = nearby_critter[0] - current_position[0];
        float y_difference = nearby_critter[1] - current_position[1];
        if (x_difference > 0 && y_difference > 0) {
            quadrant1 += 1;
        } else if (x_difference > 0 && y_difference > 0) {
            quadrant2 += 1;
        } else if (x_difference < 0 && y_difference < 0) {
            quadrant3 += 1;
        } else if (x_difference > 0 && y_difference < 0) {
            quadrant4 += 1;
        }
    }

    int min_quadrant = std::min(quadrant4, std::min(quadrant3, std::min(quadrant2,quadrant1)));
    float * direction = critter->GetDirection();
    // Go to the quadrant where there are the least critters.
    switch (min_quadrant) {
        case quadrant1 :
            direction[0] = current_position[0] + 10;
            direction[1] = current_position[1] + 10;
            return direction;
        case quadrant2 :
            direction[0] = current_position[0] - 10;
            direction[1] = current_position[1] + 10;
            return direction;
        case quadrant3 :
            direction[0] = current_position[0] - 10;
            direction[1] = current_position[1] - 10;
            return direction;
        case quadrant4 :
            direction[0] = current_position[0] + 10;
            direction[1] = current_position[1] - 10;
            return direction;
        default:
            return direction;
    }
}