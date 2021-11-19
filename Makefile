.PHONY : clean
.DEFAULT : objs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJS = faceRotation.o solveur.o main.o main
objs : ${OBJS}
faceRotation.o: faceRotation.c rubiksCube.h
	${CC} ${CFLAGS} -c $<
solveur.o: solveur.c solveur.h
	${CC} ${CFLAGS} -c $<
main.o: main.c solveur.h
	${CC} ${CFLAGS} -c $<
main: main.o faceRotation.o solveur.o
	${CC} ${CFLAGS} $^ -o $@
clean:
	@rm -f *.o