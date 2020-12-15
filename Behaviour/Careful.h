//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_CAREFUL_H
#define CODE_V1_1_CAREFUL_H
#include "BehaviourInterface.h"
#include "CritterInterface.h"

class Careful : public BehaviourInterface {
public:
    float*  NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) override;
    int*  GetColor();

private:
    int color[3] = {0,255,0};
    float getDistance(const float * p1, const float * p2);
};


#endif //CODE_V1_1_CAREFUL_H
