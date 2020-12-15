//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_SHEEP_H
#define CODE_V1_1_SHEEP_H
#include "BehaviourInterface.h"
#include "CritterInterface.h"

class Sheep : public BehaviourInterface {
public:
    void NextMove(CritterInterface* critter, float direction[2], std::vector<std::shared_ptr<CritterInterface>> listcritters);
    int * GetColor();
    BehaviourInterface* clone() override;

private:
    int color[3] = {0,0,0};
};


#endif //CODE_V1_1_SHEEP_H
