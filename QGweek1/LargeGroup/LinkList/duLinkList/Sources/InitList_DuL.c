#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

Status InitList_DuL(DuLinkedList *L){
	
	*L = (DuLNode*)malloc(sizeof(DuLNode));
	DuLNode *head = *L;
	head->next = NULL;
	head->prior = NULL;
	
	printf("��������ɹ���\n\n");
	return SUCCESS;
	
}
