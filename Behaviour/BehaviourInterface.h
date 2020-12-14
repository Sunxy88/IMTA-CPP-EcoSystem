//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_BEHAVIOURINTERFACE_H
#define CODE_V1_1_BEHAVIOURINTERFACE_H


class BehaviourInterface {
public:
    BehaviourInterface();
    virtual ~BehaviourInterface();
    virtual float* NextMove(CritterInterface *critter, Environment & env) = 0;
    virtual int* GetColor() = 0;
};


#endif //CODE_V1_1_BEHAVIOURINTERFACE_H
