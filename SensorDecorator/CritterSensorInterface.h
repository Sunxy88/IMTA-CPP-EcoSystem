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

	virtual vector<CritterInterface> Detect() = 0;
	
};


#endif /*  CRITTERSENSORINTERFACE_H_*/