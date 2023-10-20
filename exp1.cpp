#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a keyword
int isKeyword(char *token) {
    char keywords[8][10] = {"int", "float", "if", "else", "while", "for", "break", "return"};
    for (int i = 0; i < 8; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }
    return 0; // It's not a keyword
}

int main() {
    char input[100];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);
    
    char delimiters[] = " \t\n(){}[];,+-*/%=><";
    char *token = strtok(input, delimiters);

    while (token != NULL) {
        if (isalpha(token[0]) || token[0] == '_') {
            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
        } else if (isdigit(token[0])) {
            printf("Constant: %s\n", token);
        } else {
            printf("Operator: %s\n", token);
        }

        token = strtok(NULL, delimiters);
    }

    return 0;
}

