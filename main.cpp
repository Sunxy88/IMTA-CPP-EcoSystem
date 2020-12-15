#include "Aquarium.h"
#include "Milieu.h"
#include "BaseCritter.h"


#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 1000, 500, 30 );

   std::srand(std::time(NULL));
	std::rand();
   
   ecosysteme.getMilieu().AddCritter();
   ecosysteme.getMilieu().AddCritter();
   std::cout << ecosysteme.getMilieu().GetCritters().size() << std::endl;
   ecosysteme.run();

   return 0;

}
