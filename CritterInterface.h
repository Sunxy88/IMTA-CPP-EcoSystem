#ifndef _CRITTERINTERFACE_H_
#define _CRITTERINTERFACE_H_

#include <vector>
#include <iostream>

#include "UImg.h"
#include "SensorDecorator/CritterSensorInterface.h"

 class CritterInterface : public CritterSensorInterface {

 	public :
 		static const int DIM = 2;

 		virtual float CalculateSpeed() = 0;
 		virtual float CalculateCollisionResistance() = 0;
 		virtual float CalculateCamouflageCapacity() = 0;
 		//virtual void ChangeBehaviour(BehaviourInterface* newBehaviour) = 0;
 		virtual void Move() = 0;
 		virtual void Update() = 0;
 		virtual bool IsColliding(CritterInterface &other) = 0;

	    
 		virtual const float* GetPosition() const = 0;
		virtual const float* GetDirection() const = 0;
 		virtual const float* GetSize() const = 0;
 		virtual const int GetId() const = 0;
 		virtual const float GetBaseSpeed() const = 0;
 		virtual const int GetLifespan() const = 0;
 		virtual const int GetCurrentAge() const = 0;
 		//virtual const BehaviourInterface GetBehaviour() const = 0;
 		virtual const bool GetMultiBehaviour() const = 0;

 		virtual void Draw(UImg & support) = 0;


 };

 #endif