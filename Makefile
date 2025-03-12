EXE=prog.out
CC=g++
FLAGS=-Wall -g

INCLUDE=include
SRC=src
BIN=build

all: main.o Point.o Forme.o Rectangle.o Cercle.o 
	@mkdir -p ${BIN}
	${CC} ${FLAGS} ${BIN}/*.o -o ${EXE}

main.o : ${SRC}/main.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/main.cpp -o ${BIN}/main.o -c

Point.o : ${SRC}/Point.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Point.cpp -o ${BIN}/Point.o -c

Forme.o : ${SRC}/Forme.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Forme.cpp -o ${BIN}/Forme.o -c

Rectangle.o : ${SRC}/Rectangle.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Rectangle.cpp -o ${BIN}/Rectangle.o -c

Cercle.o : ${SRC}/Cercle.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Cercle.cpp -o ${BIN}/Cercle.o -c

Carre.o : ${SRC}/Carre.cpp
	@mkdir -p ${BIN}
	${CC} ${FLAGS} -I $(shell pwd)/${INCLUDE} ${SRC}/Carre.cpp -o ${BIN}/Carre.o -c


clean :
	rm -f ${EXE} ${BIN}/*.o

run :
	make && echo "\n==== ${EXE} ====\n" && ./${EXE}