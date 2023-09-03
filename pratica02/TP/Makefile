# Compilador C++
CC = g++

# Flags de compilação
CFLAGS = -Wall -pg -std=c++11 -Iinclude

# Diretórios
SRC = src
OBJ = obj
BIN = bin
INC = include

# Arquivos fonte
SRCS = $(wildcard $(SRC)/*.cpp)

# Nomes dos objetos correspondentes
OBJS = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))

# Nome do executável
EXE = $(BIN)/main

# Regra padrão
all: $(EXE)

# Regra para compilar os objetos
$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@


# Regra para o executável
$(EXE): $(OBJS)
	@mkdir -p $(@D)
	$(CC) -o $(EXE) $(OBJS) -pg

# Regra para rodar o programa
run: $(EXE)
	./$(EXE) -f -n 5
	./$(EXE) -b -n 5

# Regra para limpar arquivos gerados
clean:
	rm -rf $(OBJ) $(BIN) gmon.out

