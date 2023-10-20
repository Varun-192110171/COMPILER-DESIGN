#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSIONS 100
#define MAX_EXPR_LEN 100

// Structure to represent an arithmetic expression
typedef struct {
    char expr[MAX_EXPR_LEN];
    int isCommon; // Flag to indicate if it's a common sub-expression
} Expression;

// Function to check if two expressions are equal
int areEqual(const char *expr1, const char *expr2) {
    return strcmp(expr1, expr2) == 0;
}

// Function to eliminate common sub-expressions
void eliminateCommonSubExpressions(Expression expressions[], int numExpressions) {
    for (int i = 0; i < numExpressions; i++) {
        if (!expressions[i].isCommon) {
            for (int j = i + 1; j < numExpressions; j++) {
                if (!expressions[j].isCommon && areEqual(expressions[i].expr, expressions[j].expr)) {
                    expressions[j].isCommon = 1; // Mark as a common sub-expression
                }
            }
        }
    }
}

int main() {
    Expression expressions[MAX_EXPRESSIONS];
    int numExpressions = 0;

    // Input expressions (you can add more)
    strcpy(expressions[numExpressions++].expr, "a + b * c");
    strcpy(expressions[numExpressions++].expr, "d + e * f");
    strcpy(expressions[numExpressions++].expr, "a + b * c");
    strcpy(expressions[numExpressions++].expr, "x + y");

    // Assume none of the expressions are common initially
    for (int i = 0; i < numExpressions; i++) {
        expressions[i].isCommon = 0;
    }

    // Eliminate common sub-expressions
    eliminateCommonSubExpressions(expressions, numExpressions);

    // Print the optimized expressions
    printf("Optimized Expressions:\n");
    for (int i = 0; i < numExpressions; i++) {
        if (!expressions[i].isCommon) {
            printf("%s\n", expressions[i].expr);
        }
    }

    return 0;
}

