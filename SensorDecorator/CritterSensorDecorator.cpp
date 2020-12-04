/*
 * CritterSensorDecorator.cpp
 *
 *      Author: Sami RMILI
 */


#include "CritterSensorDecorator.h"
#include "CritterSensorInterface.h"

CritterSensorDecorator::CritterSensorDecorator(CritterSensorInterface  *crittersensor) : crittersensor(crittersensor) {}


