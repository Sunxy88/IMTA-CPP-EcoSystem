/*
 * CritterSensorInterface.h
 *
 *      Author: Sami RMILI
 */
#pragma once

#ifndef  CRITTERSENSORINTERFACE_H
#define  CRITTERSENSORINTERFACE_H_

#include "CritterInterface.h"

using namespace std;

class CritterSensorInterface {


public:
	CritterSensorInterface();
	virtual ~CritterSensorInterface();

	virtual vector<CritterInterface> Detect(vector<CritterInterface>* critters) = 0;
	virtual const float* GetPosition() const = 0;
 	virtual const float* GetSize() const = 0;
	
};


#endif /*  CRITTERSENSORINTERFACE_H_*/