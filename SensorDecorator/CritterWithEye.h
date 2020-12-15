/*
 * CritterWithEye.h
 *
 *      Author: Sami RMILI
 */
#pragma once

#ifndef  CRITTERWITHEYE_H
#define  CRITTERWITHEYE_H_

#include "CritterSensorDecorator.h"
#include "CritterInterface.h"

using namespace std;

class CritterWithEye : public CritterSensorDecorator{
private:
    float angle;
    float distance;
    float capacity;

public:
	CritterWithEye(CritterInterface* critter, float angle, float distance, float capacity);
	~CritterWithEye();

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
	bool IsEyeColliding(CritterInterface &other); // Only this class has this method
    std::vector<std::shared_ptr<CritterInterface>> Detect(std::vector<std::shared_ptr<CritterInterface>> critters) override;

    const float* GetPosition() const override;
    const float* GetDirection() const override;
    float* GetModifiableDir() override;
    const float* GetSize() const override;
    const int GetId() const override;
    const float GetBaseSpeed() const override;
    const int GetLifespan() const override;
    const int GetCurrentAge() const override;
    BehaviourInterface* GetBehaviour()  override;
    const bool GetMultiBehaviour() const override;

    void Draw(UImg & support) override;
	
};


#endif /*  CRITTERWITHEYE_H_*/