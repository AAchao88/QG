#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

void InitLQueue(LQueue *Q){
	if(Q->front!=NULL||Q->rear!=NULL){
		printf("�����ѳ�ʼ���������ظ���\n\n");
		return ;
	}else{
		Q->front = (Node*)malloc(sizeof(Node));
		(Q->front)->next = NULL;
	//	Q->rear = (Node*)malloc(sizeof(Node));
		(Q->rear) = (Q->front);
		//(Q->rear)->next = NULL;
		Q->length = 0;
		printf("��ʼ���ɹ���\n\n");
		return ;
	}
}


void DestoryLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("������δ��ʼ�������ȳ�ʼ�����У�\n\n");
		return FALSE;
	}
	if((Q->front)->data==NULL){
		printf("����Ϊ�գ�������ӣ�\n\n");
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
		printf("���ٳɹ���\n\n");
		return TRUE;
		
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("������δ��ʼ�������ȳ�ʼ�����У�\n\n");
		return FALSE;
	}else{
		if(Q->length==0){
			printf("����Ϊ�գ�\n\n");
			return TRUE;
		}else{
			printf("���в�Ϊ�գ�\n\n");
			return TRUE;
		}
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("������δ��ʼ�������ȳ�ʼ�����У�\n\n");
		return FALSE;
	}
	if((Q->front)->data==NULL){
		printf("��ͷΪ�գ�������ӣ�\n\n");
		return FALSE;
	}

	switch((Q->front)->flag){
			case 1:{
				//int *temp = (int*)e;
				int *temp1 = (int*)((Q->front)->data);
				//*temp = *temp1;
				printf("��ͷ����Ϊ��%d\n",*temp1);
				break;
			}
			case 2:{
				//double *temp = (double*)e;
				double *temp1 = (double*)((Q->front)->data);
				//*temp = *temp1;
				printf("��ͷ����Ϊ��%f\n",*temp1);
				break;
			}
			case 3:{
				//char *temp=(char*)e;
				char *temp1 = (char *)((Q->front)->data);
				//*temp = *temp1;
				printf("��ͷ����Ϊ��%c\n",*temp1);
				break;
			}
			case 4:{
				//char *temp=(char*)e;
				char *temp1 = (char *)((Q->front)->data);
				//*temp = *temp1;
				printf("��ͷ����Ϊ��%s\n",*temp1);
				break;
			}
			
	}
