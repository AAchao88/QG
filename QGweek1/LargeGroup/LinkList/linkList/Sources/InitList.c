#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

Status InitList(LinkedList *L){

	LNode* head = (LNode*)malloc(sizeof(LNode));
	*L =head;
	head->next = NULL;
	
	printf("�����ɹ���\n\n");
	
	return SUCCESS;
	//����ͷ��� 
}
