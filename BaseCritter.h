#ifndef _BASECRITTER_H_
#define _BASECRITTER_H_

#include <string>

#include "CritterInterface.h"
#include "Behaviour/BehaviourInterface.h"

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
		int something;
 		bool isMultiBehaviour;
 		bool isDead;

 	private :
 		void MoveTowards(const float newDirection[DIM]);

 	public :
 		BaseCritter(int id, float baseSpeed, int lifespan, float position[DIM], float direction[DIM], float size[DIM], BehaviourInterface* behaviour, bool isMultiBehaviour = false);
 		BaseCritter(const BaseCritter &b);
 		~BaseCritter();
 		friend std::ostream& operator<<(std::ostream& flot, const BaseCritter& b);

 		BaseCritter* Clone();
 		void AttemptSurvive() override;
 		bool IsDying() override;
		void setIsDying(bool dead) override;
 		void Bounce() override;
 		float CalculateSpeed() override;
 		float CalculateCollisionResistance() override;
 		float CalculateCamouflageCapacity() override;
 		void ChangeBehaviour(BehaviourInterface* newBehaviour) override;
 		void Move(Environment & env, float speed) override;
 		void Update(Environment & env, float speed) override;
 		bool IsColliding(CritterInterface &other) override;
		std::vector<std::shared_ptr<CritterInterface>> Detect(std::vector<std::shared_ptr<CritterInterface>> critters) override;

 		const float* GetPosition() const override;
		const float* GetDirection() const override;
		float* GetModifiableDir() override;
 		const float* GetSize() const override;
 		const int GetId() const override;
 		const float GetBaseSpeed() const override;
 		const int GetLifespan() const override;
 		const int GetCurrentAge() const override;
 		BehaviourInterface* GetBehaviour()  override;
 		const bool GetMultiBehaviour() const override;

 		void Draw(UImg & support) override;
		CritterInterface* clone() override;

 };

 #endif
