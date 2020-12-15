//
// Created by Xi Sung on 2020/11/27.
//
#include "memory"
#include "Careful.h"
#include "algorithm"
#include "vector"
#include "../Simulation.h"

using namespace std;

int* Careful::GetColor() {
    return color;
}

// Basic idea of this algorithm :
// calculate the number of critters in 4 quadrants (original point is current position)
// and calculate the sum of distances between the careful critter and the critters in each quadrants.
// Get a score based on the formula:
// score = WEIGHT_DISTANCE * distance + WEIGHT_NUMBER_OF_CRITTERS * number_of_critters;
// Then choose the quadrant whose score is the lowest.
// You can set the weight in Simulation.h
float* Careful::NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    int quadrant1 = 0, quadrant2 = 0, quadrant3 = 0, quadrant4 = 0;
    float distance1 = 0.0, distance2 = 0.0, distance3 = 0.0, distance4 = 0.0;
    float score1 = 0.0, score2 = 0.0, score3 = 0.0, score4 = 0.0;
    const float * current_position = critter->GetPosition();
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    int numberOfCritters = critters.size();

    // Calculate the number of critters and the distance in 4 quadrants
    for (int i = 0; i < numberOfCritters; ++i) {
        const float * nearby_critter = critters[i]->GetPosition();
        float x_difference = nearby_critter[0] - current_position[0];
        float y_difference = nearby_critter[1] - current_position[1];
        float distance = getDistance(current_position, nearby_critter);

        if (x_difference > 0 && y_difference > 0) {
            quadrant1 += 1;
            distance1 += distance;
        } else if (x_difference > 0 && y_difference > 0) {
            quadrant2 += 1;
            distance2 += distance;
        } else if (x_difference < 0 && y_difference < 0) {
            quadrant3 += 1;
            distance3 += distance;
        } else if (x_difference > 0 && y_difference < 0) {
            quadrant4 += 1;
            distance4 += distance;
        }
    }

    score1 = WEIGHT_DISTANCE * distance1 + WEIGHT_NUMBER_OF_CRITTERS * quadrant1;
    score2 = WEIGHT_DISTANCE * distance2 + WEIGHT_NUMBER_OF_CRITTERS * quadrant2;
    score3 = WEIGHT_DISTANCE * distance3 + WEIGHT_NUMBER_OF_CRITTERS * quadrant3;
    score4 = WEIGHT_DISTANCE * distance1 + WEIGHT_NUMBER_OF_CRITTERS * quadrant4;

    float min_quadrant = std::min(score4, std::min(score3, std::min(score2,score1)));
    float * direction = critter->GetDirection();
    // Go to the quadrant where there are the least critters.
    if (min_quadrant == score1) {
        direction[0] = current_position[0] + 10;
        direction[1] = current_position[1] + 10;
    } else if (min_quadrant == score2) {
        direction[0] = current_position[0] - 10;
        direction[1] = current_position[1] + 10;
    } else if (min_quadrant == score3) {
        direction[0] = current_position[0] - 10;
        direction[1] = current_position[1] - 10;
    } else {
        direction[0] = current_position[0] + 10;
        direction[1] = current_position[1] - 10;
    }
    return direction;
}

float Careful::getDistance(const float * p1, const float * p2) {
    return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
}
