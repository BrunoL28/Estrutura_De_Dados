# Compilador C++
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -pg -std=c++11 -I$(INC)

# Diretórios
INC = include
BIN = bin
OBJ = obj
SRC = src

OBJS = $(OBJ)/fatorial.o $(OBJ)/fibonacci.o $(OBJ)/main.o $(OBJ)/utils.o
HDRS = $(INC)/fatorial.hpp $(INC)/fibonacci.hpp $(INC)/msgassert.hpp $(INC)/tempo.hpp $(INC)/utils.hpp

EXE = $(BIN)/main

all: $(EXE)
	$(EXE)

run: $(EXE)
	$(EXE) -h
	$(EXE) -f -n 5
	$(EXE) -b -n 5

$(EXE): $(OBJS)
	$(CXX) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/fatorial.o: $(HDRS) $(SRC)/fatorial.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/fatorial.o $(SRC)/fatorial.cpp

$(OBJ)/fibonacci.o: $(HDRS) $(SRC)/fibonacci.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.cpp

$(OBJ)/utils.o: $(HDRS) $(SRC)/utils.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/utils.o $(SRC)/utils.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
