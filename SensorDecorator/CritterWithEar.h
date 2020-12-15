/*
 * CritterWithEar.h
 *
 *      Author: Sami RMILI
 */
#pragma once

#ifndef  CRITTERWITHEAR_H
#define  CRITTERWITHEAR_H_

#include "CritterSensorDecorator.h"
#include "CritterInterface.h"

using namespace std;


class CritterWithEar : public CritterSensorDecorator{
private:
    float radius;
    float capacity;

public:
	CritterWithEar(CritterInterface* critter, float radius, float capacity);
	~CritterWithEar();

	void AttemptSurvive() override;
    bool IsDying() override;
    void setIsDying(bool dead) override;
    void Bounce();
    float CalculateSpeed() override;
    float CalculateCollisionResistance() override;
    float CalculateCamouflageCapacity() override;
    void ChangeBehaviour(BehaviourInterface* newBehaviour) override;
    void Move(Environment & env, float speed) override;
    void Update(Environment & env, float speed) override;
    bool IsColliding(CritterInterface &other) override;
	bool IsEarColliding(CritterInterface &other); // Only this class has this method
    std::vector<std::shared_ptr<CritterInterface>> Detect(std::vector<std::shared_ptr<CritterInterface>> critters) override;

    const float* GetPosition() const override;
    const float* GetDirection() const override;
    const float* GetSize() const override;
    const int GetId() const override;
    const float GetBaseSpeed() const override;
    const int GetLifespan() const override;
    const int GetCurrentAge() const override;
    BehaviourInterface* GetBehaviour()  override;
    const bool GetMultiBehaviour() const override;

    void Draw(UImg & support) override;
};



#endif /*  CRITTERWITHEAR_H_*/