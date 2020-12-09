/*
 * ColliderInterface.h
 *
 *      Author: Sami RMILI
 */
#pragma once

#ifndef  COLLIDERINTERFACE_H
#define  COLLIDERINTERFACE_H_

#include "CritterInterface.h"

using namespace std;

class ColliderInterface {


public:
	ColliderInterface();
	virtual ~ColliderInterface();

	virtual bool IsColliding(CritterInterface* critter) = 0;
	
};


#endif /*  COLLIDERINTERFACE_H_*/