#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};


struct node *first=NULL;
struct node * display();
struct node * creat();
struct node *pop();
struct node *push();
struct node *peek();

void main(){
    int choice;
    do{
    printf("\n1.To Create a Node.\n2.To Display Node.\n3.To use pop.\n4.To use push.\n5.To use peek.\n");
    printf("Enter Your Choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:

        first = creat(first);
        printf("The Stack is Created");
        break;

        case 2:
        printf("-----------------------------Displaying Stack-------------------------------\n");
        first = display(first);
        break; 

        case 3:
        printf("-----------------------------Poping from stack-------------------------\n");
        first = pop(first);
        break;

        case 4:
        printf("------------------------------Pushing in Stack------------------------\n");
        first=push(first);
        break;

        case 5:
        printf("-------------------------------Peek node vaolue in stack--------------------\n");
        first = peek(first);
        break;

        default:
        printf("------------------Enter the wrong choice----------------------\n");
        }
    }while(choice!=6);
}

struct node * display(struct node * first){
    struct node *ptr;
    ptr=first;
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    //printf("\t%d",ptr->data);
    return first;
}

struct node * push(struct node * first){
    struct node *ptr,*p;
    int a;
    ptr = (struct node *)(malloc(sizeof(struct node)));
    printf("Enter the Data:");
    scanf("%d",&a);
    ptr->data=a;
    if(first==NULL){
        ptr->next=NULL;
        first=ptr;
        return ptr;
    }
    else{
        p=first;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=ptr;
        ptr->next=NULL;
        return first;
    }
    //return first;
}

struct node *pop(struct node * first){
    struct node *ptr,*preptr;
    ptr=first;
    first=ptr->next;
    printf("The Deleted Element is : %d",ptr->data);
    free(ptr);
    return first;
}

struct node *peek(struct node * first){
    struct node *ptr;
    ptr=first;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    printf("the peek valuse is %d",ptr->data);

    return first;
}