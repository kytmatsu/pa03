// This is just a basic stack. I swiped this from my 12b registry.
#include <stdio.h>
#include <stdlib.h>
#include "stackFunc.h"

Stack * initStack() {
	Stack * stack = (Stack *)malloc(sizeof(Stack));
	stack->last = NULL;
	stack->size = 0;

	return stack;
}
//Preconditions: stack
//Postconditions: an int
int isEmptyStack(Stack * stack) {
	if (stack->size == 0)
		return 1;
	else
		return 0;
}

//Preconditions: a stack and an int
//Postconditions: returns nothing
void pushStack(Stack * stck, int elt) {
	FinishTime * newElt = (FinishTime *)malloc(sizeof(FinishTime));

	newElt->prev = stck->last;
	newElt->next = NULL;
	newElt->time = elt;

	if (!isEmptyStack(stck)) {
		(stck->last)->next = newElt;
	}
	stck->last = newElt;
	stck->size++;
}
//Preconditions: a stack
//Postconditions: returns nothing
void popStack(Stack * stack) {
	if (isEmptyStack(stack))
		return;

	FinishTime * high = stack->last;
	stack->last = high->prev;
	stack->size--;
}
//Preconditions: a stack
//Postconditions: an int
int topStack(Stack * stack) {
	if (isEmptyStack(stack))
		return -1;
	else
		return (stack->last)->time;
}
//Preconditions: a stack
//Postconditions: returns nothing
void printStack(Stack * stack) {
	if (isEmptyStack(stack)) {
		printf("Is an Empty stack");
		return;
	}   

	FinishTime * t1 = stack->last;
	printf("\nStack\n");
	while(t1) {
		printf(" %d\n", t1->time);
		t1 = t1->prev;
	}
}
