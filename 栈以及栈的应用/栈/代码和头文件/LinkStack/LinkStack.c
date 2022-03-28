#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	if(s->top != NULL){
		printf("ջ�ѳ�ʼ���������ظ���\n\n");
		return ERROR;
	}else{
		s->top = (StackNode*)malloc(sizeof(StackNode));
		s->count = 0;
		(s->top)->next = NULL; 
		printf("��ʼ���ɹ���\n\n");
		return SUCCESS;
	}
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
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top == NULL){
		printf("ջ��δ��ʼ�������ȳ�ʼ��ջ��\n\n");
		return ERROR;
	} 
	if(s->count == 0){
		printf("ջΪ�գ�������ջ��\n\n");
		return ERROR; 
	}
	*e = (s->top)->data;
	return SUCCESS;
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
	printf("��ջ�ɹ���\n\n");
	return SUCCESS;
	
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	
	StackNode *head = s->top;
	*data = head->data;
	s->top = head->next;
	free(head);
	(s->count)--;
	printf("��ջ�ɹ���\n\n");
	return SUCCESS;
	
}



