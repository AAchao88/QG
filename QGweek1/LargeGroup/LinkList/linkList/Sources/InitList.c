#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

Status InitList(LinkedList *L){

	LNode* head = (LNode*)malloc(sizeof(LNode));
	*L =head;
	head->next = NULL;
	
	printf("创建成功！\n\n");
	
	return SUCCESS;
	//创建头结点 
}
