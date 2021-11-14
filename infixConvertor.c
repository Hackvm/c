#include<stdio.h>
#define MAX 20

int priority(char ch);
void Infix_Postfix(char infix[],char postfix[]);

void push(int);
int pop();
int peek();

int isEmpty();
int isFull();

void display();

char st[MAX];
int top = -1;

void main()
{
	char infix[50],postfix[50];
	printf("Enter Intfix expression\n");
	getw(infix);
	Infix_Postfix(infix,postfix);
	printf("\nPostfix expression is\n");
	puts(postfix);
}

void Infix_Postfix(char infix[],char postfix[])
{
	int i,j=0;
	for(i=0;infix[i]!='\0';i++)
	{
		if(isalnum(infix[i]))
			postfix[j++]=infix[i];
		else if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]==')')
		{
			while(st[top]!='(')
				postfix[j++]=pop();
			pop();
		}
		else
		{
			while(!isEmpty()&&(priority(st[top])>=priority(infix[i])))
				postfix[j++]=pop();
			push(infix[i]);
		}
	}
	while(!isEmpty())
		postfix[j++]=pop();
	postfix[j]='\0';
}

int priority(char ch)
{
	if(ch=='^')
		return 3;
	if(ch=='*' || ch=='/' )
		return 2;
	if(ch=='+' || ch=='-')
		return 1;
	if(ch=='(')
		return 0;
}

void push(int x)
{
	top++;
	st[top]=x;
}

int pop()
{
	int x;
	x=st[top];
	top--;
	return x;
}

int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull()
{
	if(top==MAX-1)
		return 1;
	else
	return 0;
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("Stack Empty");
	}
	else
	{
		printf("Elements in stack are\n");
		for(i=top;i>=0;i--)
		{
			printf("%d",st[i]);
			printf("\n");
		}
	}
}

int peek()
{
	if(top==-1)
	{
		printf("\nStack Empty");
		return -1;
	}
	else
	{
		return (st[top]);
	}
}