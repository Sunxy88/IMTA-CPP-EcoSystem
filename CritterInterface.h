#include <vector>
#include <iostream>

#include "CritterSensorInterface.h"

 class CritterInterface : public CritterSensorInterface{


 	public :
 		static const int DIM = 2;

 		virtual float CalculateSpeed() = 0;
 		virtual float CalculateCollisionResistance() = 0;
 		virtual float CalculateCamouflageCapacity() = 0;
 		virtual std::vector<CritterInterface> Detect() = 0;
 		//virtual void Move() = 0;
 		virtual void Update() = 0;
 		virtual bool IsColliding(CritterInterface &other) = 0;
 		virtual const float* GetPosition() const = 0;
 		virtual const float* GetSize() const = 0;


 };