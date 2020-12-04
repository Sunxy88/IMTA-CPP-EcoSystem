#include "BaseCritter.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <string.h>

BaseCritter::BaseCritter(std::string name, float baseSpeed, float position[DIM], float size[DIM], /*BehaviourInterface behaviour, */bool isMultiBehaviour /*= false*/){
	std::cout << "Creating a new Critter named " << name << " at position (" << position[0] << "," << position[1] << ")." << std::endl;

	this->name = name;
	this->baseSpeed = baseSpeed;
	memcpy(this->position, position, DIM);
	memcpy(this->size, size, DIM);
	//this->behaviour = behaviour;
	this->isMultiBehaviour = isMultiBehaviour;
	for (int i= 0; i < DIM; i++) {
		this->direction[i] = 0;
	}
	this->age = 0;
	this->isDead = false;
	std::srand(std::time(nullptr));
}

BaseCritter::~BaseCritter(){
	std::cout << "Calling BaseCritter destructor on " << this->name << std::endl;
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

// void BaseCritter::Move(){
// 	float* directionVector = this->behaviour.NextMove();
// 	float speed = this->CalculateSpeed();
// 	this->MoveTowards(speed * directionVector);
// }

void BaseCritter::Update(){
	//this->Move();
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

void BaseCritter::Clone(){

}

void BaseCritter::AttemptSurvive(const CritterInterface &other){
	double randNum = (double) std::rand() / RAND_MAX; //gérer l'aléatoire dans une classe Simulation ?
	std::cout << randNum << std::endl;
	if(randNum < 0.2){ //A ajouter en param de simulation
		std::cout << this-> name << " died from collision." << std::endl;
		this->isDead = true;
	}
	else{
		std::cout << this->name << " has survived collision and bounced." << std::endl;
		Bounce(other);
	}
}

bool BaseCritter::IsDying(){
	return this->isDead;
}

void BaseCritter::Bounce(const CritterInterface &other){
	const float* otherPos = other.GetPosition();

}

const float* BaseCritter::GetPosition() const {
	return this->position;
}

const float* BaseCritter::GetSize() const {
	return this->size;
}

void BaseCritter::MoveTowards(const float newDirection[DIM]){
	//Using newDirection as the next position
	for (int i= 0; i < DIM; i++) {
		this->direction[i] = newDirection[i] - this->position[i];
		this->position[i] = newDirection[i];
	}
}