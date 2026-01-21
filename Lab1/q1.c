#include <stdio.h>

typedef struct {
    int sid;
    char name[100];
    float marks[3];
} Student;

int main() {
    int n = 0;
    scanf("%d", &n);

    Student students[n];
    float averages[n];
    int avg=0;

    for (int i=0; i<n; i++) {
        scanf("%d", &students[i].sid);
        scanf("%s", students[i].name);
        for (int j=0; j<3; j++) {
            scanf("%f", &students[i].marks[j]);
            averages[i]+=students[i].marks[j];

        }
        averages[i] /= 3;
    }
    
    printf("Merit List:\n");
    int index = 0;
    float high = averages[0];
    for (int i=0; i<n; i++) {
        if (averages[i] > 75) {
            printf("%d %s\n", students[i].sid, students[i].name);
        }
        if (averages[i] > high) {
            high = averages[i];
            index = i;
        }

    }

    printf("Topper: %s", students[index].name);

    return 0;
}
