# Makefile do projeto

# Pasta onde ficará o arquivo compilado
PASTA_BIN = bin

# Salvando arquivos .c
ARQUIVOS_C = $(shell find -type f -name "*.c")

# Compilador
COMPILE = gcc

# Flags
FLAGS = -g -lm 

all: 
	@$(COMPILE) $(ARQUIVOS_C) $(FLAGS) -o ./bin/main.o -lm 
	@-./bin/main.o

.PHONY: all
