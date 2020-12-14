//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_KAMIKAZE_H
#define CODE_V1_1_KAMIKAZE_H
#include "BehaviourInterface.h"


class Kamikaze : public BehaviourInterface {
public:
    Kamikaze();
    ~Kamikaze();
    float * NextMove(CritterInterface *critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) override;
    int * GetColor();
    BehaviourInterface* clone() override;

private:
    int color[3] = {255,0,0};
    float getDistance(float * p1, float * p2);
};


#endif //CODE_V1_1_KAMIKAZE_H
