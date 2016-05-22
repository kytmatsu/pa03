#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfsPhase2.h"

//Preconditions: an int
//Postconditions: an int
int * initDfsRoot(int num) {
        int * dfsRoot = (int *)malloc((num+1)*sizeof(int));
        int i;

        for(i = 0; i <= num; ++i)
                dfsRoot[i] = 0;

        return dfsRoot;
}

//Preconditions: an intList, an int and a stack
//Postconditions: returns nothing
void dfsSweep2(IntList * adjList, int n, Stack * fStack) {
        int * color, * disTime, * finTime;
        int * parent, * dfsRoot;
        int time = 0;

        //initialize arrays
        color = initColor(n);
        disTime = initDiscoverTime(n);
        finTime = initFinishTime(n);
        parent = initParent(n);
        //scc's leader
        dfsRoot = initDfsRoot(n);

        //pop the stack and use DFS
        int i;
        for (i = n; i > 0; --i) {
                int v = topStack(fStack);
                popStack(fStack);
                if (color[v] == WHITE)
                        time = dfsT2(adjList, color, v, v, dfsRoot, disTime, finTime, parent, time);
        }

        //print out the results
        printArraysPhase2(n, disTime, finTime, parent, dfsRoot);
       // printScc(dfsRoot, n);


}
//Preconditions: an intlist, 4 pointers to ints, 3 ints
//Postconditions: an int
int dfsT2(IntList * adjList, int * color, int v, int leader, int * scc, int * disTime, int * finTime,int * parent, int time) {

        int w;
        IntList stay;

        color[v] = GRAY;
        scc[v] = leader;
        time++;
        disTime[v] = time;

        stay = adjList[v];
        while(stay != intNil) {
                w = intFirst(stay);
                if (color[w] == WHITE) {
                        parent[w] = v;
                        time = dfsT2(adjList, color, w, leader, scc, disTime, finTime, parent, time);
                }

                stay = intRest(stay);
        }

        time++;
        finTime[v] = time;
        color[v] = BLACK;


        return time;
}
//Preconditions: 4 pointers to ints, and int, and an scc
//Postconditions: returns nothing prints out arrays
void printArraysPhase2(int n, int * disTime, int * finTime, int * parent, int *scc) {
        printf("\nArrays\n");
        printf(" %10s %10s %10s %10s %10s\n","Vertex", "disTime", "finTime", "Parent", "dfsTroot" );
        for(int i = 1; i <= n; i++) {
                printf(" %10d  %9d  %8d %9d %10d\n", i, disTime[i], finTime[i], parent[i],scc[i] );
        }

}


