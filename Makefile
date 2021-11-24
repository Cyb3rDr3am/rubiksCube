.PHONY : clean objs
.DEFAULT : objs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SDL_CFLAGS := $(shell sdl-config --cflags)
SDL_LDFLAGS := $(shell sdl-config --libs)
OBJS =  faceRotation.o solveur.o listMovement.o  guiRubiksCube.o main.o  main
objs : ${OBJS}
faceRotation.o: faceRotation.c rubiksCube.h
	${CC} ${CFLAGS} -c $<
solveur.o: solveur.c solveur.h
	${CC} ${CFLAGS} -c $<
listMovement.o: listMovement.c listMovement.h
	${CC} ${CFLAGS} -c $<
guiRubiksCube.o: guiRubiksCube.c guiRubiksCube.h
	echo $(SDL)
	${CC} ${CFLAGS}  -c $< $(SDL)
main.o: main.c solveur.h
	${CC} ${CFLAGS} -c $<
main: main.o faceRotation.o solveur.o listMovement.o guiRubiksCube.o
	${CC} ${CFLAGS} $^ -o $@
clean:
	@rm -f *.o