# include <stdio.h>
#include <stdbool.h>
int searchMin();
int arrPrint();
void findRoute();

double arr[7][7] = {{0, 5.6, 999, 6.8, 999, 999, 999},
                {5.6, 0, 4.3, 999, 6.5, 999, 999},
                {999, 4.3, 0, 5.6, 999, 5.8, 7},
                {6.8, 999, 5.6, 0, 999, 6.5, 999},
                {999, 6.5, 999, 999, 0, 999, 5.2},
                {999, 999, 5.8, 6.5, 999, 0, 5.5},
                {999, 999, 7, 999, 5.2, 5.5, 0}};
double h_score[6] = {12, 7, 10, 5.2, 5.5, 0};
float o[6][5];
float c[6][5];
int c_index = 1;
int o_index = 0;
int node_id = 0;

int main(){
    // 먼저 출발 노드인 0을 닫힌 목록 c배열에 넣음
    for(int i =0; i < 4; i++){
        c[0][i] = 0;  
    }

    //while : c에 6있으면 종료
    while(node_id != 6){ 
        for(int i = 0; i < 7; i++){   // o배열에 넣기
            if(arr[node_id][i] != 0 && arr[node_id][i] != 999){
                bool ck = true;
                // c에 있는 배열이면 break
                for (int m = 0; m <= sizeof(c)/sizeof(int); m++){ 
                    if(c[m][0] == i){
                        ck = false;
                        break;
                    }
                }

                if(ck == true){
                    o[o_index][0] = i;
                    o[o_index][2] = c[c_index-1][2] + arr[node_id][i];
                    o[o_index][3] = h_score[i-1];
                    o[o_index][1] = o[o_index][2] + o[o_index][3];
                    o[o_index][4] = c[c_index-1][0];
                    //printf("nodID : %.2f, F Score : %.2f,  G Score : %.2f, H score : %.2f, parent node : %.2f\n",o[o_index][0] ,o[o_index][1], o[o_index][2], o[o_index][3], o[o_index][4] );
                    o_index++;
                }
            }
        }
        node_id = searchMin();
    }

    //arrPrint();

    findRoute();      //경로출력

    return 0;
}

int searchMin(){
    int f_score_min = 999 ;
    int index = 0;

    // F 값이 가장 작은 노드(index)찾음
    for(int k = 0; k < o_index; k++){
        if(o[k][1] < f_score_min){
            if(o[k][1] == 0 )break;
            f_score_min = o[k][1];
            index = k;
        }
    }
    //printf("index : %d\n",index);

    c[c_index][0] = o[index][0];
    c[c_index][2] = o[index][2];
    c[c_index][3] = o[index][3];
    c[c_index][1] = c[c_index][2] + c[c_index][3];
    c[c_index][4] = o[index][4];
    //printf("c : %f, %f, %f, %f\n",  c[c_index][0],  c[c_index][1],  c[c_index][2],  c[c_index][3]);
    node_id =  c[c_index][0];
    c_index++;

    //c에 넣은 노드정보 삭제 (좌로 밀착)
    for(int l = index; l < o_index; l++){ 
        for(int m = 0 ; m < 4; m++){
            o[l][m] = o[l+1][m];
        }
    }
    o_index--;
    //printf("node_id : %d\n",node_id);

    return node_id;
}


int arrPrint(){
    // c배열 프린트
    for(int l = 0; l < c_index; l++){  
        printf("c : %.1f, %.1f, %.1f, %.1f, %.1f\n",  c[l][0],  c[l][1],  c[l][2],  c[l][3], c[l][4]); 
    }
}

// node id와 parent node 이용해서 경로 출력
void findRoute(){  
    int value = c[c_index-1][4];
    printf("%.0f <- %d <- ",c[c_index-1][0], value);
   for(int i = c_index-1; i >= 0 ; i--){
        if(value == c[i][0]){
            value = c[i][4]; 
            if(value == 0) {
                printf("%d",value);
                break;
            }
            printf("%d <- ", value);
        }
    }
}

