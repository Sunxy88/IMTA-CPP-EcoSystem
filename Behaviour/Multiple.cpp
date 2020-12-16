//
// Created by Xi Sung on 12/17/20.
//

#include "Multiple.h"
#include "stdlib.h"
#include "time.h"

Multiple::Multiple(){}
Multiple::~Multiple(){}

// Randomly chooses another behaviour for NextMove()
void Multiple::NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) {
    srand((unsigned) time(NULL));
    int randomBehaviourIndex = rand() % 4;
    behaviours[randomBehaviourIndex]->NextMove(critter, listcritters);
}

int * Multiple::GetColor() {
    return color;
}

BehaviourInterface* Multiple::clone(){
    return new Multiple(*this);
}