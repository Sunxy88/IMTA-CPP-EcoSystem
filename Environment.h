#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H_

#include "memory"
#include "UImg.h"
#include "CritterInterface.h"
#include "CritterFactory.h"
#include <iostream>
#include <vector>

using namespace std;


class Environment : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<std::shared_ptr<CritterInterface>>   listCritter;
   CritterFactory* critterFactory;

public :
   Environment( int _width, int _height );
   ~Environment( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };


   std::vector<std::shared_ptr<CritterInterface>> GetCritters();
   void Draw();
   void UpdateCritters();
   void AddCritter();
   void RemoveDeadCritters();
   CritterInterface* getCritterById(int id);
   int getWidth();
   int getHeight();
};


#endif
