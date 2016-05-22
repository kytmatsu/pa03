#ifndef __stack__
#define __stack__


struct finishTime
{
	int time;
	struct finishTime * prev;
	struct finishTime * next;
};

typedef struct finishTime FinishTime;

typedef struct
{
	int size;
	FinishTime * last;
} Stack;

Stack * initStack();

int isEmptyStack(Stack *);


//Precondition: a stack and an int
//Postcondition: returns nothing
void pushStack(Stack *, int);

//Precondition: a stack
//Postcondition: returns nothing
void popStack(Stack *);

//Precondition: a stack
//Postcondition:returns an int
int topStack(Stack *);


//Precondition: a stack
//Postcondition: returns nothing
void printStack(Stack *);


#endif
