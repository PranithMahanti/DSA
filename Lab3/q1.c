#include <stdio.h>
#include <stdlib.h>

struct Sub {
    int marks;
    int delay;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Sub SubList[n];

    for (int i=0; i<n; i++) {
        scanf("%d", &SubList[i].marks);
        scanf("%d", &SubList[i].delay);
    }

    for (int i=0; i<n-1; i++) {
        int change = 0;
        for (int j=0; j<n-i-1; j++) {
            if (SubList[j].marks < SubList[j+1].marks) {
                int temp = SubList[j+1].marks;
                SubList[j+1].marks = SubList[j].marks;
                SubList[j].marks = temp;

                temp = SubList[j+1].delay;
                SubList[j+1].delay = SubList[j].delay;
                SubList[j].delay = temp;

                change = 1;
            } 
            else if (SubList[j].marks == SubList[j+1].marks) {
                if (SubList[j].delay > SubList[j+1].delay) {
                    int temp = SubList[j+1].marks;
                    SubList[j+1].marks = SubList[j].marks;
                    SubList[j].marks = temp;

                    temp = SubList[j+1].delay;
                    SubList[j+1].delay = SubList[j].delay;
                    SubList[j].delay = temp;

                    change = 1;
                }
            } else {}
        }
        if (!change) {
            break;
        }
    }

    printf("\nOutput:\n");

    for (int i=0; i<n; i++) {
        printf("%d %d\n", SubList[i].marks, SubList[i].delay);
    }

    return 0;
}