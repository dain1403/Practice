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
int s[7] = {0}; // �̹� ó�� �� ����� ����
int d[7] = {0}; // ������������ ���
int t[7] = {0}; // ����� ��� ��ȣ
int index = 0;
int count = 0;

int main(){
    s[count] = 0; //0�� ������ ����
    //t[0] = 0;

    // 0���� ����� ��� ���� �ϴ� ����, ������ ��꿡�� d�� �ٲ��ָ� �Ǵϱ�
    for(int i = 0; i < 7; i++){   
        d[i] = arr[index][i];
    }
    for (int i = 0; i < 7; i++){ // ���ͽ�Ʈ��� ��� ����� ��θ� �м��ϹǷ� 6���� ���ϱ� 6��������
        for (int j = 0; j < 7 ; j++){

            // ���� ���� ��뺸�� ū���̶�� ���������� �ٲ��� 
            if(d[j] > d[index] + arr[index][j]){ 
                d[j] = d[index] + arr[index][j];
                t[j] = index;  //  �ش��ȣ�� ���µ� ��ģ ��� �߰�
                //printf("i : %d, t[%d] = %d\n",i, j,t[j]);
            }
        }
        index = searchMin();  // s�� t �迭�� ���� �ε���(����ȣ) ã��
    }

    //arrPrint();
    findRoute();

    return 0;
}

int searchMin(){  // d�迭���� �������̸鼭 s�� ������ �ʴ� index�˾Ƴ���
    int min = 999;
    for(int k=0; k<7; k++){
        bool ck = true;
        if(d[k] < min){
            // s�迭�� �̹� �ִ� (�̹� ó����) ����� �������� �Ѿ��
            for (int m = 0; m <= sizeof(s)/sizeof(int); m++){  
                if(s[m] == k){
                    ck = false;
                    break;
                }
            }
            // �̹� ó���� ��尡 �ƴ� ���߿� d�� �ּҰ��� ã�� index (����ȣ) ã��
            if(ck == true){  
                min = d[k];
                index = k;
            }
        }
    }
    count++;
    s[count] = index;  // s�迭�� �߰�
    
    return index;
}

int findRoute(){  // �������� �Է¹����� �ش� ��� ���
    int destination;
    printf("\n�������� �Է� : ");
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
    //s �迭 ���
    for(int i =0 ; i < 7; i++){
        printf("%d ",s[i]);
    }
    printf("\n");
    //d �迭 ���
    for(int i =0 ; i < 7; i++){
            printf("%d ",d[i]);
        }
    printf("\n");
    //t �迭 ���
    for(int i =0 ; i < 7; i++){
        printf("%d ",t[i]);
    }
}