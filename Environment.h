#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H_


#include "UImg.h"
#include "CritterInterface.h"

#include <iostream>
#include <vector>

using namespace std;


class Environment : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<CritterInterface>   listCritter;

public :
   Environment( int _width, int _height );
   ~Environment( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   std::vector<CritterInterface> GetCritters();
   void Draw();
   void UpdateCritters();
   void AddCritter();

};


#endif
