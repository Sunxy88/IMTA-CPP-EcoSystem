#include "CritterFactory.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include "Behaviour/Kamikaze.h"
#include "Behaviour/Fearful.h"
#include "Behaviour/Sheep.h"
#include "Decorator/CritterWithFin.h"
#include "Decorator/CritterWithShell.h"
#include "Decorator/CritterWithCamouflage.h"
#include "Decorator/CritterAccessoryDecorator.h"
#include "SensorDecorator/CritterSensorDecorator.h"
#include "SensorDecorator/CritterWithEar.h"
#include "SensorDecorator/CritterWithEye.h"

int CritterFactory::count = 0;

CritterFactory::CritterFactory(){
	
}


CritterInterface* CritterFactory::CreateBaseCritter() const{
	// Using simulation parameters to randomly create a critter

	const float speed = RandomBoundedFloat(minSpeed, maxSpeed);
	const float lifespan = RandomBoundedFloat(minLifespan, maxLifespan);

	float position[2];
	float size[2];
	float direction[2];
	
	size[0] = RandomBoundedFloat(minSize, maxSize);
	size[1] = size[0] / 3;
	
	//any position within the aquarium
	position[0] = RandomBoundedFloat(0, width);
	position[1] = RandomBoundedFloat(0, height);
	float angle = RandomBoundedFloat(0, 2*M_PI);
	direction[0] = cos(angle);
	direction[1] = sin(angle);

	int id = count++;
	BehaviourInterface* k;
	float behaviour_rand = RandomBoundedFloat(0, 1);
	std::cout << behaviour_rand << "  Behave" << std::endl;
	if(behaviour_rand < 0.2){
		k = new Kamikaze();
	}else if (behaviour_rand < 0.5){
		k = new Fearful();
	}else {
		k = new Sheep();
	}

	CritterInterface* b = new BaseCritter(id, speed, lifespan, position, direction, size, k);
	if(AttemptThreshold(finChance)){
		float speedBonus = RandomBoundedFloat(minSpeedBonus, maxSpeedBonus);
		b = new CritterWithFin(b, speedBonus); 
	}
	if(AttemptThreshold(shellChance)){
		float speedMalus = RandomBoundedFloat(minSpeedMalus, maxSpeedMalus);
		float resistanceBonus = RandomBoundedFloat(minShellResistance, maxShellResistance);
		b = new CritterWithShell(b, speedMalus, resistanceBonus);
	}
	if(AttemptThreshold(camouflageChance)){
		float camouflageChance = RandomBoundedFloat(minCamouflageBonus, maxCamouflageBonus);
		b = new CritterWithCamouflage(b, camouflageChance);
	}
	if(AttemptThreshold(earChance)){
		float radius = RandomBoundedFloat(minEarRadius, maxEarRadius);
		float capacity = RandomBoundedFloat(minEarCapacity, maxEarCapacity);
		b = new CritterWithEar(b, radius , capacity);
	}
	if(AttemptThreshold(eyeChance)){
		float distance = RandomBoundedFloat(minEyeDistance, maxEyeDistance);
		float eye_capacity = RandomBoundedFloat(minEyeCapacity, maxEyeCapacity);
		float eye_angle = RandomBoundedFloat(minEyeAngle, maxEyeAngle);
		b = new CritterWithEye(b, eye_angle, distance, eye_capacity);
	}
	
	return b;
}

CritterInterface* CritterFactory::AttemptCloning(CritterInterface* critter) const{
	CritterInterface* newCritter = nullptr;
	if(AttemptThreshold(cloneRate)){
		std::cout << "Cloning " << *(reinterpret_cast<BaseCritter*>(critter)) <<std::endl;
		//newCritter = new BaseCritter(*(reinterpret_cast<BaseCritter*>(critter)));
	}

	return newCritter;
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