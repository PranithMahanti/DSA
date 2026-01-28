#include <stdio.h>
#include <limits.h>

double findMedian(int a[], int n, int b[], int m) {
    // Ensure a[] is the smaller array
    if (n > m)
        return findMedian(b, m, a, n);

    int low = 0, high = n;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = (n + m + 1) / 2 - i;

        int leftA  = (i == 0) ? INT_MIN : a[i - 1];
        int rightA = (i == n) ? INT_MAX : a[i];

        int leftB  = (j == 0) ? INT_MIN : b[j - 1];
        int rightB = (j == m) ? INT_MAX : b[j];

        if (leftA <= rightB && leftB <= rightA) {
            if ((n + m) % 2 == 1) {
                return (double)(leftA > leftB ? leftA : leftB);
            } else {
                int leftMax = leftA > leftB ? leftA : leftB;
                int rightMin = rightA < rightB ? rightA : rightB;
                return (leftMax + rightMin) / 2.0;
            }
        } 
        else if (leftA > rightB) {
            high = i - 1;
        } 
        else {
            low = i + 1;
        }
    }

    return 0.0;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums1[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums1[i]);

    int m;
    scanf("%d", &m);
    int nums2[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &nums2[i]);

    double median = findMedian(nums1, n, nums2, m);
    printf("%.2f\n", median);

    return 0;
}