//	*temp = *((Q->front)->data);
	//*temp = *temp1;
	
	return TRUE;

}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("������δ��ʼ�������ȳ�ʼ�����У�\n\n");
		return -1;
	}
	return (Q->length);
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
			if(Q->front==NULL||Q->rear==NULL){
				printf("������δ��ʼ�������ȳ�ʼ�����У�\n\n");
				return FALSE;
			}
				int sign2; 
				Menu2();
				scanf("%d",&sign2);
				while(sign2<1||sign2>4){
					printf("�����������������롣\n\n");
					scanf("%d",&sign2);
					
				}
				
				switch(sign2){
					case 1:{
						int *temp = (int*)data;
					//	temp = (int *)malloc(sizeof(int));
						printf("��������ӵ����ݣ�\n\n");
						scanf("%d",temp);
						
						if((Q->rear)->data == NULL){
						(Q->rear)->data = temp;
						(Q->rear)->flag = sign2;
						(Q->front)->data = temp;
						(Q->front)->flag = sign2;
						printf("��ӳɹ���\n\n");
						Q->length++;
						return TRUE;
					}else{
						Node *new = (Node*)malloc(sizeof(Node));
						new->data = temp;
						new->flag = sign2;
						new->next = Q->rear;
						Q->rear = new;
					//	(Q->rear)->flag = sign2;
						printf("��ӳɹ���\n\n");
						Q->length++;
						return TRUE;
					}
						break;
					}
					case 2:{
						double*temp = (double*)data;
					//	temp = (double *)malloc(sizeof(double);
						printf("��������ӵ����ݣ�\n\n");
						scanf("%f",temp);
						
						if((Q->rear)->data == NULL){
						(Q->rear)->data = temp;
						(Q->rear)->flag = sign2;
						(Q->front)->data = temp;
						(Q->front)->flag = sign2;
						printf("��ӳɹ���\n\n");
						Q->length++;
						return TRUE;
					}else{
						Node *new = (Node*)malloc(sizeof(Node));
						new->data = temp;
						new->flag = sign2;
						new->next = Q->rear;
						Q->rear = new;
						printf("��ӳɹ���\n\n");
						Q->length++;
						return TRUE;
					}
						break;
					}
					case 3:{
						char*temp=(char*)data;
					//	temp = (char *)malloc(sizeof(char);
						printf("��������ӵ����ݣ�\n\n");
						fflush(stdin);
						//scanf("%c",temp);
						*temp = getchar();
						//printf("%c\n",*temp);
						
							if((Q->rear)->data == NULL){
							(Q->rear)->data = temp;
							(Q->rear)->flag = sign2;
							(Q->front)->data = temp;
						(Q->front)->flag = sign2;
							printf("��ӳɹ���\n\n");
							Q->length++;
							return TRUE;
						}else{
							Node *new = (Node*)malloc(sizeof(Node));
							new->data = temp;
							new->flag = sign2;
							new->next = Q->rear;
							Q->rear = new;
							printf("��ӳɹ���\n\n");
							Q->length++;
							return TRUE;
						}
						break;
					}
					case 4:{
						char*temp=(char*)data;
					//	temp = (char *)malloc(sizeof(1024));
						printf("��������ӵ����ݣ�\n\n");
						fflush(stdin);
						scanf("%s",temp);
						
							if((Q->rear)->data == NULL){
							(Q->rear)->data = temp;
							(Q->rear)->flag = sign2;
							(Q->front)->data = temp;
						(Q->front)->flag = sign2;
							printf("��ӳɹ���\n\n");
							Q->length++;
							return TRUE;
						}else{
							Node *new = (Node*)malloc(sizeof(Node));
							new->data = temp;
							new->flag = sign2;
							new->next = Q->rear;
							Q->rear = new;
							printf("��ӳɹ���\n\n");
							Q->length++;
							return TRUE;
						}
						break;
					}
					
				}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("������δ��ʼ�������ȳ�ʼ�����У�\n\n");
		return FALSE;
	}
	if((Q->front)->data==NULL){
		printf("����Ϊ�գ�������ӣ�\n\n");
		return FALSE;
	}else{
		if((Q->front)->data != NULL){
			//(Q->front)->data = NULL;
			(Q->rear)->data = NULL;
			Q->length--;
			printf("���ӳɹ���\n\n");
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
			printf("���ӳɹ���\n\n");
			return TRUE;
		}
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->front==NULL||Q->rear==NULL){
		printf("������δ��ʼ�������ȳ�ʼ�����У�\n\n");
		return FALSE;
	}
	if((Q->front)->data==NULL){
		printf("����Ϊ�գ�������ӣ�\n\n");
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
		printf("��ճɹ���\n\n");
		return TRUE;
		
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,int *flag1)){
	if(Q->front==NULL||Q->rear==NULL){
		printf("������δ��ʼ�������ȳ�ʼ�����У�\n\n");
		return FALSE;
	}
	if((Q->front)==(Q->rear)&&(Q->front)->data==NULL){
		printf("����Ϊ�գ�������ӣ�\n\n");
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
 *    @description : ��������
 *    @param         q ָ��q
 
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
		printf("*  1.��ʼ������               2.���              *\n\n");
		printf("*  3.����                     4.ȷ�����г���      *\n\n");
		printf("*  5.ȷ������Ϊ��             6.��������          *\n\n");
		printf("*  7.��ն���                 8.���ٶ���          *\n\n");
		printf("*  9.�鿴��ͷ����             0.�˳�              *\n\n");
		printf("***************************************************\n\n");
		printf("�밴ѡ������Ҫ���еĲ�����\n\n");
}

void Menu2(){
		printf("**********************************************\n\n");
		printf("*  1.����                     2.������       *\n\n");
		printf("*  3.�ַ���                   4.�ַ���       *\n\n");
		printf("**********************************************\n\n");
		printf("�밴ѡ������Ҫ��ӵ��������ͣ�\n\n");
}



