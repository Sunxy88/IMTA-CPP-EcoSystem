//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_FEARFUL_H
#define CODE_V1_1_FEARFUL_H
#include "../BaseCritter.h"
#include "BehaviourInterface.h"
#include "../Environment.h"

class Fearful : public BehaviourInterface {
public:
    float * NextMove(BaseCritter* critter);
    int * GetColor();

private:
    int color[3];
};


#endif //CODE_V1_1_FEARFUL_H
