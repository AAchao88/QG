#include "calculator.h" 
#include<stdio.h>
#include<stdlib.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
		s->top = (StackNode*)malloc(sizeof(StackNode));
		s->count = 0;
		(s->top)->next = NULL; 
		//printf("��ʼ���ɹ���\n\n");
		return SUCCESS;

}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s->top == NULL){
		printf("ջ��δ��ʼ�������ȳ�ʼ��ջ��\n\n");
		return ERROR;
	} 
	if(s->count == 0){
		printf("ջΪ�գ�\n\n");
		return SUCCESS; 
	}else{
		printf("ջ��Ϊ�գ�\n\n");
		return SUCCESS;
	}
}

//�õ�ջ��Ԫ��
ElemType getTopLStack(LinkStack *s){

	StackNode *head = s->top;
	return head->data;
}

//���ջ
Status clearLStack(LinkStack *s){
	if(s->top == NULL){
		printf("ջ��δ��ʼ�������ȳ�ʼ��ջ��\n\n");
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

//����ջ
Status destroyLStack(LinkStack *s){
	if(clearLStack(s)){
		StackNode * head = s->top;
		free(head);
		s->top = NULL;
		printf("���ٳɹ���\n\n");
		return SUCCESS;
	}else{
		return ERROR;
	}
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	*length = s->count;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	
	StackNode *head = s->top;
	StackNode *new = (StackNode *)malloc(sizeof(StackNode));
	new->data = data;
	s->top = new;
	new->next = head;
	(s->count)++;
	//printf("��ջ�ɹ���\n\n");
	return SUCCESS;
	
}

//��ջ
ElemType popLStack(LinkStack *s){
	
	StackNode *head = s->top;
	ElemType data = head->data;
	s->top = head->next;
	free(head);
	(s->count)--;
	//printf("��ջ�ɹ���\n\n");
	return data;
	
}


