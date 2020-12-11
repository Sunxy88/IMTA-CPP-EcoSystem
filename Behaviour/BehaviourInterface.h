//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_BEHAVIOURINTERFACE_H
#define CODE_V1_1_BEHAVIOURINTERFACE_H
#include "CritterInterface.h"


class BehaviourInterface {
public:
    virtual float* NextMove(CritterInterface *critter) = 0;
    virtual int* GetColor() = 0;
    virtual ~BehaviourInterface() {};
};


#endif //CODE_V1_1_BEHAVIOURINTERFACE_H
