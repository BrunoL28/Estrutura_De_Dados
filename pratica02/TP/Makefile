CXX = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN_DIR = bin
OBJS = $(OBJ)/fatorial.o $(OBJ)/fibonacci.o $(OBJ)/tempo.o $(OBJ)/main.o
HDRS = $(INC)/fatorial.hpp $(INC)/fibonacci.hpp $(INC)/msgassert.hpp $(INC)/tempo.hpp
CXXFLAGS = -Wall -pg -std=c++11 -I$(INC)

EXE = $(BIN_DIR)/main

all: $(EXE)
	$(EXE)

$(EXE): $(OBJS)
	$(CXX) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/fatorial.o: $(HDRS) $(SRC)/fatorial.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJ)/fatorial.o $(SRC)/fatorial.cpp

$(OBJ)/fibonacci.o: $(HDRS) $(SRC)/fibonacci.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.cpp

$(OBJ)/tempo.o: $(HDRS) $(SRC)/tempo.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJ)/tempo.o $(SRC)/tempo.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJ)/main.o $(SRC)/main.cpp

run: $(EXE)
	$(EXE) -f -n 5
	$(EXE) -b -n 5

clean:
	rm -f $(EXE) $(OBJS) gmon.out
