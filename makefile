# Makefile do projeto

# Parte para tratar a parte principal dos códigos

# Nome do arquivo principal
NOME_MAIN = main

# Pasta onde ficará o arquivo compilado
PASTA_BIN = bin
$(shell mkdir bin)

# Salvando arquivos .c
ARQUIVOS_C = $(shell find ./src -type f -name "*.c")

# Diretórios para arquivos da pasta src  
DIRETORIOS := $(shell find ./src -type d)

# Parte para tratar os arquivos .o

# Arquivos de tipo objeto
OBJETOS = $(patsubst ./src/%.c,./obj/%.o,$(ARQUIVOS_C))

# Diretórios para arquivos do tipo objeto
DIRETORIOS_DE_OBJETOS = $(subst src,obj, $(DIRETORIOS))
$(foreach diretorio, $(DIRETORIOS_DE_OBJETOS), $(shell mkdir -p $(diretorio)))

# Compilador
COMPILE = gcc

# Flags
FLAGS = -c -g -lm

all: $(NOME_MAIN) clean

$(NOME_MAIN): $(OBJETOS)
	$(COMPILE) $^ -o $(PASTA_BIN)/$@ -lm -g

./obj/%.o: ./src/%.c
	$(COMPILE) $^ $(FLAGS) -o $@

clean:
	rm -rf obj

.PHONY: all clean
