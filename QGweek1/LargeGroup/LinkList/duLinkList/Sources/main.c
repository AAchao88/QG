#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

void visit(ElemType e);//删除函数要调用的打印函数声明 

int main(){
	
	DuLinkedList *L = (DuLinkedList *)malloc(sizeof(DuLinkedList));
	*L = NULL;
	int sign;//输入的菜单编号
	do{
		console();
	    do{
	    	scanf("%d",&sign);
	    	if(sign<0||sign>5){
	    		printf("输入有误，请输入正确的菜单编号!\n\n");
			}else{
				break;
			}
		}while(sign<0||sign>5);
		printf("\n");
    	switch(sign){
			case 1:InitList_DuL(L);break;
			case 2:{
					//异常处理 
				if((*L) == NULL||(*L)->next == NULL){
					printf("尚未创建链表或链表为空，请先创建链表并往后插入元素！\n\n");
					break;
				}
				
				int count=0,n=0,flag=0;
				ElemType data;
			    while(n<=0){
			    	printf("请输入在 第几个的前面 插入以及 要插入的数据。!!!!!!! 注意两个数据以空格分开 !!!!!!\n\n");
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
					printf("链表当前共有%d个元素，无法插入到第%d个的前面!\n\n",count,n);
				}else{
					InsertBeforeList_DuL(p,q);
				}
				break;
			}
			case 3:
				{
					//异常处理 
				if((*L) == NULL){
					printf("尚未创建链表，请先创建链表！\n\n");
					break;
				}
				
				int count=0,n=0,flag=0;
				ElemType data;
				
				if((*L)->next == NULL){
			    		printf("现在链表为空，请输入第一个元素的数据：\n\n");
			    		scanf("%d",&data); 
			    		DuLNode* p = *L;
						DuLNode*q = (DuLinkedList)malloc(sizeof(DuLNode));
						q->data = data;
						InsertAfterList_DuL(p,q);
			    		break;
					}
				
			    while(n<=0){
			    	printf("请输入在 第几个的后面 插入以及 要插入的数据: !!!!!!! 注意两个数据以空格分开 !!!!!!\n\n");
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
					printf("链表当前共有%d个元素，无法插入到第%d个的后面！\n\n",count,n);
				}else InsertAfterList_DuL(p,q);
				break;
			}
			case 4:{
					//异常处理 
				if((*L) == NULL){
					printf("尚未创建链表，请先创建链表！\n\n");
					break;
				}
				int count=0,n=0,flag=0;
				ElemType e;
			    while(n<=0){
			    	printf("请输入删除第几个\n\n");
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
					printf("链表当前共有%d个元素，无法删除第%d个\n\n",count,n);
				}else{
					DeleteList_DuL(p,&e);
				}
				break;
			}
			case 5: {
					//异常处理 
				if((*L) == NULL){
					printf("尚未创建链表，请先创建链表！\n\n");
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
