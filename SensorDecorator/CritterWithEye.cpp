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

vector<CritterInterface> CritterWithEye::Detect(vector<CritterInterface>* critters) {
     vector<CritterInterface> result;

        // iterate over all critters and check if they are colliding with my ear
        for(int i = 0; i < critters->size(); i++){
                if(IsColliding(&critters->at(i)) && capacity > critters->at(i).CalculateCamouflageCapacity()) result.push_back(critters->at(i)); 
        }
     return result;
}

bool CritterWithEye::IsColliding(CritterInterface* critter){

}


}