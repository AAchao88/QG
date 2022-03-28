#include"LinkStack.h"
#include<stdio.h>
#include<stdlib.h>


int main(){
	
	
	
	LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
	s->top = NULL;
	
	int sign;//输入的菜单编号
	do{
		printf("**************************************************************\n\n");
		printf("*    1.初始化链栈                         2.入栈             *\n\n");
		printf("*    3.出栈                               4.获取栈顶元素     *\n\n");
		printf("*    5.检测栈长度                         6.判断栈为空       *\n\n");
		printf("*    7.清空栈                             8.销毁栈           *\n\n");
		printf("*    0.退出系统                                              *\n\n");
		printf("**************************************************************\n\n");
		printf("请输入菜单编号：\n"); 
		
	    do{
	    	scanf("%d",&sign);
	    	if(sign<0||sign>8){
	    		printf("输入有误，请输入正确的菜单编号!\n\n");
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
					printf("栈尚未初始化，请先初始化栈！\n\n");
					break;
				} 
				ElemType data;
				printf("请输入入栈的数据：\n");
				scanf("%d",&data);
				pushLStack(s,data);
				break;
			}
			case 3:{
				if(s->top == NULL){
					printf("栈尚未初始化，请先初始化栈！\n\n");
					break;
				} 
				if(s->count == 0){
					printf("栈为空！请先入栈！\n\n");
					break;
				}
				ElemType data;
				popLStack(s,&data);
				printf("出栈的元素为：%d\n\n",data);
				break;
			}
				
			case 4:{
				ElemType e;
				
				if(getTopLStack(s,&e)){
					printf("得到的元素为：%d\n\n",e);
				}
				break;
			}
			case 5: {
				if(s->top == NULL){
					printf("栈尚未初始化，请先初始化栈！\n\n");
					break;
				}else{
					int length;
					LStackLength(s,&length);
					printf("栈的长度为：%d\n\n",length);
					break;
				}
			}
			case 6:{
				isEmptyLStack(s);
				break;
			}
			case 7:{
				if(clearLStack(s)){
					printf("清空成功！\n\n");
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
