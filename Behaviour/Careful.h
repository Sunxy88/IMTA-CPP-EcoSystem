//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_CAREFUL_H
#define CODE_V1_1_CAREFUL_H
#include "BehaviourInterface.h"
#include "CritterInterface.h"

class Careful : public BehaviourInterface {
public:
    float*  NextMove(CritterInterface* critter);
    int*  GetColor();

private:
    int color[3] = {0,255,0};
};


#endif //CODE_V1_1_CAREFUL_H
