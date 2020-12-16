//
// Created by Xi Sung on 12/17/20.
//

#ifndef CODE_V1_1_MULTIPLE_H
#define CODE_V1_1_MULTIPLE_H
#include "BehaviourInterface.h"
#include "Careful.h"
#include "Fearful.h"
#include "Kamikaze.h"
#include "Sheep.h"

class Multiple : public BehaviourInterface {
public:
    Multiple();
    ~Multiple();
    void NextMove(CritterInterface *critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) override;
    int * GetColor();
    BehaviourInterface* clone() override;

private:
    int color[3] = {0,255,0};
    BehaviourInterface* behaviours[4] = {new Careful(), new Sheep(), new Kamikaze(), new Fearful()};
    float getDistance(const float * p1, const float * p2);
};


#endif //CODE_V1_1_MULTIPLE_H
