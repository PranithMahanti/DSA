#include <stdio.h>

long long func(long long num) {
    return 2*num*num*num - num*num + 5*num;
}

long long main() {
    long long y;
    scanf("%d", &y);

    long long low = 0;
    long long high = y;
    long long mid;
    long long ans = 0;

    while (low <= high) {
        mid = (low+high)/2;
        if (func(mid) <= y) {
            low = mid+1;
            ans = mid;
        } 
        else if (func(mid) > y) {
            high = mid - 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}