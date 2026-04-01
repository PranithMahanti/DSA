#include <stdio.h>
#include <string.h>

int main() {
    char sen[1000];
    fgets(sen, sizeof(sen), stdin);

    int l = strlen(sen);

    if (sen[l - 1] == '\n') {
        sen[l - 1] = '\0';
        l--;
    }

    int freq[26];

    char queue[1000];
    int first = 0;
    int new = 0;

    for (int i=0; i<26; i++)
        freq[i] = 0;

    for (int i=0; i<l; i++) {
        int index = sen[i] - 'a';
        freq[index]++;

        queue[new++] = sen[i];

        while (first < new && freq[queue[first] - 'a'] > 1) {
            first++;
        }

        if (first == new)
            printf("-1 ");
        else
            printf("%c ", queue[first]);
    }

    return 0;
}