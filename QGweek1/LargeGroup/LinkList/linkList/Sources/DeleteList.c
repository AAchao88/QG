#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

Status DeleteList(LNode *p, ElemType *e){
	
	LinkedList q = p->next;
	*e =  q->data;
	p->next = q->next;
	free(q);
	printf("É¾³ý³É¹¦£¡\n\n");

	return SUCCESS;
	
	
}
