//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_CRITTERINTERFACE_H
#define CODE_V1_1_CRITTERINTERFACE_H
#include "BehaviourInterface.h"

class CritterInterface {
public:
    virtual void Move() = 0;
    virtual void Draw() = 0;
    virtual bool IsColliding(CritterInterface critterInterface) = 0;
    virtual float CalculateSpeed() = 0;
    virtual float CalculateCollisionResistance() = 0;
    virtual float CalculateCamouflageCapacity() = 0;
    virtual CritterInterface * Detect() = 0;
    virtual void Update() = 0;
    virtual void ChangeBehaviour(BehaviourInterface behaviourInterface) = 0;
    virtual float * GetPosition() = 0;
    virtual float * GetSize() = 0;
    virtual float * GetDirection() = 0;
    virtual ~CritterInterface() {};
};


#endif //CODE_V1_1_CRITTERINTERFACE_H
