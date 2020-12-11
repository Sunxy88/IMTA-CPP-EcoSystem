#include "Aquarium.h"

#include "Environnement.h"


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{


   cout << "const Aquarium" << endl;

   flotte = new Environnement();
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
   delete flotte->GetCritterById(id);
}

void Aquarium::SetBehavior(int id, String strategy)
{
   flotte->GetCritterById->ChangeBehaviour(strategy);
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
         String behavior;
         cout << "De quelle créature voulez-vous modifier le comportement ?"<<endl;
         cin>>critter;
         cout << "Quel comportement voulez-vous lui attribuer ?"<<endl;
         cin<<behavior;
         this->setBehavior(critter,behavior);
      }



      flotte->UpdateCritters();
      Draw( *flotte );

      wait( delay );

   } // while

}
