/*
 * CritterWithEye.cpp
 *
 *      Author: Sami RMILI
 */


#include <string>
#include "CritterWithEye.h"
#include "CritterInterface.h"
#include "../Environment.h"
using namespace std;



CritterWithEye::CritterWithEye(CritterInterface *critter, float angle, float distance, float capacity): CritterSensorDecorator(critter){
        this->angle = angle;
        this->distance = distance;
        this->capacity = capacity;
}

CritterWithEye::~CritterWithEye(){}

std::vector<std::shared_ptr<CritterInterface>> CritterWithEye::Detect(std::vector<std::shared_ptr<CritterInterface>> critters) {
        std::vector<std::shared_ptr<CritterInterface>> result;

        // iterate over all critters and check if they are colliding with my ear
        for ( std::vector<std::shared_ptr<CritterInterface>>::iterator it = critters.begin() ; it != critters.end() ; ++it )
   {
            if((*it)->GetId() == critter->GetId()){
                continue;
            }
            if(IsEyeColliding(*(*it)) && capacity > critter->CalculateCamouflageCapacity()){
                        result.push_back((*it)); 
                        std::cout << (*it)->GetId() << " was detected by " << critter->GetId() << "'s ear" << std::endl;
            } 
        }
        return result;
}

bool CritterWithEye::IsEyeColliding(CritterInterface &other){

    // TODO
    return false;
}
bool CritterWithEye::IsColliding(CritterInterface &other){
    return this->critter->IsColliding(other);
}


float CritterWithEye::CalculateSpeed(){
    return this->critter->CalculateSpeed();
}

float CritterWithEye::CalculateCollisionResistance(){
    return this->critter->CalculateCollisionResistance();
}

float CritterWithEye::CalculateCamouflageCapacity(){
    return this->critter->CalculateCamouflageCapacity();  
}


void CritterWithEye::ChangeBehaviour(BehaviourInterface* newBehaviour){
	this->critter->ChangeBehaviour(newBehaviour);
}

void CritterWithEye::Move(Environment & env, float speed){
	this->critter->Move(env, CalculateSpeed());

 }

void CritterWithEye::Update(Environment & env, float speed){
    this->critter->GetBehaviour()->NextMove(this, GetModifiableDir(), env.GetCritters());
	this->critter->Update(env, speed);
}


void CritterWithEye::AttemptSurvive(){
	this->critter->AttemptSurvive();
}

bool CritterWithEye::IsDying(){
	return this->critter->IsDying();
}

void CritterWithEye::Bounce(){
	this->critter->Bounce();
}

const float* CritterWithEye::GetPosition() const {return this->critter->GetPosition(); }

const float* CritterWithEye::GetDirection() const {return this->critter->GetDirection(); }

float* CritterWithEye::GetModifiableDir() {return this->critter->GetModifiableDir(); }

const float* CritterWithEye::GetSize() const {return this->critter->GetSize(); }

const int CritterWithEye::GetId() const {return this->critter->GetId(); }

const float CritterWithEye::GetBaseSpeed() const {return this->critter->GetBaseSpeed(); }

const int CritterWithEye::GetLifespan() const {return this->critter->GetLifespan(); }

const int CritterWithEye::GetCurrentAge() const {return this->critter->GetCurrentAge(); }

BehaviourInterface* CritterWithEye::GetBehaviour() {return this->critter->GetBehaviour();}

const bool CritterWithEye::GetMultiBehaviour() const {return this->critter->GetMultiBehaviour(); }

void CritterWithEye::setIsDying(bool dead){this->critter->setIsDying(dead);}


void CritterWithEye::Draw(UImg & support){
    int color[3] = {0,150,0};
    float xb = this->critter->GetPosition()[0];
    float yb = this->critter->GetPosition()[1];
    float xa = distance*this->critter->GetDirection()[0] + this->critter->GetPosition()[0];
    float ya = distance*this->critter->GetDirection()[1] + this->critter->GetPosition()[1];

    float r = tan(angle / 2) * distance;

    float xc = xa - r * (yb - ya) / distance;
    float yc = ya + r *  (xb - xa) / distance;

    float xd = xa + r * (yb - ya) / distance;
    float yd = ya - r * (xb - xa) / distance;
     support.draw_triangle(xb, yb, xc, yc, xd, yd, color, 0.5);
	this->critter->Draw(support);
}


