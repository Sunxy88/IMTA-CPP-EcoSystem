#include "CritterAccessoryDecorator.h"
#include "CritterWithShell.h"

CritterWithShell::CritterWithShell(CritterInterface* component_,float speedMalus_,float collisionResistance_) : CritterAccessoryDecorator(component_),speedMalus(speedMalus_),collisionResistance(collisionResistance_){std::cout << "SHELL CRITTER" << std::endl;}

float CritterWithShell::CalculateSpeed(){
    return this->component->CalculateSpeed() * speedMalus;
}

float CritterWithShell::CalculateCollisionResistance(){
    return this->component->CalculateCollisionResistance() + collisionResistance ;
}

float CritterWithShell::CalculateCamouflageCapacity(){
    return this->component->CalculateCamouflageCapacity();  
}

std::vector<std::shared_ptr<CritterInterface>> CritterWithShell::Detect(std::vector<std::shared_ptr<CritterInterface>> critters){
	// For decorator use
	return this->component->Detect(critters);
}

void CritterWithShell::ChangeBehaviour(BehaviourInterface* newBehaviour){
	this->component->ChangeBehaviour(newBehaviour);
}

void CritterWithShell::Move(Environment & env, float speed){
	this->component->Move(env, CalculateSpeed());

 }

void CritterWithShell::Update(Environment & env, float speed){
	this->component->Update(env, speed);
}

bool CritterWithShell::IsColliding(CritterInterface &other){
	return this->component->IsColliding(other);
}


void CritterWithShell::AttemptSurvive(){
	this->component->AttemptSurvive();
}

bool CritterWithShell::IsDying(){
	return this->component->IsDying();
}

void CritterWithShell::Bounce(){
	this->component->Bounce();
}

const float* CritterWithShell::GetPosition() const {return this->component->GetPosition(); }

const float* CritterWithShell::GetDirection() const {return this->component->GetDirection(); }

const float* CritterWithShell::GetSize() const {return this->component->GetSize(); }

const int CritterWithShell::GetId() const {return this->component->GetId(); }

const float CritterWithShell::GetBaseSpeed() const {return this->component->GetBaseSpeed(); }

const int CritterWithShell::GetLifespan() const {return this->component->GetLifespan(); }

const int CritterWithShell::GetCurrentAge() const {return this->component->GetCurrentAge(); }

BehaviourInterface* CritterWithShell::GetBehaviour() {return this->component->GetBehaviour();}

const bool CritterWithShell::GetMultiBehaviour() const {return this->component->GetMultiBehaviour(); }

void CritterWithShell::setIsDying(bool dead){this->component->setIsDying(dead);}


void CritterWithShell::Draw(UImg & support){
	this->component->Draw(support);
}

