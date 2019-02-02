
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#	Makefile for Unix & Linux Systems	#
#	using a GNU C++ compiler	#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# compiler flags
#	-g	--Enable debugging
#	-Wall	--Turn on all warnings
#	-D_USE_FIXED_PROTOTYPES_
#	--Force the compiler to use the correct headers
#	-ansi	--Don't use GNU ext; do use ansi standard.

CXX = g++ --std=c++11
CXXFLAGS = -O3 -Wall
#DEBUGFLAGS = -g -Wall
INCLUDE = -I ./bus -I ./components

#Link command:
railctrl: ./src/main.o ./bus/BusHandler.o ./bus/TestBusInterface.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) ./src/main.o ./bus/BusHandler.o ./bus/TestBusInterface.o -o railctrl

#Compilation commands:
./src/main.o: ./src/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./src/main.cpp -o ./src/main.o

./bus/BusHandler.o: ./bus/BusHandler.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./bus/BusHandler.cpp -o ./bus/BusHandler.o

./bus/TestBusInterface.o: ./bus/TestBusInterface.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./bus/TestBusInterface.cpp -o ./bus/TestBusInterface.o


#make clean
clean:
	rm	-fr	./*/*.o ./railctrl
