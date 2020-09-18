#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 문제 : https://www.acmicpc.net/problem/10799

int main(){
    int count = 0;   // ( 나오면 +1, )오면 -1
    int result = 0;
    char input[999];
    bool ck = false; 

    printf("입력 : ");
    scanf("%s",input);
    //printf("%c",input[1]);
    
    int i = 0;

    while(input[i] != '\0'){

        if(input[i] == '('){
            count++;
            ck = true;
        }

        else if(input[i] == ')'){

            if(ck == true){
                result += (count-1);
            }

            else if(count > 0){
                result++;
            }

            count--;
            ck = false;
        }

        i++;
    }

    printf("result : %d\n",result);

    return 0;

}
