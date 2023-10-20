#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

int main() {
    char str[] = "12345"; // A string containing the integer "12345"

    // Using atoi to convert the string to an integer
    int num = atoi(str);
    if(isdigit(str[1]))
        printf("hello");
    printf("Integer value: %d\n", num);

    return 0;
}

