#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
int main(){
	void visit(ElemType e);//ɾ������Ҫ���õĴ�ӡ�������� 
	
	LinkedList *L = (LinkedList*)malloc(sizeof(LinkedList));
	*L = NULL;
	int sign;
    do{
    	console();
	    scanf("%d",&sign); printf("\n\n");
	    
    	switch(sign){
			case 1:InitList(L);break;
			case 2:{
				//�쳣���� 
				if((*L) == NULL){
					printf("��δ�����������ȴ�������\n\n");
					break;
				}
				
				int count=0,n=0,flag=0;
				ElemType data;
			    while(n<=0){
			    	printf("������ ���뵽�ڼ��� �Լ� Ҫ��������ݣ�!!!!!!! ע���Կո�ֿ� !!!!!!\n\n");
			    	scanf("%d %d",&n,&data);
				}
				
				LNode* head = *L;
				LNode*p,*q;
				q = (LinkedList)malloc(sizeof(LNode));
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
					printf("����ǰ����%d��Ԫ�أ��޷����뵽��%d��\n",count,n);
				}else InsertList(p,q);
				break;
			}
			case 3:{
						//�쳣���� 
				if((*L) == NULL){
					printf("��δ�����������ȴ�������\n\n");
					break;
				}
				
				int count=0,n=0,flag=0;
				ElemType e;
			    while(n<=0){
			    	printf("������ɾ���ڼ���\n");
			    	scanf("%d",&n);
				}
				LNode* head = *L;
				LNode*p;
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
					printf("����ǰ����%d��Ԫ�أ��޷�ɾ����%d��",count,n);
				}else DeleteList(p,&e);
				break;
			}
			case 4:{
						//�쳣���� 
				if((*L) == NULL){
					printf("��δ�����������ȴ�������\n\n");
					break;
				}
				
				printf("������Ҫ��ѯ��ֵ��");
				ElemType e;
				scanf("%d",&e);
				SearchList(*L,e);
				break;
			}
			case 5:
					//�쳣���� 
				if((*L) == NULL){
					printf("��δ�����������ȴ�������\n\n");
					break;
				}
			    TraverseList(*L,visit);
				break;
			case 6: ReverseList(L);break;
			case 7:
					//�쳣���� 
				if((*L) == NULL){
					printf("��δ�����������ȴ�������\n\n");
					break;
				}
			    IsLoopList(*L);
				break;
			case 8:{
				LNode *newnode1 = FindMidNode(L);
				break;
			}
			case 9:{
				*L = ReverseEvenList(&(*L));
				break;
			}
			case 0: DestroyList(L);free(L);break;
			
		}
		system("pause");
		system("cls");
		
	}while(sign != 0); 
	
	return 0;
}

void visit(ElemType e){
	printf("%d\n",e);
}

	
