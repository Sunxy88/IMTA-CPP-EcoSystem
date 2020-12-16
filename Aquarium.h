#pragma once
#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_

#include "Environment.h"
#include <iostream>
#include <CImg.h>
using namespace std;
using namespace cimg_library;


class Environment;


class Aquarium : public CImgDisplay
{

private :
   Environment       * flotte;

   int            delay;

public :
   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );

   void Birth();
   
   void Kill(int);

   void SetBehavior(int, string const &str1);

   Environment & getMilieu( void ) { return *flotte; }

   void run( void );

};


#endif
