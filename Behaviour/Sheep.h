//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_SHEEP_H
#define CODE_V1_1_SHEEP_H
#include "BehaviourInterface.h"
#include "CritterInterface.h"

class Sheep : public BehaviourInterface {
public:
    float * NextMove(CritterInterface* critter, Environment & env);
    int * GetColor();

private:
    int color[3] = {0,0,0};
};


#endif //CODE_V1_1_SHEEP_H
