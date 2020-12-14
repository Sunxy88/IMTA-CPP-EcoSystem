/*
 * CritterWithEar.cpp
 *
 *      Author: Sami RMILI
 */


#include <string>
#include "CritterWithEar.h"
#include "CritterInterface.h"
#include "CritterAccessoryDecorator.h"
#include <iostream>
#include <cmath>
using namespace std;



CritterWithEar::CritterWithEar(CritterInterface* critter, float radius, float capacity) : CritterSensorDecorator(critter) {
        this->radius = radius;
        this->capacity = capacity;
}

CritterWithEar::~CritterWithEar(){}

vector<CritterInterface> CritterWithEar::Detect(vector<CritterInterface>* critters) {
        vector<CritterInterface> result;

        // iterate over all critters and check if they are colliding with my ear
        for(int i = 0; i < critters->size(); i++){
                if(IsColliding(&critters->at(i)) && capacity > critters->at(i).CalculateCamouflageCapacity()) result.push_back(critters->at(i)); 
        }
        return result;
}

bool CritterWithEar::IsColliding(CritterInterface* critter){

    // Get the positions and sizes of both critters 
    const float* otherPos = critter->GetPosition();
    const float* otherSize = critter->GetSize();
    const float* myPos = this->crittersensor->GetPosition();


    float testX = myPos[0];
    float testY = myPos[1];

    // Check the position of the circle(ear) compared to the rectangle(the other critter's body)
    if (myPos[0] < otherPos[0])         testX = otherPos[0];        // left edge
    else if (myPos[0] > otherPos[0]+otherSize[0]) testX = otherPos[0]+otherSize[0];     // right edge

    if (myPos[1] < otherPos[1])         testY = otherPos[1];        // top edge
    else if (myPos[1] > otherPos[1]+otherSize[1]) testY = otherPos[1]+otherSize[1];     // bottom edge

    float distX = myPos[0]-testX;
    float distY = myPos[1]-testY;
    float distance = sqrt((distX*distX) + (distY*distY))  ;

    return distance <= radius;
}

void CritterWithEar::Draw(UImg & support){
     int color[3] = {1,0,0};
     support.draw_circle( crittersensor->GetPosition()[0], crittersensor->GetPosition()[1], radius, color);
     crittersensor->Draw(support);
}