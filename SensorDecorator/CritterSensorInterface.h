/*
 * CritterSensorInterface.h
 *
 *      Author: Sami RMILI
 */
#pragma once

#ifndef  CRITTERSENSORINTERFACE_H
#define  CRITTERSENSORINTERFACE_H_



using namespace std;
class CritterInterface;

class CritterSensorInterface {


public:
	CritterSensorInterface();
	virtual ~CritterSensorInterface();

	virtual vector<CritterInterface> Detect(vector<CritterInterface>* critters) = 0;
	virtual const float* GetPosition() const = 0;
 	virtual const float* GetSize() const = 0;
	virtual void Draw(UImg & support) = 0;
	
};


#endif /*  CRITTERSENSORINTERFACE_H_*/