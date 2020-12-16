//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_FEARFUL_H
#define CODE_V1_1_FEARFUL_H
#include "../CritterInterface.h"
#include "BehaviourInterface.h"

class Fearful : public BehaviourInterface {
public:
    Fearful();
    ~Fearful();
    void NextMove(CritterInterface *critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) override;
    int * GetColor();
    BehaviourInterface* clone() override;

private:
    int color[3] = {0,0,255};
};


#endif //CODE_V1_1_FEARFUL_H
