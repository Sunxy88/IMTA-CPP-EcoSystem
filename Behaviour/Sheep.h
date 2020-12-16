//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_SHEEP_H
#define CODE_V1_1_SHEEP_H
#include "BehaviourInterface.h"

// A sheep critter adjusts its direction to the average direction
class Sheep : public BehaviourInterface {
public:
    Sheep();
    ~Sheep();
    void NextMove(CritterInterface* critter, std::vector<std::shared_ptr<CritterInterface>> listcritters);
    int * GetColor();
    BehaviourInterface* clone() override;

private:
    int color[3] = {0,0,0};
};


#endif //CODE_V1_1_SHEEP_H
