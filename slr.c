#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the grammar productions
char *productions[] = {
    "E->E+T",
    "E->T",
    "T->T*F",
    "T->F",
    "F->(E)",
    "F->id"
};

int numProductions = sizeof(productions) / sizeof(productions[0]);

// Define the parsing table
char parsingTable[6][6] = {
    {' ', ' ', 'S', 'S', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', 'A'},
    {'S', 'S', ' ', ' ', 'S', ' '},
    {'S', 'S', ' ', ' ', 'S', ' '},
    {' ', ' ', 'S', 'S', ' ', ' '},
    {' ', ' ', 'S', 'S', ' ', ' '}
};

// Define the stack for the parser
char stack[100];
int top = -1;

// Function to push a character onto the stack
void push(char c) {
    stack[++top] = c;
}

// Function to pop a character from the stack
char pop() {
    return stack[top--];
}

// Function to perform SLR parsing
void slrParser(char *input) {
    int inputIndex = 0;
    push('0'); // Initial state
    printf("Stack\t\tInput\t\tAction\n");

    while (true) {
        // Print the current stack and input
        for (int i = 0; i <= top; i++) {
            printf("%c", stack[i]);
        }
        printf("\t\t%s\t\t", input + inputIndex);

        // Get the current state and lookahead symbol
        int currentState = stack[top] - '0';
        char lookahead = input[inputIndex];

        // Determine the action from the parsing table
        char action = parsingTable[currentState][lookahead - 'E'];

        if (action == 'A') {
            printf("Accept\n");
            break; // Parsing is successful
        } else if (action == ' ') {
            printf("Error\n");
            break; // Parsing error
        } else if (action == 'S') {
            // Shift action
            push(lookahead);
            push(action);
            inputIndex++;
            printf("Shift %c\n", lookahead);
        } else {
            // Reduce action
            int reduceProduction = action - '0';
            int reduceLength = strlen(productions[reduceProduction]);
            printf("Reduce by %s\n", productions[reduceProduction]);

            // Pop the stack based on the reduce length
            for (int i = 0; i < 2 * reduceLength; i++) {
                pop();
            }

            // Get the current state after reduction
            int newState = stack[top] - '0';

            // Push the non-terminal symbol and the new state onto the stack
            push(productions[reduceProduction][0]);
            push(parsingTable[newState][productions[reduceProduction][0] - 'E']);
        }
    }
}

int main() {
    char input[100];
    printf("Enter an expression: ");
    scanf("%s", input);
    strcat(input, "$"); // Append end-marker

    slrParser(input);

    return 0;
}

