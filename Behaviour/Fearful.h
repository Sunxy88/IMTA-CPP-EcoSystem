//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_FEARFUL_H
#define CODE_V1_1_FEARFUL_H
#include "CritterInterface.h"
#include "BehaviourInterface.h"

class Fearful : public BehaviourInterface {
public:
    float * NextMove(CritterInterface critter);
    int * GetColor();

private:
    int color[3];
};


#endif //CODE_V1_1_FEARFUL_H
