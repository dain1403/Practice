#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 문제 : https://www.acmicpc.net/problem/1152

int main(){
    char input[1000000];
    //char *ptr;
    int word_count = 0;
    int i, j = 0;
    char word;

    printf("입력 : ");
    //scanf("%s",&input);

    while(1){
        word = getchar();
        //if(word == '\n') break;
        input[i++] = word;
        if(word == '\n') break;
    }

    printf("%s", input[i-1]);
    //printf("i : %d\n",i);

    // while(1){
    //     if(input[j] == ' ' && input[j+1] != '\n') word_count++;
    //     j++;
    //     if(i == j) break;
    // }

    // printf("%d",word_count);

    return 0;
}