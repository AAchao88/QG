#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

LNode* FindMidNode(LinkedList *L){
	
	//�쳣���� 
	if(*L == NULL){
		printf("��δ�����������ȴ�������\n\n");
		return NULL;
	}
	
	LNode *p,*q,*k;
	p=(*L)->next;
	q=p;
	if(p == NULL){
		printf("��Ԫ��\n");
		return NULL ;
	}
	
	if(q->next == NULL){
		printf("ֻ��һ��Ԫ�أ����е㣡\n");
		return NULL;
	}
	


	for(;q->next != NULL;){
		q=q->next;
		if(q->next == NULL){
				printf("�е�ֵΪ��%d\n",p->data);
			return p;
		}
		q=q->next;
		p=p->next;
		if(q->next == NULL){
				printf("�е�ֵΪ��%d\n",p->data);
			return p;
		}
	}
	
	printf("�е�ֵΪ��%d\n\n",p->data);
	
	return p;
	
	
}
