#include <stdio.h>
#include <string.h>
#include <ctype.h>

int nop, x;
char production[10][10], arr[10];

void find_first(char ch);
void find_follow(char ch);
void calculate(char ch);

void find_follow(char ch) {
    int i, j, k, l;
    if(production[0][0]==ch)
		calculate('$');
    for (i = 0; i < nop; i++) {
        l = strlen(production[i]);
        for (j = 2; j < l; j++) {
            if (production[i][j] == ch) {
                if (production[i][j + 1] != '\0')
                    find_first(production[i][j + 1]);
                if (production[i][j + 1] == '\0')
                    find_follow(production[i][0]);
            }
        }
    }
}

void find_first(char ch) {
    int k, i;  

    if (!isupper(ch)) {
        calculate(ch);
    } else {
        for (k = 0; k < nop; k++) {
            if (production[k][0] == ch) {
                if (production[k][2] == '$')
                   	calculate('$');
                else
                    find_first(production[k][2]);
            }
        }
    }
}

void calculate(char ch) {
    int count;
    for (count = 0; count < x; count++) {
        if (arr[count] == ch) {
            return;
        }
    }
    arr[x++] = ch;
}

int main() {
    int i;
    char choice, ch;
    printf("\nEnter the number of productions: ");
    scanf("%d", &nop);
    for (i = 0; i < nop; i++) {
        printf("Enter production %d: ", i + 1);
        scanf("%s", production[i]);
    }
    do {
        x = 0;
        printf("\nTO FIND THE FOLLOW OF: ");
        scanf(" %c", &ch); // Notice the space before %c to consume the newline
        find_first(ch);
        printf("\nFollow(%c) = {", ch);
        for (i = 0; arr[i] != '\0'; i++) {
            printf(" %c", arr[i]);
        }
        printf(" }\n");
        printf("DO YOU WANT TO CONTINUE (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    return 0;
}

