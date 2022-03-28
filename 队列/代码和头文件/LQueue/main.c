#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

int main(){
	LQueue *Q = (LQueue*)malloc(sizeof(LQueue));
	Q->front = NULL;
	Q->rear = NULL;
	
	int sign;
	do{
		Menu1();
		scanf("%d",&sign);
		while(sign<0||sign>9){
			printf("输入有误！请重新输入。\n\n");
			scanf("%d",&sign);
		}
		switch(sign){
			case 1:{
				InitLQueue(Q);
				break;
			}
			case 2:{
				void *data = malloc(sizeof(int[1024]));
				EnLQueue(Q,data);
				break;
			}
			case 3:{
				DeLQueue(Q);
				break;
			}
			case 4:{
				int n = LengthLQueue(Q);
				if(n != -1){
					printf("当前队列长度为：%d\n",n);
				}
				break;
			}
			case 5:{
				IsEmptyLQueue(Q);
				break;
			}
			case 6:{
				
				//void (*foo)(void *q);
				TraverseLQueue(Q,LPrint);
				break;
			}
			case 7:{
				ClearLQueue(Q);
				break;
			}
			case 8:{
				DestoryLQueue(Q);
				break;
			}
			case 9:{
				//void *e;
				GetHeadLQueue(Q);
				
				break;
			}
			case 0:{
				
				break;
			}
			
		} 
		
		system("pause");
		system("cls");
	}while(sign != 0);
	return 0;
}
