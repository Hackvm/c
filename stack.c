#include<stdio.h>
#define MAX 5
int st[MAX], top=-1;
//void push(int st[],int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(int argc, char *argv[]){
    int val,option;
    do{
        printf("\n--------------------------main menu-------------------------------");
        printf("\n1.PUSH\n2.POP\n3.PEEk\n4.DISPLAY\n5.Exit");
        printf("\nEnter the choosen Number:");
        scanf("%d",&option);
        switch(option){
            case 1:
            printf("\n Enter the number  to be pushed on stack:");
            scanf("%d",&val);
            //push(st,val);
            break;

            case 2:
            val=pop(st);
            if(val!=-1)
                printf("\n The value deleted from stack is:%d",val);
                break;

            case 3:
            val = peek(st);
            if(val!=1)
            printf("\n the value stored at top of stack is:%d",val);
            break;

            case 4:
            display(st);
            break;

            default:
            printf("\nEnter The wrong number");
            
        }
    }while(option!=5);
    return 0;
}


//void push(int st[],int val){
    if (top == MAX-1){
        printf("\n Stack OverFlow");
    }
    else{
        top++;
        st[top]=val;
    }
}


int pop(int st[]){
    int val;
    if (top == -1){
        printf("\n Stack UNderFlow");
    }
    else {
        val =st[top];
        top--;
        return val;
    }
}



void display(int st[]){
    int i=0;
    if (top==-1){
        printf("\n Stack Iss Empty");
    }

    else {
        while(i<=top){
            printf("\t%d",st[i]);
	    i++;
        }
    }
}



int peek(int st[]){
    if (top==-1){
        printf("\n Stack is Empty");
        return -1;
    }

    else{
        return (st[top]);
    }
}
