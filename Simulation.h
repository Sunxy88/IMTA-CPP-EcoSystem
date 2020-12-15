#ifndef _SIMULATION_H_
#define _SIMULATION_H_

// Behaviour config
static const int initialCritterNumber = 100;
static const float spawnRate = 0.3; // number of critters appearing at each update cycle
	// Make sure sum is equal to 1
static const float fearfulPerc = 0.8;
static const float kamikazePerc = 0.2;
static const float carefulPerc = 0;
static const float sheepPerc = 0;

// Accessories & Sensors config : for birth
static const float eyeChance = 0.5;
static const float earChance = 0.5;
static const float finChance = 0.3;
static const float shellChance = 0.3;
static const float camouflageChance = 0.2;


// Aquarium dimensions
static const int width = 1000;
static const int height = 500;

// Critter features
static const float minSize = 9.0;
static const float maxSize = 15.0;
static const float minSpeed = 5.0;
static const float maxSpeed = 10.0;
static const int minLifespan = 100;
static const int maxLifespan = 200;

static const float collisionDeathChance = 0.2;

#endif