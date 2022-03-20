#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

LNode* ReverseEvenList(LinkedList *L){
	
	//异常处理 
	if(*L == NULL){
		printf("尚未创建链表，请先创建链表！\n\n");
		return *L;
	}
	
	LNode *p,*q;
	p=q=(*L)->next;
	
	//分类操作 
	if(p == NULL||p->next == NULL){
		printf("无需奇偶反转。\n");
		return *L;
	}
	ElemType temp;

	//核心代码 
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
	printf("奇偶反转成功！\n\n");

	
}
