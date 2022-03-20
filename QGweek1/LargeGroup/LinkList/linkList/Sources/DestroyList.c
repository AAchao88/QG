#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

void DestroyList(LinkedList *L){
	
	//异常处理 
	if(*L == NULL){
		printf("尚未创建链表，请先创建链表！\n\n");
		return ;
	}
	
	LNode* p = *L;
	LNode* q ; 
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	printf("销毁成功！\n\n");
	
}
