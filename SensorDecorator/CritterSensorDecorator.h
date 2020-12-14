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
#include "memory"

using namespace std;


class CritterSensorDecorator : public CritterSensorInterface, ColliderInterface{
protected:
	CritterSensorInterface* crittersensor;

public:
	CritterSensorDecorator(CritterSensorInterface *crittersensor);
	virtual ~CritterSensorDecorator();

	virtual std::vector<std::shared_ptr<CritterInterface>> Detect(std::vector<std::shared_ptr<CritterInterface>> critters) = 0;
    virtual bool IsColliding(CritterInterface* critter) = 0;
	virtual void Draw(UImg & support);
};


#endif /*  CRITTERSENSORDECORATOR_H_*/