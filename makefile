
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
INCLUDE = -I ./components -I ./bus -I ./module -I ./layout

#Link command:
railctrl: ./src/main.o ./bus/BusHandler.o ./bus/TestBusInterface.o ./module/Module.o ./components/Turnout.o ./components/Sign.o ./components/Track.o ./components/ComponentFactory.o ./module/Moduleloader.o ./layout/Layout.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) ./src/main.o ./bus/BusHandler.o ./bus/TestBusInterface.o ./module/Module.o ./components/Turnout.o ./components/Sign.o ./components/Track.o ./components/ComponentFactory.o ./module/Moduleloader.o ./layout/Layout.o -o railctrl

#Compilation commands:
./src/main.o: ./src/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./src/main.cpp -o ./src/main.o

./bus/BusHandler.o: ./bus/BusHandler.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./bus/BusHandler.cpp -o ./bus/BusHandler.o

./bus/TestBusInterface.o: ./bus/TestBusInterface.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./bus/TestBusInterface.cpp -o ./bus/TestBusInterface.o

./components/Turnout.o: ./components/Turnout.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./components/Turnout.cpp -o ./components/Turnout.o

./components/Sign.o: ./components/Sign.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./components/Sign.cpp -o ./components/Sign.o

./components/Track.o: ./components/Track.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./components/Track.cpp -o ./components/Track.o

./components/ComponentFactory.o: ./components/ComponentFactory.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./components/ComponentFactory.cpp -o ./components/ComponentFactory.o

./module/Module.o: ./module/Module.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./module/Module.cpp -o ./module/Module.o

./module/Moduleloader.o: ./module/Moduleloader.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./module/Moduleloader.cpp -o ./module/Moduleloader.o

./layout/Layout.o: ./layout/Layout.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ./layout/Layout.cpp -o ./layout/Layout.o


#make clean
clean:
	rm	-fr	./*/*.o ./railctrl
