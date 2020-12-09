/*
 * CritterSensorDecorator.h
 *
 *      Author: Sami RMILI
 */
#pragma once

#ifndef  CRITTERSENSORDECORATOR_H
#define  CRITTERSENSORDECORATOR_H_

#include "CritterSensorInterface.h"
#include "ColliderInterface.h"

using namespace std;


class CritterSensorDecorator : public CritterSensorInterface, ColliderInterface{
protected:
	CritterSensorInterface* crittersensor;

public:
	CritterSensorDecorator(CritterSensorInterface *crittersensor);
	virtual ~CritterSensorDecorator();

	virtual vector<CritterInterface> Detect(vector<CritterInterface>* critters) = 0;
    virtual bool IsColliding(CritterInterface* critter) = 0;
	
};


#endif /*  CRITTERSENSORDECORATOR_H_*/