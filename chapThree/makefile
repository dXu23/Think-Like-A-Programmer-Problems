CC=g++
FLAGS=-Wall -g

agentDriver: agent.o usefulArrayFunc.o
	$(CC) $(FLAGS) -o agentDriver usefulArrayFunc.o agent.o

agent.o: agent.cpp 
	$(CC) $(FLAGS) -c agent.cpp

usefulArrayFunc.o: usefulArrayFunc.cpp
	$(CC) $(FLAGS) -c usefulArrayFunc.cpp
