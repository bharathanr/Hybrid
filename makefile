DEFINES =
LIBS = OGRE OIS
CXX = g++
CXXFLAGS = $(shell pkg-config --cflags $(LIBS)) $(DEFINES) 
CPPFLAGS += -I ./include
LD = g++
LDFLAGS = $(shell pkg-config --libs $(LIBS))

#The meat!
SOURCES= Application.cpp HybridApplication.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE = Application

vpath %.cpp src

all: $(SOURCES) $(EXECUTABLE)
	g++ $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)

clean:
	rm -f Application
	rm -f *.o


