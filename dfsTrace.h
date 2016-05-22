#ifndef DFS1
#define DFS1

#include "intList.h"
#include "stackFunc.h"

#define WHITE 0
#define GRAY  1
#define BLACK 2

Stack * dfsSweep(IntList[], int);
//DFS
int dfsTrace(IntList[], int, int[], int[], int[], int[], Stack *, int);
int * initColor(int);
int * initFinishTime(int);
int * initDiscoverTime(int);
int * initParent(int);
void printArrays(int, int[], int[], int[]);


#endif
