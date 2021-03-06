//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_BEHAVIOURINTERFACE_H
#define CODE_V1_1_BEHAVIOURINTERFACE_H
#include "../CritterInterface.h"


class CritterInterface;

// The strategy interface exploded to use.
class BehaviourInterface {
public:
    BehaviourInterface();
    virtual ~BehaviourInterface();
    virtual void NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters) = 0;
    virtual int* GetColor() = 0;
    virtual BehaviourInterface* clone() = 0;
};


#endif //CODE_V1_1_BEHAVIOURINTERFACE_H
