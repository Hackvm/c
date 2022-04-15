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
    printf("\n1.To Usae Push.\n2.To Display Node.\n3.To use pop.\n4.To use peek.\n");
    printf("Enter Your Choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:

        printf("\n------------------------Push in stack-----------------------------------\n");
        first=push(first);
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
        printf("-------------------------------Peek node vaolue in stack--------------------\n");
        first = peek(first);
        break;

        default:
        printf("------------------Enter the wrong choice----------------------\n");
        }
    }while(choice!=5);
}

struct node * display(struct node * first){
    struct node *ptr;
    if(first==NULL){
        printf("Stack IS Empty\n");
    }

    else{
    ptr=first;
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    }
    //printf("\t%d",ptr->data);
    return first;
}

struct node * push(struct node * first){
    struct node *ptr;
    int a;
    ptr=(struct node *)(malloc(sizeof(struct node)));
    printf("Enter the Data:");
    scanf("%d",&a);
    ptr->data=a;
    if(first==NULL){
        ptr->next=NULL;
        first=ptr;
    }

    else{
        ptr->next=first;
        first=ptr;
    }
    return first;
}

struct node *pop(struct node * first){
    struct node *ptr,*preptr;
    if(first==NULL){
        printf("\nStack is Empty\n");
    }
    
    ptr=first;
    first=ptr->next;
    printf("\n The Value being deleted is %d",ptr->data);
    free(ptr);
    return first;
}

struct node *peek(struct node * first){
    struct node *ptr;
    if(first==NULL){
        printf("\n Stack is Empty");
    }
    else{
    printf("the peek valuse is %d",first->data);
    }
    return first;
}