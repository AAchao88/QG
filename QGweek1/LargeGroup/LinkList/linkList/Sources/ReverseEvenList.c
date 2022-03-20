#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

LNode* ReverseEvenList(LinkedList *L){
	
	//�쳣���� 
	if(*L == NULL){
		printf("��δ�����������ȴ�������\n\n");
		return *L;
	}
	
	LNode *p,*q;
	p=q=(*L)->next;
	
	//������� 
	if(p == NULL||p->next == NULL){
		printf("������ż��ת��\n");
		return *L;
	}
	ElemType temp;

	//���Ĵ��� 
	for(;p->next != NULL;){
		q = p->next;
		
		temp = p->data;
		p->data = q->data;
		q->data = temp;
		
		if(q->next == NULL){
			return *L;
		}else{
			p = q->next;
		}
	} 
	printf("��ż��ת�ɹ���\n\n");

	
}
