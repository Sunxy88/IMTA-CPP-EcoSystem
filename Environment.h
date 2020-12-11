#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H_


#include "UImg.h"
#include "BaseCritter.h"

#include <iostream>
#include <vector>

using namespace std;


class Environment : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<BaseCritter>   listCritter;

public :
   Environment( int _width, int _height );
   ~Environment( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void addMember( const BaseCritter & b ) { listCritter.push_back(b); }
   std::vector<BaseCritter> GetCritters();
   void Draw();
   void UpdateCritters();
   void AddCritter();

};


#endif
