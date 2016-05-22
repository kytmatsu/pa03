#ifndef DFS2
#define DFS2
#include "intList.h"
#include "stackFunc.h"
#include "dfsTrace.h"

int * initDfsRoot(int);
void dfsSweep2(IntList[], int, Stack *);
int dfsT2(IntList[], int[], int, int, int[], int[], int[], int[], int);
void printArraysPhase2(int, int[], int[],int[], int[]); 

#endif
