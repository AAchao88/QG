#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

Status ReverseList(LinkedList *L){
	
	//�쳣���� 
	if(*L == NULL){
		printf("��δ�����������ȴ�������\n\n");
		return SUCCESS;
	}
	
	LNode *p,*q,*head,*temp;
	head = *L;
	p = head->next;
	if(p == NULL) return SUCCESS;
	q = p->next;
	while(q!= NULL){
			if(p == head->next) p->next = NULL;
			temp = q->next;
			q->next = p;
			p = q;
			q = temp;
		
	}
	head->next = p;
	printf("��ת�ɹ���\n\n");
	
	return SUCCESS;
	
}
