#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

void InitLQueue(LQueue *Q){
	if(Q->front!=NULL||Q->rear!=NULL){
		printf("队列已初始化，无需重复！\n\n");
		return ;
	}else{
		Q->front = (Node*)malloc(sizeof(Node));
		(Q->front)->next = NULL;
	//	Q->rear = (Node*)malloc(sizeof(Node));
		(Q->rear) = (Q->front);
		//(Q->rear)->next = NULL;
		Q->length = 0;
		printf("初始化成功！\n\n");
		return ;
	}
}


void DestoryLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("队列尚未初始化，请先初始化队列！\n\n");
		return FALSE;
	}
	if((Q->front)->data==NULL){
		printf("队列为空！请先入队！\n\n");
		return FALSE;
	}else{
		Node *tail = Q->rear;
		while(tail != Q->front){
			Q->rear = tail->next;
			free(tail);
			tail = Q->rear;
		}
		//Q->rear = Q->front;
		(Q->rear)->data=(Q->front)->data = NULL;
		Q->length = 0;
		
		free(Q->front);
		Q->front==NULL;
		Q->rear==NULL;
		printf("销毁成功！\n\n");
		return TRUE;
		
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("队列尚未初始化，请先初始化队列！\n\n");
		return FALSE;
	}else{
		if(Q->length==0){
			printf("队列为空！\n\n");
			return TRUE;
		}else{
			printf("队列不为空！\n\n");
			return TRUE;
		}
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("队列尚未初始化，请先初始化队列！\n\n");
		return FALSE;
	}
	if((Q->front)->data==NULL){
		printf("队头为空，请先入队！\n\n");
		return FALSE;
	}

	switch((Q->front)->flag){
			case 1:{
				//int *temp = (int*)e;
				int *temp1 = (int*)((Q->front)->data);
				//*temp = *temp1;
				printf("队头数据为：%d\n",*temp1);
				break;
			}
			case 2:{
				//double *temp = (double*)e;
				double *temp1 = (double*)((Q->front)->data);
				//*temp = *temp1;
				printf("队头数据为：%f\n",*temp1);
				break;
			}
			case 3:{
				//char *temp=(char*)e;
				char *temp1 = (char *)((Q->front)->data);
				//*temp = *temp1;
				printf("队头数据为：%c\n",*temp1);
				break;
			}
			case 4:{
				//char *temp=(char*)e;
				char *temp1 = (char *)((Q->front)->data);
				//*temp = *temp1;
				printf("队头数据为：%s\n",*temp1);
				break;
			}
			
	}
