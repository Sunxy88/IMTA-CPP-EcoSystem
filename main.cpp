#include "Aquarium.h"
#include "BaseCritter.h"
#include "Simulation.h"


#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 1280, 720, 30 );

   std::srand(std::time(NULL));
	std::rand();
   
   for( int i = 0; i < initialCritterNumber; i++){
         ecosysteme.getMilieu().AddCritter();
   }
   
   
   std::cout << ecosysteme.getMilieu().GetCritters().size() << std::endl;
   ecosysteme.run();

   return 0;

}
