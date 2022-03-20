#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

Status DeleteList_DuL(DuLNode *p, ElemType *e){
	
	DuLinkedList q = p->next;
	*e =  q->data;
	p->next = q->next;
	free(q);
	printf("É¾³ý³É¹¦£¡\n\n");
	return SUCCESS;
}
	
