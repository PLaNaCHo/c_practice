#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define m0 SizeOfArray
void clear();
int num_of_current_link=0;
//-------function--------------------------------
/*
-만들것-
노드 수 N
도수(이웃수==링크수)k
k^-(감마) 의 멱함수 꼴의 이웃수 분포p(k) 
-나중에 할 것-
그래프로 표현

노드=점
링크=이어진 선

모두 종료 후 이웃수 분포 
*/
struct node {
  int node_num;
  int num_of_link;
  struct node *linked_node[30];
};

//-----------main--------------------------------
int main(){
  srand(time(NULL));
  clear();
  int SizeOfArray;
  struct node *arr;
  int num_of_total_link;
  int i,k;
  //int m0;//초기 노드 수

  printf("총 노드 수 : ");
  scanf("%d", &SizeOfArray);

  arr = (struct node *)malloc(sizeof(struct node) * SizeOfArray);
  // int arr[SizeOfArray] 와 동일한 작업을 한 크기의 배열 생성

  printf("총 링크 수 : ");
  scanf("%d", &num_of_total_link);

  for (int i=0;i<m0;i++){//노드 초기화
    arr[i].node_num = i+1;//링크 넘버 새기기
    arr[i].num_of_link = 0;
  }

  while (num_of_current_link<=num_of_total_link){//m0의 초기노드 생성
      do {i = rand() % (m0);//링크할 노드 선택용 랜덤
          k = rand() % (m0);
      }while(i==k);

      //printf("%d,%d\n",k,i);
      arr[i].linked_node[arr[i].num_of_link] = &arr[k];
      arr[k].linked_node[arr[k].num_of_link] = &arr[i];

      arr[i].num_of_link++;
      arr[k].num_of_link++;
      num_of_current_link++;
      //printf("%d",num_of_current_link);
      if(num_of_current_link==num_of_total_link)
        break;
  }
  for (int i=0;i<m0;i++){//링크 확인
    printf("\n%.3d번째 노드, 링크%d개",arr[i].node_num,arr[i].num_of_link);

    if(arr[i].num_of_link>0){
      printf(",이어진 노드 : ");
      for (int n=0;n<30;n++){
          if (arr[i].linked_node[n]==NULL)
            break;
          if (n%5==0)
            printf("\n  ");
         printf("%.3d번째 ",(*arr[i].linked_node[n]).node_num);
      }
    
    }

    printf("\n");
  }

  free(arr);
return 0;
}

//-------function-------------------------------
void clear(){
  //화면 지우는 함수. 윈도우면 clear 대신 cls를 입력력
  printf("\n");
  system("clear");
};
/*
노드 생성 : 객체
링크 방법 : matrix, array,*/