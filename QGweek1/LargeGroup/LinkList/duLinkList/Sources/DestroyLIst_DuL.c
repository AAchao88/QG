#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

void DestroyList_DuL(DuLinkedList *L){
	
	DuLNode* p = *L;
	DuLNode* q ; 
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	printf("��������ɹ���\n\n");
	
}
