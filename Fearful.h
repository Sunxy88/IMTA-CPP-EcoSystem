//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_FEARFUL_H
#define CODE_V1_1_FEARFUL_H
#include "CritterInterface.h"
#include "BehaviourInterface.h"

/**
 * 对应peureux，当周围虫子数量过多时会向相反方向行动
 */
class Fearful : public BehaviourInterface {
public:
    float * NextMove(CritterInterface critter);
    int * GetColor();

private:
    int color[3];
};


#endif //CODE_V1_1_FEARFUL_H
