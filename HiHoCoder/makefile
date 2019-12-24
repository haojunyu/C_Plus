DIR_SRC = .
DIR_OBJ = .
DIR_BIN = .
#DIR_INC = ../include

SRC = $(wildcard ${DIR_SRC}/*.c)
#OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC}))
OBJ = 1039.o

TARGET = hiho 
BIN_TARGET = ${DIR_BIN}/${TARGET}

CC = gcc 
CFLAGS = -g -Wall 
#CFLAGS = -g -Wall -I${DIR_INC}

${BIN_TARGET}:${OBJ}
	$(CC) -g $(OBJ) -o $@

${DIR_OBJ}/%.o:${DIR_SRC}/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find ${DIR_OBJ} -name '*.o' -exec rm -rf {} \;
