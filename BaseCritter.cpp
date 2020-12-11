#include "BaseCritter.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <string.h>

BaseCritter::BaseCritter(int id, float baseSpeed, int lifespan, float position[DIM], float direction[DIM], float size[DIM], /*BehaviourInterface behaviour, */bool isMultiBehaviour /*= false*/){
	std::cout << "Creating a new Critter n°" << id << " at position (" << position[0] << "," << position[1] << ")." << std::endl;

	this->id = id;
	this->baseSpeed = baseSpeed;
	this->lifespan = lifespan;
	memcpy(this->position, position, DIM * sizeof(float));
	memcpy(this->direction, direction, DIM * sizeof(float));
	memcpy(this->size, size, DIM * sizeof(float));
	this->behaviour = behaviour;
	this->isMultiBehaviour = isMultiBehaviour;

	this->age = 0;
	this->isDead = false;
	std::srand(std::time(nullptr));
}

BaseCritter::BaseCritter(const BaseCritter &b){
	//TODO : position
	//A revoir
	std::cout << "Copying " << b << std::endl;
	this->id = b.GetId();
	this->baseSpeed = b.GetBaseSpeed();
	memcpy(this->size, b.GetSize(), DIM * sizeof(float));
	this->lifespan = b.GetLifespan();
	//this->behaviour = b.GetBehaviour(); //Copier au lieu de garder le même objet ?
	this->isMultiBehaviour = b.GetMultiBehaviour();

	this->age = 0;
	this->isDead = false;
	std::srand(std::time(nullptr));
}

std::ostream& operator<<(std::ostream& flot, const BaseCritter& b){
	flot << "BaseCritter n°" << b.GetId();
    return flot;
}

BaseCritter::~BaseCritter(){
	std::cout << "Calling BaseCritter destructor on " << *this << std::endl;
	//delete this->behaviour;
}

float BaseCritter::CalculateSpeed(){
	return this->baseSpeed;
}

float BaseCritter::CalculateCollisionResistance(){
	return 0;
}

float BaseCritter::CalculateCamouflageCapacity(){
	return 0;
}

std::vector<CritterInterface> BaseCritter::Detect(vector<CritterInterface>* critters){
	return std::vector<CritterInterface>();
}

// void BaseCritter::ChangeBehaviour(BehaviourInterface newBehaviour){
// 	this->behaviour = newBehaviour;
// }

void BaseCritter::Move(){
 	float* directionVector = behaviour->NextMove(this);
 	float speed = this->CalculateSpeed();

	for (int i= 0; i < DIM; i++) {
		directionVector[i] *= speed;
	}
 	this->MoveTowards(directionVector);
 }

void BaseCritter::Update(){
	//this->Move();
	this->age++;
	if(this->age >= this->lifespan){
		std::cout << this << " is dying of old age." << std::endl;
		this->isDead = true;
	}
}

bool BaseCritter::IsColliding(CritterInterface &other){
	//Detecting collision between two circles.

	//Getting the biggest radius for both ellipses.
	float radius = this->size[0];
	const float* otherSize = other.GetSize();
	float otherRadius = otherSize[0];
	for(int i= 1; i < DIM; i++){
		radius = std::max(radius, this->size[i]);
		otherRadius = std::max(otherRadius, otherSize[i]);
	}

	//Calculating distance between critters.
	float distance = 0;
	const float* otherPos = other.GetPosition();
	for(int i= 0; i < DIM; i++){
			distance += std::pow(otherPos[i] - this->position[i], 2);
	}
	distance = std::pow(distance, 0.5);
	std::cout << "Distance : " << distance << std::endl;

	return radius + otherRadius >= distance;
}

//BaseCritter BaseCritter::Clone(){
//	return BaseCritter(*this);
//}

void BaseCritter::AttemptSurvive(){
	double randNum = (double) std::rand() / RAND_MAX;
	std::cout << randNum << std::endl;
	if(randNum < 0.2){ //A ajouter en param de simulation
		std::cout << *this << " died from collision." << std::endl;
		this->isDead = true;
	}
	else{
		std::cout << *this << " has survived collision and bounced." << std::endl;
		Bounce();
	}
}

bool BaseCritter::IsDying(){
	return this->isDead;
}

void BaseCritter::Bounce(){
	//The critter then goes in the opposite direction.
	float newDir[DIM];
	memcpy(newDir, this->direction, DIM * sizeof(float));
	for(int i= 0; i < DIM; i++){
		newDir[i] = - newDir[i];
	}
	this->MoveTowards(newDir);

}

const float* BaseCritter::GetPosition() const {return this->position; }

const float* BaseCritter::GetDirection() const {return this->direction; }

const float* BaseCritter::GetSize() const {return this->size; }

const int BaseCritter::GetId() const {return this->id; }

const float BaseCritter::GetBaseSpeed() const {return this->baseSpeed; }

const int BaseCritter::GetLifespan() const {return this->lifespan; }

const int BaseCritter::GetCurrentAge() const {return this->age; }

//const BehaviourInterface BaseCritter::GetBehaviour() const {return this->behaviour; }

const bool BaseCritter::GetMultiBehaviour() const {return this->isMultiBehaviour; }


void BaseCritter::Draw(UImg & support){
	const float HEADRATIO = 2.1;

	const float orientation = atan(this->position[0] / this->position[1]) * 180 / M_PI;
	const float maxSize = std::max(this->size[0], this->size[1]);
	const double xt = this->position[0] + cos(orientation)*maxSize/HEADRATIO;
	const double yt = this->position[1] - sin(orientation)*maxSize/HEADRATIO;

	support.draw_ellipse(this->position[0], this->position[1], this->size[0], this->size[1], orientation, behaviour->GetColor());
	support.draw_circle( xt, yt, maxSize/HEADRATIO, behaviour->GetColor());
}

void BaseCritter::MoveTowards(const float newDirection[DIM]){
	//Using newDirection as the next position
	for (int i= 0; i < DIM; i++) {
		this->direction[i] = newDirection[i] - this->position[i];
		this->position[i] = newDirection[i];
	}
}