#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
	
	q->next = p->next;
	if(p->next == NULL){
		p->next = q;
		q->prior = p;
		printf("����ɹ���\n\n");
		return SUCCESS;
	}
	
	(p->next)->prior = q;
	p->next = q;
	q->prior = p;
	printf("����ɹ���\n\n");
	return SUCCESS;
}
