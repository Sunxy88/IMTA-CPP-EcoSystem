/*
 * CritterWithEar.cpp
 *
 *      Author: Sami RMILI
 */


#include <string>
#include "CritterWithEar.h"
#include <iostream>
#include <cmath>
using namespace std;



CritterWithEar::CritterWithEar(CritterInterface* critter, float radius, float capacity) : CritterSensorDecorator(critter) {
        this->radius = radius;
        this->capacity = capacity;
        std::cout << "EAR ENGAGED" << std::endl;
}

CritterWithEar::~CritterWithEar(){}

std::vector<std::shared_ptr<CritterInterface>> CritterWithEar::Detect(std::vector<std::shared_ptr<CritterInterface>> critters) {
        std::vector<std::shared_ptr<CritterInterface>> result;

        // iterate over all critters and check if they are colliding with my ear
        for(int i = 0; i < critters.size(); i++){
                if(IsEarColliding(*critters.at(i)) && capacity > critters.at(i)->CalculateCamouflageCapacity()) result.push_back(critters.at(i)); 
        }
        return result;
}

bool CritterWithEar::IsEarColliding(CritterInterface &other){

    // Get the positions and sizes of both critters 
    const float* otherPos = other.GetPosition();
    const float* otherSize = critter->GetSize();
    const float* myPos = this->critter->GetPosition();


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

    return distance <= radius ;
}
bool CritterWithEar::IsColliding(CritterInterface &other){
    return this->critter->IsColliding(other);
}


float CritterWithEar::CalculateSpeed(){
    return this->critter->CalculateSpeed();
}

float CritterWithEar::CalculateCollisionResistance(){
    return this->critter->CalculateCollisionResistance();
}

float CritterWithEar::CalculateCamouflageCapacity(){
    return this->critter->CalculateCamouflageCapacity();  
}


void CritterWithEar::ChangeBehaviour(BehaviourInterface* newBehaviour){
	this->critter->ChangeBehaviour(newBehaviour);
}

void CritterWithEar::Move(Environment & env, float speed){
	this->critter->Move(env, CalculateSpeed());

 }

void CritterWithEar::Update(Environment & env, float speed){
	this->critter->Update(env, speed);
}


void CritterWithEar::AttemptSurvive(){
	this->critter->AttemptSurvive();
}

bool CritterWithEar::IsDying(){
	return this->critter->IsDying();
}

void CritterWithEar::Bounce(){
	this->critter->Bounce();
}

const float* CritterWithEar::GetPosition() const {return this->critter->GetPosition(); }

const float* CritterWithEar::GetDirection() const {return this->critter->GetDirection(); }

const float* CritterWithEar::GetSize() const {return this->critter->GetSize(); }

const int CritterWithEar::GetId() const {return this->critter->GetId(); }

const float CritterWithEar::GetBaseSpeed() const {return this->critter->GetBaseSpeed(); }

const int CritterWithEar::GetLifespan() const {return this->critter->GetLifespan(); }

const int CritterWithEar::GetCurrentAge() const {return this->critter->GetCurrentAge(); }

BehaviourInterface* CritterWithEar::GetBehaviour() {return this->critter->GetBehaviour();}

const bool CritterWithEar::GetMultiBehaviour() const {return this->critter->GetMultiBehaviour(); }

void CritterWithEar::setIsDying(bool dead){this->critter->setIsDying(dead);}


void CritterWithEar::Draw(UImg & support){
    int color[3] = {0,150,0};
     support.draw_circle( critter->GetPosition()[0], critter->GetPosition()[1], radius, color);
	this->critter->Draw(support);
}

