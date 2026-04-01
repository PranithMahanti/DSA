#include <stdio.h>

int main(){

    //sort first(bubble sort)

    int n = 0;
    scanf("%d" , &n);

    int arr[n];
    for(int i = 0 ; i < n ; i++) scanf("%d" , &arr[i]);

    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - i -1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int curr = arr[0];
    int count = 1;

    for(int i = 1 ; i < n ; i++){
        if(arr[i] == curr) count++;
        else{
            printf("%d -> %d\n" , arr[i-1] , count);
            curr = arr[i];
            count = 1;
        }
    }

    printf("%d -> %d" , arr[n-1] , count);

    return 0;
}