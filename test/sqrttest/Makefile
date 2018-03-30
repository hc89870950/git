LDFLAGS=-lm
CFLAGS=-g -Wall -O2
DIR=./nexttest/

sqrttest: sqrttest.o
	gcc -E -o ${DIR}sqrttest.i sqrttest.c
	gcc -S -o ${DIR}sqrttest.s ${DIR}sqrttest.i
	gcc -c -o ${DIR}sqrttest.o ${DIR}sqrttest.s
	gcc -o sqrttest ${DIR}sqrttest.o ${CFLAGS} ${LDFLAGS}


#sqrttest: sqrttest.o 
#	gcc -o sqrttest sqrttest.o ${LDFLAGS}
#sqrttest.o: sqrttest.c
#	gcc -c $< ${LDFLAGS}
clean:
	rm -f sqrttest sqrttest.o sqrttest.i sqrttest.s
	rm -f ${DIR}sqrttest ${DIR}sqrttest.o ${DIR}sqrttest.i ${DIR}sqrttest.s
