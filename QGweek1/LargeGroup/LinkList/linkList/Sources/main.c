#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
int main(){
	void visit(ElemType e);//删除函数要调用的打印函数声明 
	
	LinkedList *L = (LinkedList*)malloc(sizeof(LinkedList));
	*L = NULL;
	int sign;
    do{
    	console();
	    scanf("%d",&sign); printf("\n\n");
	    
    	switch(sign){
			case 1:InitList(L);break;
			case 2:{
				//异常处理 
				if((*L) == NULL){
					printf("尚未创建链表，请先创建链表！\n\n");
					break;
				}
				
				int count=0,n=0,flag=0;
				ElemType data;
			    while(n<=0){
			    	printf("请输入 插入到第几个 以及 要插入的数据：!!!!!!! 注意以空格分开 !!!!!!\n\n");
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
					printf("链表当前共有%d个元素，无法插入到第%d个\n",count,n);
				}else InsertList(p,q);
				break;
			}
			case 3:{
						//异常处理 
				if((*L) == NULL){
					printf("尚未创建链表，请先创建链表！\n\n");
					break;
				}
				
				int count=0,n=0,flag=0;
				ElemType e;
			    while(n<=0){
			    	printf("请输入删除第几个\n");
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
					printf("链表当前共有%d个元素，无法删除第%d个",count,n);
				}else DeleteList(p,&e);
				break;
			}
			case 4:{
						//异常处理 
				if((*L) == NULL){
					printf("尚未创建链表，请先创建链表！\n\n");
					break;
				}
				
				printf("请输入要查询的值：");
				ElemType e;
				scanf("%d",&e);
				SearchList(*L,e);
				break;
			}
			case 5:
					//异常处理 
				if((*L) == NULL){
					printf("尚未创建链表，请先创建链表！\n\n");
					break;
				}
			    TraverseList(*L,visit);
				break;
			case 6: ReverseList(L);break;
			case 7:
					//异常处理 
				if((*L) == NULL){
					printf("尚未创建链表，请先创建链表！\n\n");
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

	
