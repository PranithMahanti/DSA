#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10000

int main() {

    int n;
    scanf("%d", &n);

    char input[MAX];
    scanf("%s", input);

    int countStack[MAX];
    char stringStack[MAX][MAX];

    int countTop = -1, stringTop = -1;

    char current[MAX] = "";
    int num = 0;

    for (int i = 0; input[i] != '\0'; i++) {

        if (isdigit(input[i])) {
            num = num * 10 + (input[i] - '0');
        }

        else if (input[i] == '[') {
            countStack[++countTop] = num;
            strcpy(stringStack[++stringTop], current);

            num = 0;
            current[0] = '\0';
        }

        else if (input[i] == ']') {

            int repeat = countStack[countTop--];
            char temp[MAX];
            strcpy(temp, current);

            strcpy(current, stringStack[stringTop--]);

            for (int j = 0; j < repeat; j++) {
                strcat(current, temp);
            }
        }

        else {  // normal character
            int len = strlen(current);
            current[len] = input[i];
            current[len + 1] = '\0';
        }
    }

    printf("%s", current);

    return 0;
}
