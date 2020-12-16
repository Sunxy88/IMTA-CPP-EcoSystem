#include "CritterAccessoryDecorator.h"

class CritterWithCamouflage : public CritterAccessoryDecorator{

private:
    float camouflageCapacity;

public:
    CritterWithCamouflage(CritterInterface* component_,float camouflageCapacity_);
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
    CritterInterface* clone() override;

};