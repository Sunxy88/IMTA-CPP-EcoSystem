/*
 * CritterSensorDecorator.h
 *
 *      Author: Sami RMILI
 */
#pragma once

#ifndef  CRITTERSENSORDECORATOR_H
#define  CRITTERSENSORDECORATOR_H_


#include "../CritterInterface.h"

using namespace std;


class CritterSensorDecorator : public CritterInterface{
protected:
	CritterInterface* critter;

public:
	CritterSensorDecorator(CritterInterface *critter);
	virtual ~CritterSensorDecorator();

};


#endif /*  CRITTERSENSORDECORATOR_H_*/