#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_PROD 10
#define MAX_LEN 10

char nonTerminal; // The non-terminal to eliminate left-factoring
int numProductions; // Number of productions for the non-terminal
char productions[MAX_PROD][MAX_LEN]; // Production rules

void eliminateLeftRecursion() {
    char newNonTerminal = nonTerminal + 1; // Create a new non-terminal
    char epsilon[2] = {'\0', '\0'};

    for (int i = 0; i < numProductions; i++) {
        if (productions[i][0] == nonTerminal) {
            // Production begins with the non-terminal to eliminate
            char remainder[MAX_LEN];
            strcpy(remainder, productions[i] + 1); // Get the remainder of the production
            printf("%c -> %s%c'\n", newNonTerminal, remainder, newNonTerminal);
        } else {
            // Production doesn't begin with the non-terminal to eliminate
            if (productions[i][0] != epsilon[0]) {
                printf("%c -> %s%c'\n", nonTerminal, productions[i], newNonTerminal);
            } else {
                printf("%c -> %c'\n", nonTerminal, newNonTerminal);
            }
        }
    }

    // Add epsilon production
    printf("%c' -> %s%c' | %c\n", newNonTerminal, epsilon, newNonTerminal, epsilon[0]);
}

int main() {
    printf("Enter the non-terminal to eliminate left-recursion: ");
    scanf(" %c", &nonTerminal);

    printf("Enter the number of productions for %c: ", nonTerminal);
    scanf("%d", &numProductions);

    printf("Enter the production rules:\n");
    for (int i = 0; i < numProductions; i++) {
        scanf("%s", productions[i]);
    }

    printf("After eliminating left-recursion:\n");
    eliminateLeftRecursion();

    return 0;
}

