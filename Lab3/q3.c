#include <stdio.h>
#include <math.h>

int main() {
    int n, h; 
    scanf("%d %d", &n, &h);

    int arr[n];
    int max=0;

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

        int low = 1, high = max;
        int answer = max;

        while (low <= high) {
            int mid = (low + high) / 2;
            double time = 0;

            for (int i = 0; i < n; i++) {
                time += (arr[i] + mid - 1) / mid;
            }

            if (time <= h) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        printf("%d\n", answer);

}