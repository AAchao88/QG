#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
Status InsertList(LNode *p, LNode *q){
	
	
	q->next = p->next;
	p->next = q;
	
	printf("����ɹ���\n\n");

	return SUCCESS;
}
