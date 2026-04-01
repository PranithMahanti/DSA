#include <stdio.h>
#include <string.h>

int main(){

    char str[500];
    fgets(str , 500 , stdin);

    int words = 1;
    int vowels = 0;

    int index = 0;

    while(1){
        char curr = str[index];
        if (curr == '\0') break;
        if(curr == ' ') words++;
        else if(curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u') vowels++;
        index++;
    }

    //reversed string
    char rev[500];
    for(int i = 0 ; i < strlen(str) ; i++){
        rev[i] = str[strlen(str)- i - 1];
    }
    rev[strlen(str)+1] = '\0';

    printf("Words: %d \nVowels: %d \nReversed: %s" , words , vowels ,rev);

    return 0;
}
