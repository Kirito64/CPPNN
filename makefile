C_SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJ = ${C_SOURCES:.cpp=.o}
CFLAGS = 

MAIN = main
CC = g++
LINKER = ld

run: ${MAIN}
	./${MAIN}

main: ${OBJ}
	${CC} ${CFLAGS} $^ -o $@ -lm

# Generic rules
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@ -lm

clean:
	rm *.o  ${MAIN}