#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isComment(char *line) {
    int len = strlen(line);

    // Check if it's a single-line comment
    if (len >= 2 && line[0] == '/' && line[1] == '/') {
        return true;
    }

    // Check if it's a multi-line comment start
    if (len >= 2 && line[0] == '/' && line[1] == '*') {
        return true;
    }

    // Check if it's a multi-line comment end
    if (len >= 2 && line[len - 2] == '*' && line[len - 1] == '/') {
        return true;
    }

    return false;
}

int main() {
    char input[100];
    printf("Enter a line: ");
    fgets(input, sizeof(input), stdin);

    if (isComment(input)) {
        printf("It's a comment.\n");
    } else {
        printf("It's not a comment.\n");
    }

    return 0;
}

