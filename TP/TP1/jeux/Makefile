PROG=jeux_plus_moins
ARMCC=arm-linux-gnueabihf-gcc                         

all: dynamic static debug arm_dynamic arm_static arm_debug    
dynamic: menu.o main.o game.o
	gcc *.o -o ${PROG}_dynamic
static: menu.o main.o game.o
	gcc -static *.o -o ${PROG}_static
debug: menu.c main.c game.c
	gcc -g *.c -o ${PROG}_debug
main.o: main.c
	gcc -c main.c -o main.o

menu.o: menu.c
	gcc -c menu.c -o menu.o
game.o: game.c
	gcc -c game.c -o game.o

arm_dynamic: menu.c main.c game.c                     
	${ARMCC} *.c -o ${PROG}_arm_dynamic
arm_static: menu.c main.c game.c                      
	${ARMCC} -static *.c -o ${PROG}_arm_static
arm_debug: menu.c main.c game.c                       
	${ARMCC} -g *.c -o ${PROG}_arm_debug

clean:
	rm -f *.o ${PROG}_*
