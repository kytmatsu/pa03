#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfsTrace.h"

// Scc functionality start
//Preconditions: an intlist, and an int
//Postconditions: a stack
Stack * dfsSweep(IntList * adjVs, int n) {
        int * color, * disTime, * finTime, * parent;
        int time = 0;

        //initialize arrays
        color = initColor(n);
        disTime = initDiscoverTime(n);
        finTime = initFinishTime(n);
        parent = initParent(n);
        Stack * stack = initStack();
        

        //recursively call DFS
        int i;
        for (i = 1; i <= n; ++i)
                if (color[i] == WHITE)
                        time = dfsTrace(adjVs, i, color, disTime, finTime, parent, stack, time);

        /*print out the results*/
        printArrays(n, disTime, finTime, parent);

        return stack;
}
//Preconditions: an intlist, 4 pointers to ints, a stack, and 2 ints
//Postconditions: an int
int dfsTrace(IntList * adjVs, int v, int * color, int * disTime, int * finTime, int * parent, Stack * fStack, int time) {
        int w;
        IntList remAdj;

        color[v] = GRAY;
        time++;
        disTime[v] = time;

        remAdj = adjVs[v];
        while(remAdj != intNil) {
                w = intFirst(remAdj);
                if (color[w] == WHITE) {
                        parent[w] = v;
                        time = dfsTrace(adjVs, w, color, disTime, finTime, parent, fStack, time);
                }

                remAdj = intRest(remAdj);
        }

        time++;
        finTime[v] = time;
        color[v] = BLACK;

        /*push vertex v into stack*/
        pushStack(fStack, v);

        return time;
}

//Preconditions: an int
//Postconditions: an int
int * initColor(int num) {
        int * color = (int *)malloc((num+1)*sizeof(int));
        for(int i = 0; i <= num; i++)
                color[i] = WHITE;

        return color;
}
//Preconditions: an int
//Postconditions: an int
int * initFinishTime(int num) {
        int * finTime = (int *)malloc((num+1)*sizeof(int));
        for(int i = 0; i <= num; i++)
                finTime[i] = 0;

        return finTime;
}
//Preconditions: an int
//Postconditions: an int
int * initDiscoverTime(int num) {
        int * disTime = (int *)malloc((num+1)*sizeof(int));
        for(int i = 0; i <= num; i++)
                disTime[i] = 0;
        return disTime;
}


//Preconditions: an int
//Postconditions: an int
int * initParent(int num) {
        int * parent = (int *)malloc((num+1)*sizeof(int));
        for (int i = 0; i <= num; i++)
                parent[i] = -1;

        return parent;
}

//Preconditions: an int, 3 pointers to an int
//Postconditions: returns nothing but prints out arrays
void printArrays(int n, int * disTime, int * finTime, int * parent) {
        printf("\nArrays\n");
        printf(" %10s %10s %10s %10s\n","Vertex", "disTime", "finTime", "Parent" );
        for(int i = 1; i <= n; i++) {
                printf(" %10d  %9d  %8d %9d\n", i, disTime[i], finTime[i], parent[i] );
        }

}
