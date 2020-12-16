#ifndef _CRITTERINTERFACE_H_
#define _CRITTERINTERFACE_H_

#include <vector>
#include <iostream>
#include "UImg.h"
#include "memory"
#include "Behaviour/BehaviourInterface.h"


class Environment;
class BehaviourInterface;

class CritterInterface{
	
 	public :
		CritterInterface();
		virtual ~CritterInterface();
 		static const int DIM = 2;

		virtual float CalculateSpeed() = 0;
    	virtual float CalculateCollisionResistance() = 0;
    	virtual float CalculateCamouflageCapacity() = 0;
		virtual void Bounce() = 0;
		virtual bool IsDying() = 0;
		virtual void setIsDying(bool dead) = 0;
		virtual void AttemptSurvive() = 0;
 		virtual void ChangeBehaviour(BehaviourInterface* newBehaviour) = 0;
 		virtual void Move(Environment & env, float speed) = 0;
 		virtual void Update(Environment & env, float speed) = 0;
 		virtual bool IsColliding(CritterInterface &other) = 0;
        virtual std::vector<std::shared_ptr<CritterInterface>> Detect(std::vector<std::shared_ptr<CritterInterface>> critters) = 0;
	    
 		virtual const float* GetPosition() const = 0;
		virtual const float* GetDirection() const = 0;
		virtual float* GetModifiableDir() = 0 ;
 		virtual const float* GetSize() const = 0;
 		virtual const int GetId() const = 0;
 		virtual const float GetBaseSpeed() const = 0;
 		virtual const int GetLifespan() const = 0;
 		virtual const int GetCurrentAge() const = 0;
 		virtual BehaviourInterface* GetBehaviour()  = 0;
 		virtual const bool GetMultiBehaviour() const = 0;

 		virtual void Draw(UImg & support) = 0;
		virtual CritterInterface* clone() = 0;
		


 };

 #endif