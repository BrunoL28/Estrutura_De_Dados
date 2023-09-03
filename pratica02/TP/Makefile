# Compilador C++
CC = g++

# Flags de compilação
CXXFLAGS = -Wall -pg -std=c++11 -I$(INC)

# Diretórios
SRC = src
OBJ = obj
BIN = bin
INC = include

# Arquivos de origem
SRCS = $(SRC)/main.cpp $(SRC)/fatorial.cpp $(SRC)/fibonacci.cpp $(SRC)/tempo.cpp

# Nomes dos objetos correspondentes
OBJS = $(OBJ)/main.o $(OBJ)/fatorial.o $(OBJ)/fibonacci.o $(OBJ)/tempo.o

# Nome do executável
EXE = $(BIN)/main

# Regra padrão
all: $(EXE)

# Regra para compilar os objetos
$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $(OBJ)/%.o -o $(SRC)/%.cpp


# Regra para o executável
$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) -pg

# Regra para rodar o programa
run: $(EXE)
	./$(EXE) -h
	./$(EXE) -f -n 5
	./$(EXE) -b -n 5

# Regra para limpar arquivos gerados
clean:
	rm -rf $(OBJ) $(BIN) gmon.out

