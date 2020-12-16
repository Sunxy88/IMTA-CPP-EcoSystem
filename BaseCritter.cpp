#include "BaseCritter.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <string.h>
#include "Environment.h"
#include "Behaviour/Kamikaze.h"
#include "Simulation.h"

BaseCritter::BaseCritter(int id, float baseSpeed, int lifespan, float position[DIM], float direction[DIM], float size[DIM], BehaviourInterface* behaviour, bool isMultiBehaviour /*= false*/) : behaviour(behaviour){
	// Copying all given elements
	std::cout << "Creating a new Critter n°" << id << " at position (" << position[0] << "," << position[1] << ")." << std::endl;
	this->id = id;
	this->baseSpeed = baseSpeed;
	this->lifespan = lifespan;
	memcpy(this->position, position, DIM * sizeof(float));
	memcpy(this->direction, direction, DIM * sizeof(float));
	memcpy(this->size, size, DIM * sizeof(float));
	this->isMultiBehaviour = isMultiBehaviour;

	this->age = 0;
	this->isDead = false;
}

BaseCritter::BaseCritter(const BaseCritter &b) : behaviour(b.behaviour->clone()){
	//TODO : positionning better
	std::cout << "Copying " << b << std::endl;
	this->id = CritterFactory::GetNewId();
	this->baseSpeed = b.GetBaseSpeed();
	memcpy(this->position, b.GetPosition(), DIM * sizeof(float));
	memcpy(this->direction, b.GetDirection(), DIM * sizeof(float));
	memcpy(this->size, b.GetSize(), DIM * sizeof(float));
	this->lifespan = b.GetLifespan();
	std::cout << behaviour->GetColor()[0] << std::endl;
	this->isMultiBehaviour = b.GetMultiBehaviour();

	this->age = 0;
	this->isDead = false;
}

std::ostream& operator<<(std::ostream& flot, const BaseCritter& b){
	flot << "BaseCritter n°" << b.GetId();
    return flot;
}

BaseCritter::~BaseCritter(){
	std::cout << "Calling BaseCritter destructor on " << *this << std::endl;
	delete this->behaviour;
}

float BaseCritter::CalculateSpeed(){
	// For decorator use
	return this->baseSpeed;
}

float BaseCritter::CalculateCollisionResistance(){
	// For decorator use
	return 0;
}

float BaseCritter::CalculateCamouflageCapacity(){
	// For decorator use
	return 0;
}

std::vector<std::shared_ptr<CritterInterface>> BaseCritter::Detect(std::vector<std::shared_ptr<CritterInterface>> critters){
	// For decorator use
	return std::vector<std::shared_ptr<CritterInterface>>();
}

void BaseCritter::ChangeBehaviour(BehaviourInterface* newBehaviour){
	this->behaviour = newBehaviour;
}

void BaseCritter::Move(Environment & env, float speed){

	// Check Collision with environment
	int xLim = env.getWidth();
	int yLim = env.getHeight();

	if((position[0] < 0) || (position[0] > xLim)){
		direction[0] = -direction[0];
	}
	if(position[1] < 0 || position[1] > yLim){
		direction[1] = -direction[1];
	}

    // Movement
	
 	position[0] += direction[0] * speed;
	position[1] += direction[1] * speed;
 }

void BaseCritter::Update(Environment & env, float speed){
	// Called by Environment
	this->Move(env, speed);
	this->age++;

	// Checking natural death
	if(this->age >= this->lifespan){
		std::cout << this->id << " is dying of old age." << std::endl;
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
	//std::cout << "Distance : " << distance << std::endl;

	return radius + otherRadius >= distance;
}

//BaseCritter BaseCritter::Clone(){
//	return BaseCritter(*this);
//}

void BaseCritter::AttemptSurvive(){
	// Called when colliding with another critter.
	// Has a random chance to either die or survive (and bounce)
	// Collision resistance gives another chance at survival if this critter is about to die
	double randNum = (double) std::rand() / RAND_MAX;
	if(randNum <= collisionDeathChance){
		if((double) std::rand() / RAND_MAX >= this->CalculateCollisionResistance()){
			std::cout << *this << " died from collision." << std::endl;
			this->isDead = true;
			return;
		}
	}
	std::cout << *this << " has survived collision and bounced." << std::endl;
	Bounce();
	return;
}

bool BaseCritter::IsDying(){
	return this->isDead;
}

void BaseCritter::Bounce(){
	//The critter then goes in the opposite direction.
	for(int i= 0; i < DIM; i++){
		direction[i] = - direction[i];
	}
}

const float* BaseCritter::GetPosition() const {return this->position; }

const float* BaseCritter::GetDirection() const {return this->direction; }

float* BaseCritter::GetModifiableDir() {return this->direction;}

const float* BaseCritter::GetSize() const {return this->size; }

const int BaseCritter::GetId() const {return this->id; }

const float BaseCritter::GetBaseSpeed() const {return this->baseSpeed; }

const int BaseCritter::GetLifespan() const {return this->lifespan; }

const int BaseCritter::GetCurrentAge() const {return this->age; }

<<<<<<< HEAD
BehaviourInterface* BaseCritter::GetBehaviour() {return this->behaviour; }
=======
BehaviourInterface* BaseCritter::GetBehaviour() {return this->behaviour;}
>>>>>>> 4107fd477036fc90861f7d0e67ceca1a07f3d375

const bool BaseCritter::GetMultiBehaviour() const {return this->isMultiBehaviour; }

void BaseCritter::setIsDying(bool dead){this->isDead = dead;}


void BaseCritter::Draw(UImg & support){
<<<<<<< HEAD

	const float orientation = atan(this->direction[1] / this->direction[0]) * 180 / M_PI;
	const float maxSize = std::max(this->size[0], this->size[1]);
=======
	//const float HEADRATIO = 2.1;

	const float orientation = atan(this->direction[1] / this->direction[0]) * 180 / M_PI;
	/*const float maxSize = std::max(this->size[0], this->size[1]);
	const double xt = this->position[0] + direction[0]*maxSize/HEADRATIO;
	const double yt = this->position[1] - direction[1]*maxSize/HEADRATIO;*/
>>>>>>> 4107fd477036fc90861f7d0e67ceca1a07f3d375
    
	
	//std::cout << this->behaviour->GetColor()[0] << std::endl;
	support.draw_ellipse(this->position[0], this->position[1], this->size[0], this->size[1], orientation, this->behaviour->GetColor());
<<<<<<< HEAD
	const float black[3] = {0, 0, 0};
	support.draw_text(this->position[0], this->position[1], std::to_string(this->id).c_str(), black, 1);
	const float norm = std::pow( std::pow(this->direction[0], 2) + std::pow(this->direction[1], 2), 0.5 ) * 0.5/maxSize;
	support.draw_arrow(this->position[0], this->position[1], this->position[0] + this->direction[0] / norm, this->position[1] + this->direction[1] / norm, black);
=======
	int text_color[3] = {100,100,0};
	support.draw_text(this->position[0], this->position[1], std::to_string(GetId()).c_str(), text_color, 1, 1.0, 22);
	//support.draw_circle( xt, yt, maxSize/HEADRATIO, this->behaviour->GetColor());
>>>>>>> 4107fd477036fc90861f7d0e67ceca1a07f3d375
}

void BaseCritter::MoveTowards(const float newDirection[DIM]){
	//Using newDirection as the next position
	for (int i= 0; i < DIM; i++) {
		this->direction[i] = newDirection[i] - this->position[i];
		this->position[i] = newDirection[i];
	}
}