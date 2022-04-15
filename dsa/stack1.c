#include<stdio.h>
#define MAX 5

int st[MAX], top=-1;
void push (int str[]);
int pop(int str[]);
void display(int str[]);
int peek(int str[]);


void main(){
    int data,chosen;
    do{
        printf("\n----------------------------------The Main Menu -----------------------------------");
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.Display\n5.Exit");
        printf("\nEnter the Chossen Number:");
        scanf("%d",&chosen);
        switch(chosen){
            case 1:
            push(st);
            break;

            case 2:
            data =pop(st);
            break;

            case 3:
            data = peek(st);
            break;

            case 4:
            display(st);
            break;

            default:
            printf("You Enter the Wrong Number");

        }
    }while(chosen!=5);
}


void push(int str[]){
    int data;
    if (top==MAX-1){
        printf("\n Stack OverFlow");
    }
    else{
        top=top+1;
        printf("\n\tEnter the data you want to push in stack:");
        scanf("%d",&data);
        str[top]=data;
    }
}

int pop(int str[]){
    int data;
    if(top==-1){
        printf("\n Stack UnderFlow");
    }
    else{
        data = str[top];
        top=top-1;
        return data;
    }
}


void display(int str[]){
    int i=0;
    if(top == -1){
        printf("\n Stack Underflow");
    }
    else{
        while(i<=top){
            printf("\t%d",str[i]);
            i++;
        }

    }
}


int peek(int str[]){
    int data;
    if(top==MAX-1){
        printf("\n Stack Overflow");
    }

    else{
        data = str[top];
        printf("\n  The last element in the stack : %d",data); 
    }
    return 0;
}

