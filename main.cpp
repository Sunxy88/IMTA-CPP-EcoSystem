#include "Aquarium.h"
#include "Milieu.h"
#include "BaseCritter.h"
#include "Fearful.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 20; ++i ){
      Fearful* fear = new Fearful();
      float position[2] = { 100, 100 };
      float size[2] = {5,5};
      BaseCritter bs("id", 1.5, 200, position , size, fear ,false);
      ecosysteme.getMilieu().addMember(bs);
      
   }
      
   ecosysteme.run();


   return 0;

}
