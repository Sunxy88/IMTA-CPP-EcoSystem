#include "BaseCritter.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <string.h>

BaseCritter::BaseCritter(std::string name, float baseSpeed, int maxAge, float position[DIM], float size[DIM], /*BehaviourInterface behaviour, */bool isMultiBehaviour /*= false*/){
	std::cout << "Creating a new Critter named " << name << " at position (" << position[0] << "," << position[1] << ")." << std::endl;

	this->name = name;
	this->baseSpeed = baseSpeed;
	this->maxAge = maxAge;
	memcpy(this->position, position, DIM * sizeof(float));
	memcpy(this->size, size, DIM * sizeof(float));
	//this->behaviour = behaviour;
	this->isMultiBehaviour = isMultiBehaviour;
	for (int i= 0; i < DIM; i++) {
		this->direction[i] = 0;
	}

	this->age = 0;
	this->isDead = false;
	std::srand(std::time(nullptr));
}

BaseCritter::BaseCritter(const BaseCritter &b){
	//TODO : position
	std::cout << "Copying Critter named " << b.GetName() << std::endl;
	this->name = b.GetName() + "Jr";
	this->baseSpeed = b.GetBaseSpeed();
	memcpy(this->size, b.GetSize(), DIM * sizeof(float));
	this->maxAge = b.GetMaxAge();
	//this->behaviour = b.GetBehaviour(); //Copier au lieu de garder le même objet ?
	this->isMultiBehaviour = b.GetMultiBehaviour();

	this->age = 0;
	this->isDead = false;
	std::srand(std::time(nullptr));
}

BaseCritter::~BaseCritter(){
	std::cout << "Calling BaseCritter destructor on " << this->name << std::endl;
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

std::vector<CritterInterface> BaseCritter::Detect(){
	return std::vector<CritterInterface>();
}

// void BaseCritter::ChangeBehaviour(BehaviourInterface newBehaviour){
// 	this->behaviour = newBehaviour;
// }

void BaseCritter::Move(){
 	float directionVector = behaviour->NextMove();
 	const float speed = this->CalculateSpeed();
 	this->MoveTowards(speed * directionVector);
 }

void BaseCritter::Update(){
	//this->Move();
	this->age++;
	if(this->age >= this->maxAge){
		std::cout << this->name << " is dying of old age." << std::endl;
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
		std::cout << this-> name << " died from collision." << std::endl;
		this->isDead = true;
	}
	else{
		std::cout << this->name << " has survived collision and bounced." << std::endl;
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

const float* BaseCritter::GetSize() const {return this->size; }

const std::string BaseCritter::GetName() const {return this->name; }

const float BaseCritter::GetBaseSpeed() const {return this->baseSpeed; }

const int BaseCritter::GetMaxAge() const {return this->maxAge; }

const int BaseCritter::GetCurrentAge() const {return this->age; }

//const BehaviourInterface BaseCritter::GetBehaviour() const {return this->behaviour; }

const bool BaseCritter::GetMultiBehaviour() const {return this->isMultiBehaviour; }


void BaseCritter::Draw(UImg & support){
	const float HEADRATIO = 2.1;

	const float orientation = atan(this->position[0] / this->position[1]) * 180 / M_PI;
	const float maxSize = std::max(this->size[0], this->size[1]);
	const double xt = this->position[0] + cos(orientation)*maxSize/HEADRATIO;
	const double yt = this->position[1] - sin(orientation)*maxSize/HEADRATIO;

	//support.draw_ellipse(this->position[0], this->position[1], this->size[0], this->size[1], orientation, this->behaviour.GetColor());
	//support.draw_circle( xt, yt, maxSize/HEADRATIO, this->behaviour.GetColor());
}

void BaseCritter::MoveTowards(const float newDirection[DIM]){
	//Using newDirection as the next position
	for (int i= 0; i < DIM; i++) {
		this->direction[i] = newDirection[i] - this->position[i];
		this->position[i] = newDirection[i];
	}
}