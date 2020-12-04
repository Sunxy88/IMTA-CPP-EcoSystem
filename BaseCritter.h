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
 		//BehaviourInterface behaviour;
 		bool isMultiBehaviour;
 		bool isDead;

 	private :
 		void MoveTowards(const float newDirection[DIM]);

 	public :
 		BaseCritter(std::string name, float baseSpeed, float position[DIM], float size[DIM], bool isMultiBehaviour = false);
 		~BaseCritter();

 		void Clone();
 		void AttemptSurvive(const CritterInterface &other);
 		bool IsDying();
 		void Bounce(const CritterInterface &other);
 		float CalculateSpeed() override;
 		float CalculateCollisionResistance() override;
 		float CalculateCamouflageCapacity() override;
 		std::vector<CritterInterface> Detect() override;
 		//void Move() override;
 		void Update() override;
 		bool IsColliding(CritterInterface &other) override;

 		const float* GetPosition() const override;
 		const float* GetSize() const override;



 };