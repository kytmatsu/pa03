# An Extremely basic Makefile that I made based off of the professors Makefile
# kytmatsu
# Kyle Matsumoto
CC = gcc
CFLAGS = -g -std=c99


scc03:	scc03.o intList.o dfsPhase2.o dfsTrace.o stackFunc.o
		${CC} -o scc03 ${CFLAGS} scc03.o intList.o dfsTrace.o dfsPhase2.o stackFunc.o

stackFunc.o:	stackFunc.c stackFunc.h
		${CC} -c ${CFLAGS} stackFunc.c

dfsPhase2.o:	dfsPhase2.c dfsPhase2.h
		${CC} -c ${CFLAGS} dfsPhase2.c

dfsTrace.o:	dfsTrace.c dfsTrace.h
		${CC} -c ${CFLAGS} dfsTrace.c

scc03.o:	scc03.c intList.h dfsTrace.o
		${CC} -c ${CFLAGS} scc03.c

intList.o:	intList.c intList.h
		${CC} -c ${CFLAGS} intList.c

