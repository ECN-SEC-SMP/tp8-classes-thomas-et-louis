EXE=prog.out
CC=g++
FLAGS=-Wall -g

INCLUDE=include
SRC=src
BIN=build

all: main.o Animal.o Attaque.o Game.o Lion.o Loup.o Ours.o Pierre.o
	@mkdir -p ${BIN}
	${CC} ${FLAGS} ${BIN}/*.o -o ${EXE}

main.o : ${SRC}/main.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/main.cpp -o ${BIN}/main.o -c

Animal.o : ${SRC}/Animal.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Animal.cpp -o ${BIN}/Animal.o -c

Attaque.o : ${SRC}/Attaque.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Attaque.cpp -o ${BIN}/Attaque.o -c

Game.o : ${SRC}/Game.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Game.cpp -o ${BIN}/Game.o -c

Lion.o : ${SRC}/Lion.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Lion.cpp -o ${BIN}/Lion.o -c

Loup.o : ${SRC}/Loup.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Loup.cpp -o ${BIN}/Loup.o -c

Ours.o : ${SRC}/Ours.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Ours.cpp -o ${BIN}/Ours.o -c

Pierre.o : ${SRC}/Pierre.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Pierre.cpp -o ${BIN}/Pierre.o -c

clean :
	rm -f ${EXE} ${BIN}/*.o

run :
	make && echo "\n==== ${EXE} ====\n" && ./${EXE}