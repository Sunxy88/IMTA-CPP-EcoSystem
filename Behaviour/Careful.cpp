//
// Created by Xi Sung on 2020/11/27.
//
#include "memory"
#include "Careful.h"
#include "algorithm"
#include "vector"
#include "../Simulation.h"

using namespace std;

Careful::Careful(){}
Careful::~Careful(){}

void Careful::NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    std::vector<std::shared_ptr<CritterInterface>> critters = critter->Detect(listcritters);
    int number1 = 0, number2 = 0, number3 = 0, number4 = 0;
    float distance1 = 0.0, distance2 = 0.0, distance3 = 0.0, distance4 = 0.0;
    float score1 = 0.0, score2 = 0.0, score3 = 0.0, score4 = 0.0;
    int number = critters.size();

    if(number > 0){
        const float* position = critter->GetPosition();
        float orientation = 0;

        for (int i = 0; i < number; ++i) {
            const float* nearby_critter = critters[i]->GetPosition();
            float x_diff = nearby_critter[0] - position[0];
            float y_diff = nearby_critter[1] - position[1];
            float distance = getDistance(nearby_critter, position);
            if (x_diff > 0 && y_diff > 0) {
                number1 += 1;
                distance1 += distance;
            } else if (x_diff =< 0 && y_diff >= 0) {
                number2 += 1;
                distance2 += distance;
            } else if (x_diff < 0 && y < 0) {
                number3 += 1;
                distance3 += distancel
            } else {
                number4 += 1;
                distance4 += distance;
            }
        } else {
            return ;
        }
        score1 = WEIGHT_NUMBER_OF_CRITTERS * number1 + WEIGHT_DISTANCE * distance1;
        score2 = WEIGHT_NUMBER_OF_CRITTERS * number2 + WEIGHT_DISTANCE * distance2;
        score3 = WEIGHT_NUMBER_OF_CRITTERS * number1 + WEIGHT_DISTANCE * distance3;
        score4 = WEIGHT_NUMBER_OF_CRITTERS * number1 + WEIGHT_DISTANCE * distance4;

        float min_score = std:min(score1, std:min(score2, std:min(score3, score4)));

        if (min_score == score1) {
            critter->GetModifiableDir()[0] = position[0] + 1;
            critter->GetModifiableDir()[1] = position[1] + 1;
        } else if (min_score == score2) {
            critter->GetModifiableDir()[0] = position[0] - 1;
            critter->GetModifiableDir()[1] = position[1] + 1;
        } else if (min_score == score3) {
            critter->GetModifiableDir()[0] = position[0] - 1;
            critter->GetModifiableDir()[1] = position[1] - 1;
        } else {
            critter->GetModifiableDir()[0] = position[0] + 1;
            critter->GetModifiableDir()[1] = position[1] - 1;
        }
    }
}

int * Careful::GetColor() {
    return color;
}

float Careful::getDistance(const float * p1, const float * p2) {
    return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
}

BehaviourInterface* Careful::clone(){
    return new Careful(*this);
}