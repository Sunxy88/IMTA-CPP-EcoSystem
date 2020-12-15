#include "CritterFactory.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include "Behaviour/Kamikaze.h"
#include "Behaviour/Fearful.h"
#include "Decorator/CritterWithFin.h"
#include "Decorator/CritterWithShell.h"
#include "Decorator/CritterWithCamouflage.h"
#include "Decorator/CritterAccessoryDecorator.h"
#include "SensorDecorator/CritterSensorDecorator.h"
#include "SensorDecorator/CritterWithEar.h"

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
	if(AttemptThreshold(fearfulPerc)){
		k = new Fearful();
	}else{
		k = new Kamikaze();
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