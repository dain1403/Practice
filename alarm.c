#include <stdio.h>

// 문제 : https://www.acmicpc.net/problem/2884

int main(){
    int h, m;  //시 , 초
    int value;
   scanf("%d %d",&h, &m);

    if(m >= 45){
        m -= 45;
    }
    else if(m >= 0 && m < 45){
        value = 45 - m;
        m = 0;
        m = 60 - value;
        if(h == 0){
            h = 23;
        }else{
            h -= 1;
        }
    }
    printf("%d %d", h, m);
    return 0;
}