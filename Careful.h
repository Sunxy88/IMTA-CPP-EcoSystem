//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_CAREFUL_H
#define CODE_V1_1_CAREFUL_H
#include "BehaviourInterface.h"
#include "CritterInterface.h"

/**
 * 对应prévoyante，预估周围虫子的方向并避免碰撞
 */
class Careful : public BehaviourInterface {
public:
    float * NextMove(CritterInterface critter);
    int * GetColor();

private:
    int color[3];
};


#endif //CODE_V1_1_CAREFUL_H
