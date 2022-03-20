#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
void TraverseList(LinkedList L, void (*visit)(ElemType e)){
	
	LinkedList p = L->next;
	while(p != NULL){
	    (*visit)(p->data);
		p = p->next;
	}
	
	

	
}
