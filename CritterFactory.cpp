#include "CritterFactory.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include "Behaviour/Kamikaze.h"
#include "Decorator/CritterWithFin.h"

int CritterFactory::count = 0;

CritterFactory::CritterFactory(){
	
}


CritterInterface* CritterFactory::CreateBaseCritter() const{
	// Using simulation parameters to randomly create a critter

	const float speed = RandomBoundedFloat(minSpeed, maxSpeed);
	const float lifespan = RandomBoundedFloat(minSpeed, maxSpeed);

	float position[2];
	float size[2];
	float direction[2];
	for(int i= 0; i < 2; i++){
		size[i] = RandomBoundedFloat(minSize, maxSize);
	}
	//any position within the aquarium
	position[0] = RandomBoundedFloat(0, width);
	position[1] = RandomBoundedFloat(0, height);
	float angle = RandomBoundedFloat(0, 2*M_PI);
	direction[0] = cos(angle);
	direction[1] = sin(angle);

	int id = count++;
	Kamikaze* k = new Kamikaze();

	CritterInterface* b = new BaseCritter(id, speed, lifespan, position, direction, size, k);
	//if(AttemptThreshold(finChance)){b = new CritterWithFin(b, 0); }
	return b;
}




const float CritterFactory::RandomBoundedFloat(const float min, const float max) const{
	float randNum = ((float) std::rand()) / (float) RAND_MAX;
	return min + randNum * (max - min);
}

const bool CritterFactory::AttemptThreshold(const float threshold) const{
	return ((float) std::rand()) / (float) RAND_MAX <= threshold;
}

const int CritterFactory::GetNewId(){
	return count++;
}