#include "calculator.h" 
#include<stdio.h>
#include<stdlib.h>
//链栈

//初始化栈
Status initLStack(LinkStack *s){
		s->top = (StackNode*)malloc(sizeof(StackNode));
		s->count = 0;
		(s->top)->next = NULL; 
		//printf("初始化成功！\n\n");
		return SUCCESS;

}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s->top == NULL){
		printf("栈尚未初始化，请先初始化栈！\n\n");
		return ERROR;
	} 
	if(s->count == 0){
		printf("栈为空！\n\n");
		return SUCCESS; 
	}else{
		printf("栈不为空！\n\n");
		return SUCCESS;
	}
}

//得到栈顶元素
ElemType getTopLStack(LinkStack *s){

	StackNode *head = s->top;
	return head->data;
}

//清空栈
Status clearLStack(LinkStack *s){
	if(s->top == NULL){
		printf("栈尚未初始化，请先初始化栈！\n\n");
		return ERROR;
	} 
	StackNode *head = s->top;
	while(head->next != NULL){
		s->top = head->next;
		free(head);
		head = s->top;
	}
	s->count = 0;
	
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s){
	if(clearLStack(s)){
		StackNode * head = s->top;
		free(head);
		s->top = NULL;
		printf("销毁成功！\n\n");
		return SUCCESS;
	}else{
		return ERROR;
	}
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	*length = s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	
	StackNode *head = s->top;
	StackNode *new = (StackNode *)malloc(sizeof(StackNode));
	new->data = data;
	s->top = new;
	new->next = head;
	(s->count)++;
	//printf("入栈成功！\n\n");
	return SUCCESS;
	
}

//出栈
ElemType popLStack(LinkStack *s){
	
	StackNode *head = s->top;
	ElemType data = head->data;
	s->top = head->next;
	free(head);
	(s->count)--;
	//printf("出栈成功！\n\n");
	return data;
	
}


