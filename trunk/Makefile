CC=gcc
CPP=g++
CFLAGS=
CXXFLAGS=
LD=gcc
LDFLAGS=

OBJECTS=main.o vector.o
TARGET=vector

all: $(TARGET)

clean:   
	rm $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS) 
	$(CPP) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

vector.o: vector.cpp
	$(CPP) $(CXXFLAGS) -c vector.cpp

main.o: main.cpp
	$(CPP) $(CXXFLAGS) -c main.cpp

