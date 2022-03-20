#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

LNode* FindMidNode(LinkedList *L){
	
	//异常处理 
	if(*L == NULL){
		printf("尚未创建链表，请先创建链表！\n\n");
		return NULL;
	}
	
	LNode *p,*q,*k;
	p=(*L)->next;
	q=p;
	if(p == NULL){
		printf("无元素\n");
		return NULL ;
	}
	
	if(q->next == NULL){
		printf("只有一个元素，无中点！\n");
		return NULL;
	}
	


	for(;q->next != NULL;){
		q=q->next;
		if(q->next == NULL){
				printf("中点值为：%d\n",p->data);
			return p;
		}
		q=q->next;
		p=p->next;
		if(q->next == NULL){
				printf("中点值为：%d\n",p->data);
			return p;
		}
	}
	
	printf("中点值为：%d\n\n",p->data);
	
	return p;
	
	
}
