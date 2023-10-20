#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_INPUT_SIZE 100

// Define the productions of the grammar
char *productions[] = {
    "E->E+T",
    "E->T",
    "T->T*F",
    "T->F",
    "F->(E)",
    "F->i"
};

int numProductions = 6;

// Define the terminals and non-terminals
char terminals[] = {'+', '*', '(', ')', 'i', '$'};
char nonTerminals[] = {'E', 'T', 'F'};

// Parse table for the grammar
int parseTable[3][6] = {
    {5, 0, 0, 0, 5, 0},
    {0, 6, 0, 0, 0, 7},
    {0, 0, 8, 9, 0, 0}
};

// Stack to hold the states
int stack[MAX_STACK_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int state) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = state;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

// Function to get the action from the parse table
int getAction(int state, int symbol) {
    int index1, index2;
    for (index1 = 0; index1 < 3; index1++) {
        if (nonTerminals[index1] == state) break;
    }
    for (index2 = 0; index2 < 6; index2++) {
        if (terminals[index2] == symbol) break;
    }
    return parseTable[index1][index2];
}

// Function to perform parsing
void parse(char input[]) {
    push(0);
    int i = 0;
    while (1) {
        int state = stack[top];
        int symbol = input[i];
        int action = getAction(state, symbol);
        if (action == -1) {
            printf("Error\n");
            exit(1);
        } else if (action == 0) {
            printf("Accept\n");
            break;
        } else if (action > 0) {
            push(symbol);
            push(action);
            i++;
        } else if (action < 0) {
            int production = -action;
            int len = strlen(productions[production - 1]);
            for (int j = 0; j < 2 * len; j++) {
                pop();
            }
            symbol = productions[production - 1][0];
            state = stack[top];
            push(symbol);
            int nextState = parseTable[state - 'E'][terminals[symbol - '+']];
            push(nextState);
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter input string: ");
    scanf("%s", input);
    strcat(input, "$"); // Append $ to the input string
    parse(input);
    return 0;
}

