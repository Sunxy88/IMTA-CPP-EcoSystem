main : main.cpp  Behaviour/BehaviourInterface.o Behaviour/Kamikaze.o Behaviour/Fearful.o Behaviour/Sheep.o Decorator/CritterAccessoryDecorator.o Decorator/CritterWithFin.o Decorator/CritterWithCamouflage.o Decorator/CritterWithShell.o SensorDecorator/CritterSensorDecorator.o SensorDecorator/CritterWithEar.o SensorDecorator/CritterWithEye.o CritterInterface.o BaseCritter.o CritterFactory.o Environment.o Aquarium.o
	g++ -Wall -std=c++14 -o main main.cpp   BehaviourInterface.o Kamikaze.o Fearful.o Sheep.o  CritterAccessoryDecorator.o CritterWithFin.o CritterWithCamouflage.o CritterWithShell.o CritterSensorDecorator.o CritterWithEar.o CritterWithEye.o CritterInterface.o BaseCritter.o CritterFactory.o  Environment.o Aquarium.o -I . -lX11 -lpthread

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

Behaviour/Fearful.o : Behaviour/Fearful.h Behaviour/Fearful.cpp
	g++ -Wall -std=c++14  -c Behaviour/Fearful.cpp -I .

Behaviour/Sheep.o : Behaviour/Sheep.h Behaviour/Sheep.cpp
	g++ -Wall -std=c++14  -c Behaviour/Sheep.cpp -I .

Decorator/CritterAccessoryDecorator.o : Decorator/CritterAccessoryDecorator.h Decorator/CritterAccessoryDecorator.cpp
	g++ -Wall -std=c++14  -c Decorator/CritterAccessoryDecorator.cpp -I .

Decorator/CritterWithFin.o : Decorator/CritterWithFin.h Decorator/CritterWithFin.cpp
	g++ -Wall -std=c++14  -c Decorator/CritterWithFin.cpp -I .

Decorator/CritterWithShell.o : Decorator/CritterWithShell.h Decorator/CritterWithShell.cpp
	g++ -Wall -std=c++14  -c Decorator/CritterWithShell.cpp -I .

Decorator/CritterWithCamouflage.o : Decorator/CritterWithCamouflage.h Decorator/CritterWithCamouflage.cpp
	g++ -Wall -std=c++14  -c Decorator/CritterWithCamouflage.cpp -I .

SensorDecorator/CritterSensorDecorator.o : SensorDecorator/CritterSensorDecorator.h SensorDecorator/CritterSensorDecorator.cpp
	g++ -Wall -std=c++14  -c SensorDecorator/CritterSensorDecorator.cpp -I .

SensorDecorator/CritterWithEar.o : SensorDecorator/CritterWithEar.h SensorDecorator/CritterWithEar.cpp
	g++ -Wall -std=c++14  -c SensorDecorator/CritterWithEar.cpp -I .

SensorDecorator/CritterWithEye.o : SensorDecorator/CritterWithEye.h SensorDecorator/CritterWithEye.cpp
	g++ -Wall -std=c++14  -c SensorDecorator/CritterWithEye.cpp -I .




