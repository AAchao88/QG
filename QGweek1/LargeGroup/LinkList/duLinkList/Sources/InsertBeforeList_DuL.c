#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q){
	
	q->prior = p->prior;
	if(p->prior == NULL){
		p->prior = q;
		q->next  =p;
		printf("插入成功！\n\n");
		return SUCCESS;
	}
	
	(p->prior)->next = q;
	p->prior = q;
	q->next  =p;
	
	printf("插入成功！\n\n");
	return SUCCESS;
}
