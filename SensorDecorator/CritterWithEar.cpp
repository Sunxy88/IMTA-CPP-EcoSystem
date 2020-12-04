/*
 * CritterWithEar.cpp
 *
 *      Author: Sami RMILI
 */


#include <string>
#include "CritterWithEar.h"
#include "CritterInterface.h"
#include "CritterAccessoryDecorator.h"


CritterWithEar::CritterWithEar(CritterInterface* critter, float radius, float capacity) : CritterSensorDecorator(critter) {
        this->radius = radius;
        this->capacity = capacity;
}

CritterWithEar::~CritterWithEar(){}

vector<CritterInterface> CritterWithEar::Detect() {
     
}

bool CritterWithEar::IsColliding(CritterInterface* critter){
    

}