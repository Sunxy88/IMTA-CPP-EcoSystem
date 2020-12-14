main : main.cpp    CritterInterface.o BaseCritter.o CritterFactory.o Environment.o Aquarium.o
	g++ -Wall -std=c++14 -o main main.cpp  CritterInterface.o BaseCritter.o CritterFactory.o  Environment.o Aquarium.o -I . -lX11 -lpthread

CritterInterface.o : CritterInterface.h CritterInterface.cpp
	g++ -Wall -std=c++14  -c CritterInterface.cpp -I .

BaseCritter.o : BaseCritter.h BaseCritter.cpp
	g++ -Wall -std=c++14  -c BaseCritter.cpp -I .


Environment.o : Environment.h Environment.cpp
	g++ -Wall -std=c++14  -c Environment.cpp -I .

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++14  -c Aquarium.cpp -I .

CritterFactory.o : CritterFactory.h CritterFactory.cpp
	g++ -Wall -std=c++14  -c CritterFactory.cpp -I .

Behaviour/BehaviourInterface.o : Behaviour/BehaviourInterface.h Behaviour/BehaviourInterface.cpp
	g++ -Wall -std=c++14  -c Behaviour/BehaviourInterface.cpp -I .

Behaviour/Kamikaze.o : Behaviour/Kamikaze.h Behaviour/Kamikaze.cpp
	g++ -Wall -std=c++14  -c Behaviour/Kamikaze.cpp -I .


