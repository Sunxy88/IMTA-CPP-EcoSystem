
#include "Environment.h"

#include <cstdlib>
#include <ctime>


const T    Environment::white[] = { (T)255, (T)255, (T)255 };


Environment::Environment( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{
   std::cout << "START" << std::endl;
   this->critterFactory = new CritterFactory();
   std::cout << "END" << std::endl;
   cout << "const Milieu" << endl;


}


Environment::~Environment( void )
{

   cout << "dest Milieu" << endl;
   delete critterFactory;

}


void Environment::Draw()
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<std::shared_ptr<CritterInterface>>::iterator it = listCritter.begin() ; it != listCritter.end() ; ++it )
   {
      
      (*it)->Draw( *this );
    
   } 

}


void Environment::UpdateCritters()
{

   // New Critters Spawning
   /*float r = ((float) std::rand()) / (float) RAND_MAX;
   if(r > spawnRate){
=======
   float r = ((float) std::rand()) / (float) RAND_MAX;
   if(r < spawnRate){
>>>>>>> f2c883eea8c364452fc365110251ee3d7a36a081
      std::cout << "a new Critter spawned  " << std::endl;
      AddCritter();
   }*/
   for ( std::vector<std::shared_ptr<CritterInterface>>::iterator it = listCritter.begin() ; it != listCritter.end() ; ++it )
   {
      /*if(std::rand() < spawnRate){
         std::cout << "Cloning :" << (*it)->GetId() << std::endl;
         AddCritter((*it)->clone());
      }*/
      
      (*it)->Update(*this, (*it)->CalculateSpeed());
      // Check for collision
      for ( std::vector<std::shared_ptr<CritterInterface>>::iterator it2 = listCritter.begin() ; it2 != listCritter.end() ; ++it2 ){
            if(it == it2) continue;
            if((*it)->IsColliding(*(*it2).get())){
               std::cout << "Colliding" << endl;
               if(!(*it)->IsDying())
               (*it)->AttemptSurvive();
               if(!(*it2)->IsDying())
               (*it2)->AttemptSurvive();

            }
            
      }

   } 
   
   RemoveDeadCritters();

}


void Environment::AddCritter(){
   AddCritter(this->critterFactory->CreateBaseCritter());
}

void Environment::AddCritter(CritterInterface* crit){
//    shared_ptr is employed here to simplify the management of memory and
//    to void the leak of memory since critter is easily created and easily dies.
   std::shared_ptr<CritterInterface> critter;
   critter.reset(crit);
   listCritter.push_back(critter);
}

void Environment::RemoveDeadCritters(){
   std::vector<std::shared_ptr<CritterInterface>>::iterator it = listCritter.begin();
   while(it != listCritter.end()){
      if((*it)->IsDying()){
            listCritter.erase(it);
      }else{
         it++;
      }
   } 
   
}

std::vector<std::shared_ptr<CritterInterface>> Environment::GetCritters(){
   return listCritter;
}

int Environment::getWidth(){
   return width;
}

int Environment::getHeight(){
   return height;
}

CritterInterface* Environment::getCritterById(int id){
   std::vector<std::shared_ptr<CritterInterface>>::iterator it = listCritter.begin();
   while(it != listCritter.end()){
      if((*it)->GetId() == id){
            return (*it).get();
      }else{
         it++;
      }
   } 
   return nullptr;
}





