#include "CritterAccessoryDecorator.h"
#include "CritterWithCamouflage.h"

CritterWithCamouflage::CritterWithCamouflage(CritterInterface* component_,float camouflageCapacity_) : CritterAccessoryDecorator(component_),camouflageCapacity(camouflageCapacity_){std::cout << "CAMOUFLAGE CRITTER" << std::endl;}

float CritterWithCamouflage::CalculateSpeed(){
    return this->component->CalculateSpeed();
}

float CritterWithCamouflage::CalculateCollisionResistance(){
    return this->component->CalculateCollisionResistance();
}

float CritterWithCamouflage::CalculateCamouflageCapacity(){
    return this->component->CalculateCamouflageCapacity() + camouflageCapacity;
}

std::vector<std::shared_ptr<CritterInterface>> CritterWithCamouflage::Detect(std::vector<std::shared_ptr<CritterInterface>> critters){
	// For decorator use
	return this->component->Detect(critters);
}

void CritterWithCamouflage::ChangeBehaviour(BehaviourInterface* newBehaviour){
	this->component->ChangeBehaviour(newBehaviour);
}

void CritterWithCamouflage::Move(Environment & env, float speed){
	this->component->Move(env, CalculateSpeed());

 }

void CritterWithCamouflage::Update(Environment & env, float speed){
	this->component->Update(env, speed);
}

bool CritterWithCamouflage::IsColliding(CritterInterface &other){
	return this->component->IsColliding(other);
}


void CritterWithCamouflage::AttemptSurvive(){
	this->component->AttemptSurvive();
}

bool CritterWithCamouflage::IsDying(){
	return this->component->IsDying();
}

void CritterWithCamouflage::Bounce(){
	this->component->Bounce();
}

const float* CritterWithCamouflage::GetPosition() const {return this->component->GetPosition(); }

const float* CritterWithCamouflage::GetDirection() const {return this->component->GetDirection(); }

float* CritterWithCamouflage::GetModifiableDir() {return this->component->GetModifiableDir(); }

const float* CritterWithCamouflage::GetSize() const {return this->component->GetSize(); }

const int CritterWithCamouflage::GetId() const {return this->component->GetId(); }

const float CritterWithCamouflage::GetBaseSpeed() const {return this->component->GetBaseSpeed(); }

const int CritterWithCamouflage::GetLifespan() const {return this->component->GetLifespan(); }

const int CritterWithCamouflage::GetCurrentAge() const {return this->component->GetCurrentAge(); }

BehaviourInterface* CritterWithCamouflage::GetBehaviour() {return this->component->GetBehaviour();}

const bool CritterWithCamouflage::GetMultiBehaviour() const {return this->component->GetMultiBehaviour(); }

void CritterWithCamouflage::setIsDying(bool dead){this->component->setIsDying(dead);}


void CritterWithCamouflage::Draw(UImg & support){
	this->component->Draw(support);
}


