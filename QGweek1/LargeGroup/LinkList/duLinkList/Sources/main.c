#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

void visit(ElemType e);//ɾ������Ҫ���õĴ�ӡ�������� 

int main(){
	
	DuLinkedList *L = (DuLinkedList *)malloc(sizeof(DuLinkedList));
	*L = NULL;
	int sign;//����Ĳ˵����
	do{
		console();
	    do{
	    	scanf("%d",&sign);
	    	if(sign<0||sign>5){
	    		printf("����������������ȷ�Ĳ˵����!\n\n");
			}else{
				break;
			}
		}while(sign<0||sign>5);
		printf("\n");
    	switch(sign){
			case 1:InitList_DuL(L);break;
			case 2:{
					//�쳣���� 
				if((*L) == NULL||(*L)->next == NULL){
					printf("��δ�������������Ϊ�գ����ȴ��������������Ԫ�أ�\n\n");
					break;
				}
				
				int count=0,n=0,flag=0;
				ElemType data;
			    while(n<=0){
			    	printf("�������� �ڼ�����ǰ�� �����Լ� Ҫ��������ݡ�!!!!!!! ע�����������Կո�ֿ� !!!!!!\n\n");
			    	scanf("%d %d",&n,&data);
				}
				n=n+1;
				DuLNode* head = *L;
				DuLNode*p,*q;
				q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = data; 
			
				while(head != NULL){
					if(count+1 == n){
						p = head;
						flag=1;
						break;
					}else{	
					head = head->next;
					count++;
					}
				}
				if(flag == 0){
					printf("����ǰ����%d��Ԫ�أ��޷����뵽��%d����ǰ��!\n\n",count,n);
				}else{
					InsertBeforeList_DuL(p,q);
				}
				break;
			}
			case 3:
				{
					//�쳣���� 
				if((*L) == NULL){
					printf("��δ�����������ȴ�������\n\n");
					break;
				}
				
				int count=0,n=0,flag=0;
				ElemType data;
				
				if((*L)->next == NULL){
			    		printf("��������Ϊ�գ��������һ��Ԫ�ص����ݣ�\n\n");
			    		scanf("%d",&data); 
			    		DuLNode* p = *L;
						DuLNode*q = (DuLinkedList)malloc(sizeof(DuLNode));
						q->data = data;
						InsertAfterList_DuL(p,q);
			    		break;
					}
				
			    while(n<=0){
			    	printf("�������� �ڼ����ĺ��� �����Լ� Ҫ���������: !!!!!!! ע�����������Կո�ֿ� !!!!!!\n\n");
						scanf("%d %d",&n,&data);
						n=n+1;
				}
			
				DuLNode* head = *L;
				DuLNode*p,*q;
				q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = data;
			
				while(head != NULL){
					if(count+1 == n){
						p = head;
						flag=1;
						break;
					}else{	
					head = head->next;
					count++;
					}
				}
				if(flag == 0){
					printf("����ǰ����%d��Ԫ�أ��޷����뵽��%d���ĺ��棡\n\n",count,n);
				}else InsertAfterList_DuL(p,q);
				break;
			}
			case 4:{
					//�쳣���� 
				if((*L) == NULL){
					printf("��δ�����������ȴ�������\n\n");
					break;
				}
				int count=0,n=0,flag=0;
				ElemType e;
			    while(n<=0){
			    	printf("������ɾ���ڼ���\n\n");
			    	scanf("%d",&n);
				}
				DuLNode* head = *L;
				DuLNode*p;
				while(head != NULL){
					if(count+1 == n){
						p = head;
						flag=1;
						break;
					}else{	
					head = head->next;
					count++;
					}
				}
				if(flag == 0){
					printf("����ǰ����%d��Ԫ�أ��޷�ɾ����%d��\n\n",count,n);
				}else{
					DeleteList_DuL(p,&e);
				}
				break;
			}
			case 5: {
					//�쳣���� 
				if((*L) == NULL){
					printf("��δ�����������ȴ�������\n\n");
					break;
				}
				TraverseList_DuL(*L,visit);
				break;	
			}
			case 0:{
				DestroyList_DuL(L);
				free(L);
				break;	
			
			} 
		}
		system("pause");
		system("cls");
	} while(sign != 0);
}


void visit(ElemType e){
	printf("%d\n",e);
}
