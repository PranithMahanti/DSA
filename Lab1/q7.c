#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int n = strlen(s);
    char compressed[2000];
    int k = 0;

    for (int i = 0; i < n; i++) {
        char current = s[i];
        int count = 1;

        // Count consecutive identical characters
        while (i + 1 < n && s[i] == s[i + 1]) {
            count++;
            i++;
        }

        // Store character
        compressed[k++] = current;

        // Store count (can be multiple digits)
        k += sprintf(&compressed[k], "%d", count);
    }

    compressed[k] = '\0';

    // Print based on length comparison
    if (strlen(compressed) <= strlen(s)) {
        printf("%s\n", compressed);
    } else {
        printf("%s\n", s);
    }

    return 0;
}
