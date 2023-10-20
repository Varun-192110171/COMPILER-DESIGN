#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_NON_TERMINALS 3
#define NUM_TERMINALS 4

// Function prototypes
void initializeParsingTable(char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][3]);
void printParsingTable(char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][3]);
void predictiveParse(char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][3], char input[]);
void syntaxError();
   char nonTerminals[NUM_NON_TERMINALS] = {'E', 'T', 'F'},stackSymbol;
   int col;
    char terminals[NUM_TERMINALS] = {'+', '*', '(', ')'};
int main() {
    // Define the grammar production rules
 

    // Define the predictive parsing table
    char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][3];

    // Initialize the parsing table
    initializeParsingTable(parsingTable);

    // Print the parsing table
    printf("Predictive Parsing Table:\n");
    printParsingTable(parsingTable);

    // Input string to parse
    char input[] = "id+id*id";

    // Parse the input string using the parsing table
    printf("\nParsing Input String:\n");
    predictiveParse(parsingTable, input);

    return 0;
}

// Initialize the predictive parsing table with production rules
void initializeParsingTable(char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][3]) {
    // Initialize all entries to empty strings
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        for (int j = 0; j < NUM_TERMINALS; j++) {
            strcpy(parsingTable[i][j], "");
        }
    }

    // Fill in the table with production rules
    // Example grammar:
    // E -> TE'
    // E' -> +TE' | e
    // T -> FT'
    // T' -> *FT' | e
    // F -> (E) | id

    strcpy(parsingTable[0][0], "TE'");
    strcpy(parsingTable[0][2], "TE'");
    strcpy(parsingTable[0][3], "");

    strcpy(parsingTable[1][0], "");
    strcpy(parsingTable[1][1], "FT'");
    strcpy(parsingTable[1][2], "");
    strcpy(parsingTable[1][3], "");

    strcpy(parsingTable[2][0], "");
    strcpy(parsingTable[2][1], "");
    strcpy(parsingTable[2][2], "(E)");
    strcpy(parsingTable[2][3], "id");
}

// Print the predictive parsing table
void printParsingTable(char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][3]) {
    printf("    +   *   (   )   id\n");
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        printf("%c ", nonTerminals[i]);
        for (int j = 0; j < NUM_TERMINALS; j++) {
            printf("%s ", parsingTable[i][j]);
        }
        printf("\n");
    }
}

// Predictive parsing function
void predictiveParse(char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][3], char input[]) {
    char stack[100];
    int top = -1;
    int inputIndex = 0;
    stack[++top] = '$'; // Initial stack symbol
    stack[++top] = 'E'; // Start symbol
    printf("Stack\tInput\tOutput\n");

    while (stack[top] != '$') {
        // Pop the stack symbol
         stackSymbol = stack[top--];

        // If stack symbol is a terminal, match it with input
        if (stackSymbol == input[inputIndex]) {
            inputIndex++;
            stack[top + 1] = '\0'; // Remove matched symbol from stack
        } else if (stackSymbol >= 'A' && stackSymbol <= 'Z') { // If stack symbol is a non-terminal
            // Find the production rule in the parsing table
            int row = stackSymbol - 'E';
            col = 0;
            while (input[inputIndex] != terminals[col]) {
                col++;
            }
            if (strcmp(parsingTable[row][col], "") != 0) {
                // Push the production rule onto the stack in reverse order
                for (int i = strlen(parsingTable[row][col]) - 1; i >= 0; i--) {
                    stack[++top] = parsingTable[row][col][i];
                }
            } else {
                syntaxError();
            }
        }

        // Print stack and input
        printf("%s\t%s\t", stack, &input[inputIndex]);
        if (stackSymbol == input[inputIndex]) {
            printf("Match %c\n", stackSymbol);
        } else if (stackSymbol >= 'A' && stackSymbol <= 'Z') {
            printf("Use %s -> %s\n", &stack[top + 1], parsingTable[stackSymbol - 'E'][col]);
        }
    }

    if (stackSymbol == '$' && input[inputIndex] == '\0') {
        printf("Parsing successful!\n");
    } else {
        syntaxError();
    }
}

// Function to handle syntax errors
void syntaxError() {
    printf("Syntax error!\n");
    exit(1);
}

