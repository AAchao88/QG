#include<stdio.h>
#include<stdlib.h>
#include"calculator.h"

/*
	�ü���������һ��char����洢�û��������׺���ʽ�ַ�����һ��int����洢��׺���ʽ ��
	һ����ջ��ʵ����׺ת��׺�����֮������գ�Ȼ�����������׺���ʽ��	 
*/

int main(){
	char infix[100];
	//�洢�û��������׺���ʽ 
	int suffix[100];
	//�洢��׺���ʽ 
	LinkStack *in = (LinkStack*)malloc(sizeof(LinkStack));
	in->top = NULL; 
	int finalresult,temp=0;
	//���ս�� ���ݴ���� 
	initLStack(in);
	//��ʼ��ջ 
	
	
	while(1){
		//������׺ת��׺����ջ 
	
		printf("\n��������Ҫ�����������ʽ��\n\n");
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
				//ת��ʱջ���ַ� 
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
		
		
		
		//��׺���ʽ�ļ���
		j=0;
		clearLStack(in);
		//���ջ
		int top,topnext=0,result;
		//��׺����ʱ���ֵ��ݴ���� 
		
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
		printf("\n������Ϊ��%d\n\n",finalresult);
		
		clearLStack(in);
		//���ջ
		system("pause");
		system("cls");
		
	} 

	return 0; 
}

