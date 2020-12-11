#include "CritterFactory.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

int CritterFactory::count = 0;

CritterFactory::CritterFactory(){
	std::srand(std::time(nullptr));
	std::rand();
}


BaseCritter CritterFactory::CreateBaseCritter() const{
	const float speed = RandomBoundedFloat(minSpeed, maxSpeed);
	const float lifespan = RandomBoundedFloat(minSpeed, maxSpeed);
	float position[2];
	float size[2];
	float direction[2];
	for(int i= 0; i < 2; i++){
		size[i] = RandomBoundedFloat(minSize, maxSize);
	}
	position[0] = RandomBoundedFloat(0, width);
	position[1] = RandomBoundedFloat(0, height);
	float angle = RandomBoundedFloat(0, 2*M_PI);
	direction[0] = cos(angle);
	direction[1] = sin(angle);


	int id = count++;
	return BaseCritter(id, speed, lifespan, position, direction, size);
}


const float CritterFactory::RandomBoundedFloat(const float min, const float max) const{
	float randNum = ((float) std::rand()) / (float) RAND_MAX;
	return min + randNum * (max - min);
}