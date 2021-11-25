.PHONY : clean objs
.DEFAULT : objs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs)
OBJS =  faceRotation.o solveur.o listMovement.o  guiRubiksCube.o main.o  main
objs : ${OBJS}
faceRotation.o: faceRotation.c rubiksCube.h
	${CC} ${CFLAGS} -c $<
solveur.o: solveur.c solveur.h
	${CC} ${CFLAGS} -c $<
listMovement.o: listMovement.c listMovement.h
	${CC} ${CFLAGS} -c $<
guiRubiksCube.o: guiRubiksCube.c guiRubiksCube.h rubiksCube.h
	${CC} ${CFLAGS}  -c $< $(SDL_CFLAGS) $(SDL_LDFLAGS)
main.o: main.c solveur.h
	${CC} ${CFLAGS} -c $< $(SDL_CFLAGS) $(SDL_LDFLAGS)
main: main.o faceRotation.o solveur.o listMovement.o guiRubiksCube.o
	${CC} ${CFLAGS} $^ -o $@ $(SDL_CFLAGS) $(SDL_LDFLAGS)
clean:
	@rm -f *.o