#include "Environment.h"

#include <cstdlib>
#include <ctime>


const T    Environment::white[] = { (T)255, (T)255, (T)255 };


Environment::Environment( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Environment::~Environment( void )
{

   cout << "dest Milieu" << endl;

}


void Environment::Draw()
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<CritterInterface>::iterator it = listCritter.begin() ; it != listCritter.end() ; ++it )
   {

      it->Draw( *this );

   } // for

}


void Environment::UpdateCritters()
{

   for ( std::vector<CritterInterface>::iterator it = listCritter.begin() ; it != listCritter.end() ; ++it )
   {

      it->Draw( *this );

   } // for

}



