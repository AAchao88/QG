#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

Status IsLoopList(LinkedList L){
	
	
	LNode *p,*q,*k;
	q=p=L->next;
	if(p == NULL){
		printf("无元素，不成环！\n");
		return SUCCESS;
	}
	if(q->next == NULL){
		printf("只有一个元素，不成环！\n");
		return SUCCESS;
	}
	
	while(q->next != NULL){
		q = q->next;
		if(q->next == NULL){
			printf("不成环！\n\n");
			return SUCCESS;
		}
		q = q->next;
		p = p->next;
		if(p == q){
			printf("成环！\n\n");
			return SUCCESS;
		}
	}
	
	printf("不成环！\n\n");
	return SUCCESS;
	
}
