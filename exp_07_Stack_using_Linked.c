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

struct node * creat(struct node *first){
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to stop linked list\n");
    printf("Enter the Data:");
    scanf("%d",&num);
    while (num!=-1){
        new_node= (struct node*)(malloc(sizeof(struct node)));
        new_node->data=num;

        if(first==NULL){
            new_node->next=NULL;
            first=new_node;
        }
        else{
            ptr=first;
            while(ptr->next!=NULL)
                ptr=ptr->next;
                ptr->next=new_node;
                new_node->next=NULL;
            }
            printf("Enter the data:");
            scanf("%d",&num);
        }
        return first;

}

struct node * display(struct node * first){
    struct node *ptr;
    ptr=first;
    while(ptr->next!=NULL){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d",ptr->data);
    return first;
}

struct node * push(struct node * first){
    struct node *ptr,*p;
    int a;
    printf("Enter the Data:");
    scanf("%d",&a);
    p = (struct node *)(malloc(sizeof(struct node)));
    p->data=a;
    ptr=first;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next = p;
    p->next=NULL;
    return first;
}

struct node *pop(struct node * first){
    struct node *ptr,*preptr;
    ptr=first;
    first=ptr->next;
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
}