OBJECTS = BaseCritter.o CritterFactory.o Main.o
EXEC = game

FLAGS = -Wall

CC = g++

# Automated compiling       
all: $(OBJECTS)
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)

