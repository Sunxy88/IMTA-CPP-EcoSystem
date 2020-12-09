/*
 * CritterWithEar.h
 *
 *      Author: Sami RMILI
 */
#pragma once

#ifndef  CRITTERWITHEAR_H
#define  CRITTERWITHEAR_H_

#include "CritterSensorDecorator.h"
#include "CritterInterface.h"

using namespace std;


class CritterWithEar : public CritterSensorDecorator{
private:
    float radius;
    float capacity;

public:
	CritterWithEar(CritterInterface* critter, float radius, float capacity);
	~CritterWithEar();

	vector<CritterInterface> Detect(vector<CritterInterface>* critters) override;
    bool IsColliding(CritterInterface* critter) override;
	
};



#endif /*  CRITTERWITHEAR_H_*/