DEFINES =
LIBS = OGRE OIS
CXX = g++
CXXFLAGS = $(shell pkg-config --cflags $(LIBS)) $(DEFINES) 
CPPFLAGS += -I ./include
LD = g++
LDFLAGS = $(shell pkg-config --libs $(LIBS))

#The meat!
SOURCES= RunApplication.cpp HybridApplication.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE = RunApplication

vpath %.cpp src

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

HybridApplication.o: include/HybridApplication.h

clean:
	rm -f $(EXECUTABLE) 
	rm -f *.o


