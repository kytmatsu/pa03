
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include "intList.h"
#include "dfsTrace.h"
#include "dfsPhase2.h"
#include "stackFunc.h"

#define maxSIZE 1024

typedef struct {
	int from;
	int to;
	double weight;
} Edge;


//This is a file from the Professor that I modified to check if the
//the the number was greater than the size we were given.
//It combines two of the files we were given.
//PreConditions: A char pointer, and Intlist, and an int that is the size of the array
//PostConditions:It alters the intlist.
void parseEdges(char *line, IntList *aVert, int arrSize) {
	Edge newE;
	int numFields;
	numFields = sscanf(line, "%d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
	if (numFields < 2 || numFields > 3) {
		printf("Bad Edge: %s\n", line);
		exit(1);
	}

	if (newE.from > arrSize) {
		printf("Number exceeds n, Number is too large: %s\n", line);
		newE.from = 0;
		newE.to = 0;
	}

	if (numFields == 2) {
		newE.weight = 0.0;
	}
	aVert[newE.from] = intCons(newE.to, aVert[newE.from]);
}



int main(int argc, char* argv[]) {
	FILE* input;
	if (argc > 1) {
			if(!strcmp(argv[1],"-")) {
				input = stdin;
			}
			else{
				//Open File
				char *myFile = argv[1];
				input = fopen(myFile, "r");
				if (input == NULL) {
					fprintf(stderr, "ERROR: FILE DOES NOT EXIST\n");
					return(0);
				}
			}
		}
		else{
			input = stdin;
		}


	//Get the size of our index from the first line
		char line[maxSIZE];
		int index;
		fgets(line, sizeof(line), input); //Read in first line
		sscanf(line, "%d %*s",  &index); //get the number n of index from first line

		//Create the IntList that will have the linked list data in it at the size of the index
		IntList *adjList = (IntList*)calloc(index+1,sizeof(IntList));
		int start = 1;
		for(start = 1; start <= index; start++) {
			adjList[start] = NULL;
		}
		// variable to count m
		int countIt = 0;
		//Read each line until the end of file and save it
		while (fgets(line, sizeof(line), input)) {
			countIt++;
			parseEdges(line, adjList, index);
		}
		// We've gotten the data now we print it.
		printf("\nn = %d\n", index);
		printf("m = %d\n", countIt);
		for(int count = 1; count <= index; count++) {
			bool start = true;
			IntList t = adjList[count];
			printf("%d  ", count);
			if(!t) {
				// If theres nothing in the file for that slot print a Null
				printf("Null\n");
			}
			// Start printing out the graph. If more than one entry it
			// will print out a comma to separate them
			while(t) {
				if(start == true) {
					printf("[");
				} else {
					printf(", ");
				}
				printf("%d", intFirst(t));
				t = intRest(t);
				start = false;
			}
			if(start == false) {
				printf("]\n");
			}
		}



	//scc phase 1
	Stack * finishStack1 = dfsSweep(adjList, index);

	//print out the stack
	printStack(finishStack1);

	//transpose a graph
	printf("\nTransposed graph\n");
	IntList * tGraph = transposeGraph(adjList, index);
		for(int y = 1; y <= index; y++) {
			start = true;
			IntList t1 = tGraph[y];
			printf("\n%d  ", y);
			if(!t1){
				printf("Null\n");
			}
			while(t1) {
				if(start == true) {
					printf("[");
				} else {
					printf(", ");
				}
				printf("%d", intFirst(t1));
				t1 = intRest(t1);
				start = false;
			}
			if(start == false) {
				printf("]\n");
			}
		}


	//scc phase 2
	dfsSweep2(tGraph, index, finishStack1);

	fclose(input);

	return 0;
}
