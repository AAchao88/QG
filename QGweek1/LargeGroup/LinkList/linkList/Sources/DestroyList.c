#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

void DestroyList(LinkedList *L){
	
	//�쳣���� 
	if(*L == NULL){
		printf("��δ�����������ȴ�������\n\n");
		return ;
	}
	
	LNode* p = *L;
	LNode* q ; 
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	printf("���ٳɹ���\n\n");
	
}
