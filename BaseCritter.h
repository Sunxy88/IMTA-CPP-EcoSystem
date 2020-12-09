#include <string>

#include "CritterInterface.h"

 class BaseCritter : public CritterInterface{

 	private :
 		std::string name;
 		float baseSpeed;
 		float position[DIM];
 		float size[DIM];
 		float direction[DIM];
 		int age;
 		int maxAge;
 		//BehaviourInterface behaviour;
 		bool isMultiBehaviour;
 		bool isDead;

 	private :
 		void MoveTowards(const float newDirection[DIM]);

 	public :
 		BaseCritter(std::string name, float baseSpeed, int maxAge, float position[DIM], float size[DIM], bool isMultiBehaviour = false);
 		BaseCritter(const BaseCritter &b);
 		~BaseCritter();

 		BaseCritter Clone();
 		void AttemptSurvive();
 		bool IsDying();
 		void Bounce();
 		float CalculateSpeed() override;
 		float CalculateCollisionResistance() override;
 		float CalculateCamouflageCapacity() override;
 		std::vector<CritterInterface> Detect() override;
 		//void ChangeBehaviour(BehaviourInterface newBehaviour) override;
 		//void Move() override;
 		void Update() override;
 		bool IsColliding(CritterInterface &other) override;

 		const float* GetPosition() const override;
 		const float* GetSize() const override;
 		const std::string GetName() const override;
 		const float GetBaseSpeed() const override;
 		const int GetMaxAge() const override;
 		const int GetCurrentAge() const override;
 		//const BehaviourInterface GetBehaviour() const = 0;
 		const bool GetMultiBehaviour() const override;

 		void Draw(UImg & support) override;

 };