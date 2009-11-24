DEFINES =
LIBS = OGRE OIS
CXX = g++
CXXFLAGS = $(shell pkg-config --cflags $(LIBS)) $(DEFINES) 
CPPFLAGS += -I ./include
LD = g++
LDFLAGS = $(shell pkg-config --libs $(LIBS))

vpath %.cpp src

all: Application

clean:
	rm -f Application
	rm -f *.o


