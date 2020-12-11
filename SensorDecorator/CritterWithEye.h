/*
 * CritterWithEye.h
 *
 *      Author: Sami RMILI
 */
#pragma once

#ifndef  CRITTERWITHEYE_H
#define  CRITTERWITHEYE_H_

#include "CritterSensorDecorator.h"
#include "CritterInterface.h"

using namespace std;

class CritterWithEye : public CritterSensorDecorator{
private:
    float angle;
    float distance;
    float capacity;

public:
	CritterWithEye(CritterInterface* critter, float angle, float distance, float capacity);
	~CritterWithEye();

	vector<CritterInterface> Detect(vector<CritterInterface>* critters) override;
    bool IsColliding(CritterInterface* critter) override;
	
};


#endif /*  CRITTERWITHEYE_H_*/