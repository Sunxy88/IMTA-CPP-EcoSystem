#include "Aquarium.h"

#include "Environment.h"
#include "Behaviour/Kamikaze.h"
#include "Behaviour/Sheep.h"
#include "Behaviour/Fearful.h"


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();

   cout << "const Aquarium" << endl;

   flotte = new Environment( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}

void Aquarium::Birth()
{
   flotte->AddCritter();
}

void Aquarium::Kill(int id)
{
   flotte->getCritterById(id)->setIsDying(true);
}


void Aquarium::SetBehavior(int id, string const & strategy)
{
   delete flotte->getCritterById(id)->GetBehaviour();
   if(strategy.compare("kamikaze") == 0){
         flotte->getCritterById(id)->ChangeBehaviour(new Kamikaze());
   }
   else if (strategy.compare("sheep") == 0){
      flotte->getCritterById(id)->ChangeBehaviour(new Sheep());
   }
   else{
      flotte->getCritterById(id)->ChangeBehaviour(new Fearful());
   }
}



void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if (is_keyESC()){
         close();
      }

      if (is_key(cimg::keyB)){
         this->Birth(); 

      }

      if (is_key(cimg::keyK)){
         int critter;
         cout << "Quelle créature voulez vous tuer ?"<<endl;
         cin>>critter;
         this->Kill(critter);
      }

      if (is_key(cimg::keyS)){
         int critter;
         std::string behavior;
         cout << "De quelle créature voulez-vous modifier le comportement ?"<<endl;
         cin >> critter;
         cout << "Quel comportement voulez-vous lui attribuer ?"<<endl;
         cin >> behavior;
         SetBehavior(critter,behavior);
      }
      
      flotte->UpdateCritters();
      flotte->Draw();
      display( *flotte );

      wait( delay );

   } // while

}
