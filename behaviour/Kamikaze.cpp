//
// Created by Xi Sung on 2020/11/27.
//
#include <math.h>
#include "float.h"
#include "limits.h"
#include "Kamikaze.h"

int * Kamikaze::GetColor() {
    return color;
}

float * Kamikaze::NextMove(CritterInterface critter) {
    vector<CritterInterface> critters = Environment::GetInstance().CritterInterface();

}

float getDistance(float * p1, float * p2) {
    return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5)
}