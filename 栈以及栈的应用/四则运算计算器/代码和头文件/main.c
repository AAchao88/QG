#include<stdio.h>
#include<stdlib.h>
#include"calculator.h"

/*
	该计算器采用一个char数组存储用户输入的中缀表达式字符串，一个int数组存储后缀表达式 ，
	一个链栈来实现中缀转后缀，完成之后再清空，然后用来计算后缀表达式。	 
*/

int main(){
	char infix[100];
	//存储用户输入的中缀表达式 
	int suffix[100];
	//存储后缀表达式 
	LinkStack *in = (LinkStack*)malloc(sizeof(LinkStack));
	in->top = NULL; 
	int finalresult,temp=0;
	//最终结果 和暂存变量 
	initLStack(in);
	//初始化栈 
	
	
	while(1){
		//用于中缀转后缀的链栈 
	
		printf("\n请输入您要计算的四则表达式：\n\n");
		//gets(infix);
		scanf("%s",infix);
		int i = 0,j=0;
		
		while(infix[i] != '\0'){
			if(infix[i]>='0'&&infix[i]<='9'){
				while(infix[i]>='0'&&infix[i]<='9'){
					temp = (temp*10)+(infix[i]-48);
					i++;
				}
				suffix[j] = temp;
				temp=0;
				j++;
				continue;
				//suffix[j]='\0';
			}else{
				if(infix[i]=='('){
				pushLStack(in,infix[i]);
				//转化时栈放字符 
			}else{
				if(infix[i]==')'){
				while(getTopLStack(in)!='('){
					suffix[j] = popLStack(in);
					j++;
				}
				popLStack(in);
			}else{
				while(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'){
					if(in->count==0){
						pushLStack(in,infix[i]);
						break;
					} 
					if((getTopLStack(in)=='(')||((infix[i]=='*'||infix[i]=='/')&&((getTopLStack(in)=='+')||(getTopLStack(in)=='-')))){
						pushLStack(in,infix[i]);
						break;
					}else{
						suffix[j]=popLStack(in);
						j++;
					}
		}
			}
			}
			}
			
			i++;
		}
		while(in->count!=0){
			suffix[j] = popLStack(in);
			j++;
		}
		suffix[j]='\0';
		
		
		
		//后缀表达式的计算
		j=0;
		clearLStack(in);
		//清空栈
		int top,topnext=0,result;
		//后缀计算时数字的暂存变量 
		
		while(suffix[j]!='\0'){
			
				switch(suffix[j]){
					case '+':{
						top=popLStack(in);
						topnext=popLStack(in);
						result=topnext+top;
						pushLStack(in,result);
						break;
					}
					case '-':{
						top=popLStack(in);
						topnext=popLStack(in);
						result=topnext-top;
						pushLStack(in,result);
						break;
					}
					case '*':{
						top=popLStack(in);
						topnext=popLStack(in);
						result=topnext*top;
						pushLStack(in,result);
						break;
					}
					case '/':{
						top=popLStack(in);
						topnext=popLStack(in);
						result=topnext/top;
						pushLStack(in,result);
						break;
					}
					default:{
						pushLStack(in,suffix[j]);
						break;
					}
				}
			j++;
		}
		
		finalresult = getTopLStack(in); 
		printf("\n计算结果为：%d\n\n",finalresult);
		
		clearLStack(in);
		//清空栈
		system("pause");
		system("cls");
		
	} 

	return 0; 
}

