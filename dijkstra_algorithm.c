# include <stdio.h>
#include <stdbool.h>
int searchMin();
int findRoute();
int arrPrint();

int arr[7][7] = {{0,5,999,1,999,999,999},
                    {5,0,1,999,3,999,999},
                    {999,1,0,2,999,2,8},
                    {1,999,2,0,999,1,999},
                    {999,3,999,999,0,999,1},
                    {999,999,2,1,999,0,3},
                    {999,4,8,999,1,3,0}} ;
int s[7] = {0}; // 이미 처리 된 노드의 집합
int d[7] = {0}; // 도착지까지의 비용
int t[7] = {0}; // 연결된 노드 번호
int index = 0;
int count = 0;

int main(){
    s[count] = 0; //0번 노드부터 시작
    //t[0] = 0;

    // 0번과 연결된 노드 비용들 일단 넣음, 다음번 계산에서 d값 바꿔주면 되니까
    for(int i = 0; i < 7; i++){   
        d[i] = arr[index][i];
    }
    for (int i = 0; i < 7; i++){ // 다익스트라는 모든 노드의 경로를 분석하므로 6개의 노드니까 6번돌린다
        for (int j = 0; j < 7 ; j++){

            // 새로 계산된 비용보다 큰값이라면 작은값으로 바꿔줌 
            if(d[j] > d[index] + arr[index][j]){ 
                d[j] = d[index] + arr[index][j];
                t[j] = index;  //  해당번호로 가는데 거친 노드 추가
                //printf("i : %d, t[%d] = %d\n",i, j,t[j]);
            }
        }
        index = searchMin();  // s와 t 배열에 넣을 인덱스(노드번호) 찾기
    }

    //arrPrint();
    findRoute();

    return 0;
}

int searchMin(){  // d배열에서 작은값이면서 s에 속하지 않는 index알아내기
    int min = 999;
    for(int k=0; k<7; k++){
        bool ck = true;
        if(d[k] < min){
            // s배열에 이미 있는 (이미 처리된) 노드라면 다음으로 넘어가기
            for (int m = 0; m <= sizeof(s)/sizeof(int); m++){  
                if(s[m] == k){
                    ck = false;
                    break;
                }
            }
            // 이미 처리된 노드가 아닌 것중에 d의 최소값을 찾아 index (노드번호) 찾기
            if(ck == true){  
                min = d[k];
                index = k;
            }
        }
    }
    count++;
    s[count] = index;  // s배열에 추가
    
    return index;
}

int findRoute(){  // 목적지점 입력받으면 해당 경로 출력
    int destination;
    printf("\n목적지점 입력 : ");
    scanf("%d",&destination);
    int i = destination;
     printf("%d <- ",destination);
    while(1){
        if(t[i] == 0){
            printf("%d ",t[i]);
            break;
        }
        printf("%d <- ",t[i]);
        i = t[i];
    }
}


int arrPrint(){
    //s 배열 출력
    for(int i =0 ; i < 7; i++){
        printf("%d ",s[i]);
    }
    printf("\n");
    //d 배열 출력
    for(int i =0 ; i < 7; i++){
            printf("%d ",d[i]);
        }
    printf("\n");
    //t 배열 출력
    for(int i =0 ; i < 7; i++){
        printf("%d ",t[i]);
    }
}