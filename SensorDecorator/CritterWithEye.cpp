/*
 * CritterWithEye.cpp
 *
 *      Author: Sami RMILI
 */


#include <string>
#include "CritterWithEye.h"
#include "CritterInterface.h"

using namespace std;

namespace Aqua {

CritterWithEye::CritterWithEye(CritterInterface *critter, float angle, float distance, float capacity): CritterSensorDecorator(critter){
        this->angle = angle;
        this->distance = distance;
        this->capacity = capacity;
}

CritterWithEye::~CritterWithEye(){}

vector<CritterInterface> CritterWithEye::Detect() {
     
}

bool CritterWithEye::IsColliding(CritterInterface* critter){

}


}