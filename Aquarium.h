#pragma once
#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>
#include "Environment.h"
using namespace std;
using namespace cimg_library;





class Aquarium : public CImgDisplay
{

private :
   Environment       * flotte;

   int            delay;

public :
   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );

   Environment & getMilieu( void ) { return *flotte; }

   void run( void );

};


#endif
