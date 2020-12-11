#ifndef _BASECRITTER_H_
#define _BASECRITTER_H_

#include <string>

#include "CritterInterface.h"
#include "BehaviourInterface.h"

class BaseCritter : public CritterInterface{

 	private :
 		int id;
 		float baseSpeed;
 		float position[DIM];
 		float size[DIM];
 		float direction[DIM];
 		int age;
 		int lifespan;
 		BehaviourInterface* behaviour;
 		bool isMultiBehaviour;
 		bool isDead;

 	private :
 		void MoveTowards(const float newDirection[DIM]);

 	public :
 		BaseCritter(int id, float baseSpeed, int lifespan, float position[DIM], float direction[DIM], float size[DIM], bool isMultiBehaviour = false);
 		BaseCritter(const BaseCritter &b);
 		~BaseCritter();
 		friend std::ostream& operator<<(std::ostream& flot, const BaseCritter& b);

 		BaseCritter* Clone();
 		void AttemptSurvive();
 		bool IsDying();
 		void Bounce();
 		float CalculateSpeed() override;
 		float CalculateCollisionResistance() override;
 		float CalculateCamouflageCapacity() override;
 		std::vector<CritterInterface> Detect(vector<CritterInterface>* critters) override;
 		//void ChangeBehaviour(BehaviourInterface newBehaviour) override;
 		void Move() override;
 		void Update() override;
 		bool IsColliding(CritterInterface &other) override;

 		const float* GetPosition() const override;
		 const float* GetDirection() const override;
 		const float* GetSize() const override;
 		const int GetId() const override;
 		const float GetBaseSpeed() const override;
 		const int GetLifespan() const override;
 		const int GetCurrentAge() const override;
 		//const BehaviourInterface GetBehaviour() const = 0;
 		const bool GetMultiBehaviour() const override;

 		void Draw(UImg & support) override;

 };

 #endif