//	*temp = *((Q->front)->data);
	//*temp = *temp1;
	
	return TRUE;

}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("队列尚未初始化，请先初始化队列！\n\n");
		return -1;
	}
	return (Q->length);
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
			if(Q->front==NULL||Q->rear==NULL){
				printf("队列尚未初始化，请先初始化队列！\n\n");
				return FALSE;
			}
				int sign2; 
				Menu2();
				scanf("%d",&sign2);
				while(sign2<1||sign2>4){
					printf("输入有误！请重新输入。\n\n");
					scanf("%d",&sign2);
					
				}
				
				switch(sign2){
					case 1:{
						int *temp = (int*)data;
					//	temp = (int *)malloc(sizeof(int));
						printf("请输入入队的数据：\n\n");
						scanf("%d",temp);
						
						if((Q->rear)->data == NULL){
						(Q->rear)->data = temp;
						(Q->rear)->flag = sign2;
						(Q->front)->data = temp;
						(Q->front)->flag = sign2;
						printf("入队成功！\n\n");
						Q->length++;
						return TRUE;
					}else{
						Node *new = (Node*)malloc(sizeof(Node));
						new->data = temp;
						new->flag = sign2;
						new->next = Q->rear;
						Q->rear = new;
					//	(Q->rear)->flag = sign2;
						printf("入队成功！\n\n");
						Q->length++;
						return TRUE;
					}
						break;
					}
					case 2:{
						double*temp = (double*)data;
					//	temp = (double *)malloc(sizeof(double);
						printf("请输入入队的数据：\n\n");
						scanf("%f",temp);
						
						if((Q->rear)->data == NULL){
						(Q->rear)->data = temp;
						(Q->rear)->flag = sign2;
						(Q->front)->data = temp;
						(Q->front)->flag = sign2;
						printf("入队成功！\n\n");
						Q->length++;
						return TRUE;
					}else{
						Node *new = (Node*)malloc(sizeof(Node));
						new->data = temp;
						new->flag = sign2;
						new->next = Q->rear;
						Q->rear = new;
						printf("入队成功！\n\n");
						Q->length++;
						return TRUE;
					}
						break;
					}
					case 3:{
						char*temp=(char*)data;
					//	temp = (char *)malloc(sizeof(char);
						printf("请输入入队的数据：\n\n");
						fflush(stdin);
						//scanf("%c",temp);
						*temp = getchar();
						//printf("%c\n",*temp);
						
							if((Q->rear)->data == NULL){
							(Q->rear)->data = temp;
							(Q->rear)->flag = sign2;
							(Q->front)->data = temp;
						(Q->front)->flag = sign2;
							printf("入队成功！\n\n");
							Q->length++;
							return TRUE;
						}else{
							Node *new = (Node*)malloc(sizeof(Node));
							new->data = temp;
							new->flag = sign2;
							new->next = Q->rear;
							Q->rear = new;
							printf("入队成功！\n\n");
							Q->length++;
							return TRUE;
						}
						break;
					}
					case 4:{
						char*temp=(char*)data;
					//	temp = (char *)malloc(sizeof(1024));
						printf("请输入入队的数据：\n\n");
						fflush(stdin);
						scanf("%s",temp);
						
							if((Q->rear)->data == NULL){
							(Q->rear)->data = temp;
							(Q->rear)->flag = sign2;
							(Q->front)->data = temp;
						(Q->front)->flag = sign2;
							printf("入队成功！\n\n");
							Q->length++;
							return TRUE;
						}else{
							Node *new = (Node*)malloc(sizeof(Node));
							new->data = temp;
							new->flag = sign2;
							new->next = Q->rear;
							Q->rear = new;
							printf("入队成功！\n\n");
							Q->length++;
							return TRUE;
						}
						break;
					}
					
				}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("队列尚未初始化，请先初始化队列！\n\n");
		return FALSE;
	}
	if((Q->front)->data==NULL){
		printf("队列为空！请先入队！\n\n");
		return FALSE;
	}else{
		if((Q->front)->data != NULL){
			//(Q->front)->data = NULL;
			(Q->rear)->data = NULL;
			Q->length--;
			printf("出队成功！\n\n");
			return TRUE;
		}else{
			Node *head = Q->rear;
			while(head->next != Q->front){
				head = head->next;
			}
			Q->front = head;
			free(head->next);
			(Q->front)->next= NULL;
			Q->length--;
			printf("出队成功！\n\n");
			return TRUE;
		}
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("队列尚未初始化，请先初始化队列！\n\n");
		return FALSE;
	}
	if((Q->front)->data==NULL){
		printf("队列为空！请先入队！\n\n");
		return FALSE;
	}else{
		Node *tail = Q->rear;
		while(tail != Q->front){
			Q->rear = tail->next;
			free(tail);
			tail = Q->rear;
		}
		//Q->rear = Q->front;
		(Q->front)->data = NULL;
		Q->length = 0;
		printf("清空成功！\n\n");
		return TRUE;
		
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,int *flag1)){
	if(Q->front==NULL||Q->rear==NULL){
		printf("队列尚未初始化，请先初始化队列！\n\n");
		return FALSE;
	}
	if((Q->front)==(Q->rear)&&(Q->front)->data==NULL){
		printf("队列为空！请先入队！\n\n");
		return FALSE;
	}
	Node *tail = Q->rear;
	while(tail != NULL){
		(*foo)(tail->data,&(tail->flag));
		tail = tail->next;
	}
	
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q,int*flag1){
	switch(*flag1){
			case 1:{
				int *temp = (int*)q;
				printf("%d\n",*temp);
				break;
			}
			case 2:{
				double*temp = (double*)q;
				printf("%f\n",*temp);
				break;
			}
			case 3:{
				char*temp=(char*)q;
				printf("%c\n",*temp);
				break;
			}
			case 4:{
				char*temp=(char*)q;
				printf("%s\n",temp);
				break;
			}
	}
	
}

void Menu1(){
		printf("***************************************************\n\n");
		printf("*  1.初始化队列               2.入队              *\n\n");
		printf("*  3.出队                     4.确定队列长度      *\n\n");
		printf("*  5.确定队列为空             6.遍历队列          *\n\n");
		printf("*  7.清空队列                 8.销毁队列          *\n\n");
		printf("*  9.查看队头数据             0.退出              *\n\n");
		printf("***************************************************\n\n");
		printf("请按选项输入要进行的操作：\n\n");
}

void Menu2(){
		printf("**********************************************\n\n");
		printf("*  1.整型                     2.浮点型       *\n\n");
		printf("*  3.字符型                   4.字符串       *\n\n");
		printf("**********************************************\n\n");
		printf("请按选项输入要入队的数据类型：\n\n");
}



