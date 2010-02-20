#My makefile for unit testing the Application core

#The output directory
OUTDIR=./bin

#Compilation/Linking/Loading flags
DEFINES = -g
LIBS =
BOOST_LIBS = boost_signals
CXXFLAGS = $(DEFINES)
CPPFLAGS = -I ../src
LD = g++
LDFLAGS = -L/usr/local/boost_1_41_0/ -l$(BOOST_LIBS)

#Custom variables
BINARIES = test1

#Tell make where to find the source files
vpath %.cpp src

#The rules for make
test1: test1.o
	$(LD) $(LDFLAGS) test1.o -o $(OUTDIR)/test1
test1.o: test1.cpp

clean:
	rm *.o
	rm $(OUTDIR)/$(BINARIES)
