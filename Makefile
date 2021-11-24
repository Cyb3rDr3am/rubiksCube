.PHONY : clean objs
.DEFAULT : objs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJS = faceRotation.o solveur.o listMovement.o main.o main
objs : ${OBJS}
faceRotation.o: faceRotation.c rubiksCube.h
	${CC} ${CFLAGS} -c $<
solveur.o: solveur.c solveur.h
	${CC} ${CFLAGS} -c $<
listMovement.o: listMovement.c listMovement.h
	${CC} ${CFLAGS} -c $<
main.o: main.c solveur.h
	${CC} ${CFLAGS} -c $<
main: main.o faceRotation.o solveur.o listMovement.o
	${CC} ${CFLAGS} $^ -o $@
clean:
	@rm -f *.o