#include"LinkStack.h"
#include<stdio.h>
#include<stdlib.h>


int main(){
	
	
	
	LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
	s->top = NULL;
	
	int sign;//����Ĳ˵����
	do{
		printf("**************************************************************\n\n");
		printf("*    1.��ʼ����ջ                         2.��ջ             *\n\n");
		printf("*    3.��ջ                               4.��ȡջ��Ԫ��     *\n\n");
		printf("*    5.���ջ����                         6.�ж�ջΪ��       *\n\n");
		printf("*    7.���ջ                             8.����ջ           *\n\n");
		printf("*    0.�˳�ϵͳ                                              *\n\n");
		printf("**************************************************************\n\n");
		printf("������˵���ţ�\n"); 
		
	    do{
	    	scanf("%d",&sign);
	    	if(sign<0||sign>8){
	    		printf("����������������ȷ�Ĳ˵����!\n\n");
			}else{
				break;
			}
		}while(sign<0||sign>8);
		printf("\n");
		
    	switch(sign){
			case 1:{
				
				initLStack(s);
				break;
			}
			case 2:{
				if(s->top == NULL){
					printf("ջ��δ��ʼ�������ȳ�ʼ��ջ��\n\n");
					break;
				} 
				ElemType data;
				printf("��������ջ�����ݣ�\n");
				scanf("%d",&data);
				pushLStack(s,data);
				break;
			}
			case 3:{
				if(s->top == NULL){
					printf("ջ��δ��ʼ�������ȳ�ʼ��ջ��\n\n");
					break;
				} 
				if(s->count == 0){
					printf("ջΪ�գ�������ջ��\n\n");
					break;
				}
				ElemType data;
				popLStack(s,&data);
				printf("��ջ��Ԫ��Ϊ��%d\n\n",data);
				break;
			}
				
			case 4:{
				ElemType e;
				
				if(getTopLStack(s,&e)){
					printf("�õ���Ԫ��Ϊ��%d\n\n",e);
				}
				break;
			}
			case 5: {
				if(s->top == NULL){
					printf("ջ��δ��ʼ�������ȳ�ʼ��ջ��\n\n");
					break;
				}else{
					int length;
					LStackLength(s,&length);
					printf("ջ�ĳ���Ϊ��%d\n\n",length);
					break;
				}
			}
			case 6:{
				isEmptyLStack(s);
				break;
			}
			case 7:{
				if(clearLStack(s)){
					printf("��ճɹ���\n\n");
					break;
				}else{
					break;
				}
			}
			case 8:{
				destroyLStack(s);
				break;
			}
			case 0:break;
		}
		system("pause");
		system("cls");
	} while(sign != 0);
	return 0;
}
