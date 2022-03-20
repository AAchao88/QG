#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

Status SearchList(LinkedList L, ElemType e){
	
	
	LinkedList p = L;
	while(p != NULL){
		if(p->data == e){
			printf("%d",e);
			return SUCCESS;
		}else{
			p = p->next;
		}
	}
	
	printf("≤È—Ø≥…π¶£°\n\n");

	return ERROR;
}
