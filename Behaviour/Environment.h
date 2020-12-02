//
// Created by Xi Sung on 2020/11/27.
//

#ifndef CODE_V1_1_ENVIRONMENT_H
#define CODE_V1_1_ENVIRONMENT_H
#include "CritterInterface.h"
using std::vector;

class Environment {
public:
    static Environment GetInstance();
    CritterInterface * CritterInterface();
};


#endif //CODE_V1_1_ENVIRONMENT_H
