main : main.cpp Environment.o Aquarium.o BaseCritter.o Fearful.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o -I . -lX11 -lpthread

Environment.o : Environment.h Environment.cpp
	g++ -Wall -std=c++11  -c Environment.cpp -I .

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

BaseCritter.o : BaseCritter.h BaseCritter.cpp
	g++ -Wall -std=c++11  -c BaseCritter.cpp -I .

Fearful.o : Behaviour/Fearful.h Behaviour/Fearful.cpp
	g++ -Wall -std=c++11  -c Behaviour/Fearful.cpp -I .
