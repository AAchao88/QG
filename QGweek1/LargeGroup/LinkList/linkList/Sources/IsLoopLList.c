#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

Status IsLoopList(LinkedList L){
	
	
	LNode *p,*q,*k;
	q=p=L->next;
	if(p == NULL){
		printf("��Ԫ�أ����ɻ���\n");
		return SUCCESS;
	}
	if(q->next == NULL){
		printf("ֻ��һ��Ԫ�أ����ɻ���\n");
		return SUCCESS;
	}
	
	while(q->next != NULL){
		q = q->next;
		if(q->next == NULL){
			printf("���ɻ���\n\n");
			return SUCCESS;
		}
		q = q->next;
		p = p->next;
		if(p == q){
			printf("�ɻ���\n\n");
			return SUCCESS;
		}
	}
	
	printf("���ɻ���\n\n");
	return SUCCESS;
	
}
