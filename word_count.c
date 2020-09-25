#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 문제 : https://www.acmicpc.net/problem/1152

int main(){
    char input[1000000];
    int word_count = 0;
    char word;

    printf("입력 : ");

    gets(input);

    printf("%d\n", strlen(input));

    for(int i = 0; i < strlen(input); i++){

        if(input[strlen(input)-1] == ' ') { // 문장뒤 공백 있을 경우
            word_count++;
            break;
        }
        else if(input[i] == ' ') { // 띄어쓰기 있을때 
            if(i == 0){ // 첫글자가 띄어쓰기일때는 넘어가도록
                continue;
            }
            word_count++;
        }
 
    }

    printf("%d",word_count+1);

    return 0;
}