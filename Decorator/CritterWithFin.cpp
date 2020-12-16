#include "CritterAccessoryDecorator.h"
#include "CritterWithFin.h"

CritterWithFin::CritterWithFin(CritterInterface* component_,float speedBonus_) : CritterAccessoryDecorator(component_),speedBonus(speedBonus_){std::cout << "FIN CRITTER" << std::endl;}

CritterWithFin::~CritterWithFin(){component->~CritterInterface();}

float CritterWithFin::CalculateSpeed(){
    return this->component->CalculateSpeed() * speedBonus;
}

float CritterWithFin::CalculateCollisionResistance(){
    return this->component->CalculateCollisionResistance();
}

float CritterWithFin::CalculateCamouflageCapacity(){
    return this->component->CalculateCamouflageCapacity();
}

std::vector<std::shared_ptr<CritterInterface>> CritterWithFin::Detect(std::vector<std::shared_ptr<CritterInterface>> critters){
	// For decorator use
	return this->component->Detect(critters);
}

void CritterWithFin::ChangeBehaviour(BehaviourInterface* newBehaviour){
	this->component->ChangeBehaviour(newBehaviour);
}

void CritterWithFin::Move(Environment & env, float speed){
	this->component->Move(env, CalculateSpeed());

 }

void CritterWithFin::Update(Environment & env, float speed){
	this->component->Update(env, speed);
}

bool CritterWithFin::IsColliding(CritterInterface &other){
	return this->component->IsColliding(other);
}


void CritterWithFin::AttemptSurvive(){
	this->component->AttemptSurvive();
}

bool CritterWithFin::IsDying(){
	return this->component->IsDying();
}

void CritterWithFin::Bounce(){
	this->component->Bounce();
}

const float* CritterWithFin::GetPosition() const {return this->component->GetPosition(); }

const float* CritterWithFin::GetDirection() const {return this->component->GetDirection(); }

float* CritterWithFin::GetModifiableDir() {return this->component->GetModifiableDir(); }

const float* CritterWithFin::GetSize() const {return this->component->GetSize(); }

const int CritterWithFin::GetId() const {return this->component->GetId(); }

const float CritterWithFin::GetBaseSpeed() const {return this->component->GetBaseSpeed(); }

const int CritterWithFin::GetLifespan() const {return this->component->GetLifespan(); }

const int CritterWithFin::GetCurrentAge() const {return this->component->GetCurrentAge(); }

BehaviourInterface* CritterWithFin::GetBehaviour() {return this->component->GetBehaviour();}

const bool CritterWithFin::GetMultiBehaviour() const {return this->component->GetMultiBehaviour(); }

void CritterWithFin::setIsDying(bool dead){this->component->setIsDying(dead);}


void CritterWithFin::Draw(UImg & support){
	this->component->Draw(support);
	const float* position = this->component->GetPosition();
	const float* direction = this->component->GetDirection();
	const float* size = this->component->GetSize();
	const float norm = std::pow( std::pow(direction[0], 2) + std::pow(direction[1], 2), 0.5 );
	//TODO
	/*support.draw_triangle(	position[0], 	position[1],
							position[0] + direction[0] * size[0]/norm, 	position[1] - direction[1] * size[0]/norm,
							position[0] - direction[0] * size[0]/norm, 	position[1] - direction[1] * size[0]/norm, this->component->GetBehaviour()->GetColor());*/
}


