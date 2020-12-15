
#pragma once

#ifndef  CRITTERACCESSORYDECORATOR_H
#define  CRITTERACCESSORYDECORATOR_H_


#include "../CritterInterface.h"

class CritterAccessoryDecorator : public CritterInterface

{
protected:
    
    CritterInterface* component;

public:
    CritterAccessoryDecorator(CritterInterface* component_ );
    virtual ~CritterAccessoryDecorator();

};

#endif