#include <stdio.h>

int main() {
    long long k;
    scanf("%lld", &k);

    long long x;
    long long low = 0;
    long long high = k;
    while (low <= high) {
        int mid = (low+high)/2;
        if (mid <= k/mid) {
            x = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }

    printf("%lld\n", x);

    return 0;
}