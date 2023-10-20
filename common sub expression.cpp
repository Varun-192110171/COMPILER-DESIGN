#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char operation;
    int operand1;
    int operand2;
} Expression;

bool areExpressionsEqual(Expression exp1, Expression exp2) {
    return (exp1.operation == exp2.operation) &&
           (exp1.operand1 == exp2.operand1) &&
           (exp1.operand2 == exp2.operand2);
}

int main() {
    Expression expressions[5];
    expressions[0] = (Expression) { '+', 2, 3 };
    expressions[1] = (Expression) { '-', 5, 1 };
    expressions[2] = (Expression) { '*', 4, 2 };
    expressions[3] = (Expression) { '+', 2, 3 };  // Common subexpression
    expressions[4] = (Expression) { '-', 5, 1 };  // Common subexpression

    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);

    for (int i = 0; i < numExpressions; i++) {
        bool isCommon = false;

        for (int j = i + 1; j < numExpressions; j++) {
            if (areExpressionsEqual(expressions[i], expressions[j])) {
                printf("Common subexpression found at indices %d and %d\n", i, j);
                isCommon = true;
                break;
            }
        }

        if (!isCommon) {
            printf("Expression %d: %d %c %d\n", i, expressions[i].operand1, expressions[i].operation, expressions[i].operand2);
        }
    }

    return 0;
}

