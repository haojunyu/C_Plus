SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,%.o,$(notdir ${SRC}))

TARGET = main

CC = g++
CFLAGS = -g -Wall

${TARGET}:${OBJ}
	$(CC) ${OBJ} -o $@

./%.o:./%.cpp
	$(CC) -c $< -o $@

clean:
	find . -name '*.o' -exec rm -rf {} \;

