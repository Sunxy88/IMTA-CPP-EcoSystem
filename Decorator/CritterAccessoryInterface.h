
class CritterAccessoryInterface
{
public:
    CritterAccessoryInterface(){}
    virtual ~CritterAccessoryInterface(){}
    virtual float CalculateSpeed() = 0;
    virtual float CalculateCollisionResistance() = 0;
    virtual float CalculateCamouflageCapacity() = 0;

};
