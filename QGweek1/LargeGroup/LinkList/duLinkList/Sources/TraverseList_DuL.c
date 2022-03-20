#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
	
		
	DuLinkedList p = L->next;
	while(p != NULL){
	    (*visit)(p->data);
		p = p->next;
	}
	
	printf("\n");
}
