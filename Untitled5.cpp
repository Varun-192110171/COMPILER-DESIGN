#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid C identifier
bool isValidIdentifier(const char* identifier) {
    // Check if the identifier is not empty
    if (strlen(identifier) == 0) {
        return false;
    }

    // Check the first character
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return false;
    }

    // Check the remaining characters
    for (int i = 1; i < strlen(identifier); i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return false;
        }
    }

    // If all checks pass, it's a valid identifier
    return true;
}

int main() {
    char identifier[100];
    
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("%s is a valid C identifier.\n", identifier);
    } else {
        printf("%s is not a valid C identifier.\n", identifier);
    }

    return 0;
}

