#ifndef _SIMULATION_H_
#define _SIMULATION_H_

// Behaviour config
static const int initialCritterNumber = 20;
static const float spawnRate = 0.01; // number of critters appearing at each update cycle
	// Make sure sum is equal to 1
static const float kamikazePerc = 0.25;
static const float fearfulPerc = 0.50;
static const float sheepPerc = 0.75;
static const float carefulPerc = 1.0;


// For fearful critter. A fearful will go to the opposite direction if
// the number of critters around it is bigger than this threshold
static const int FEAR_THRESHOLD = 1;

// For careful critter.
static const float WEIGHT_NUMBER_OF_CRITTERS = 0.4;
static const float WEIGHT_DISTANCE = 0.6;

// Accessories & Sensors config : for birth
static const float eyeChance = 0.5;
static const float earChance = 0.5;
static const float finChance = 0.3;
static const float shellChance = 0.3;
static const float camouflageChance = 0.2;

// Accessories & sensors stats
static const float minSpeedBonus = 1.2;
static const float maxSpeedBonus = 2.0;
static const float minSpeedMalus = 0.8;
static const float maxSpeedMalus = 0.5;
static const float minShellResistance = 1.2;
static const float maxShellResistance = 2.0;
static const float minCamouflageBonus = 0.3;
static const float maxCamouflageBonus = 1.0;
static const float minEarRadius = 30;
static const float maxEarRadius = 50;
static const float minEarCapacity = 0.3;
static const float maxEarCapacity = 1.0;
static const float minEyeDistance = 40;
static const float maxEyeDistance = 70;
static const float minEyeCapacity = 0.3;
static const float maxEyeCapacity = 1.0;
static const float minEyeAngle = 0.5;
static const float maxEyeAngle = 1.2;

// Aquarium dimensions
static const int width = 1000;
static const int height = 500;

// Critter features
static const float minSize = 9.0;
static const float maxSize = 15.0;
static const float minSpeed = 2.0;
static const float maxSpeed = 7.0;
static const int minLifespan = 1000;
static const int maxLifespan = 2000;

static const float collisionDeathChance = 0.2;

#endif