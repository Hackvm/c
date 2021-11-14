#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void travers(struct node* ptr){
    while (ptr != NULL)
    {
    printf("the element data :%d\n",ptr->data);
    ptr = ptr->next;
    }
}

struct node * InsertBegi(struct node *first,int data){
    struct node * ptr;
    ptr=(struct node *)(malloc(sizeof(struct node)));
    ptr->next=first;
    ptr->data=data;
    return ptr;

}
struct node * insertend(struct node *first,int data){
    struct node* ptr;
    ptr = (struct node *)(malloc(sizeof(struct node)));
    ptr->data=data;
    struct node * p= first;
    while(p->next!=NULL){
        p= p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return first;
    
    }

struct node * insertbetween(struct node *first,int data,int index){
    struct node* ptr;
    ptr = (struct node *)(malloc(sizeof(struct node)));
    ptr->data=data;
    struct node *p=first;
    int i=0;
    while(i!=(index-1)){
        p = p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr; 
    return first;
}
void main (){
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    first->data=64;
    first->next=second;

    second->data=5;
    second->next=third;

    third->data=60;
    third->next=NULL;
    //first = InsertBegi(first,88);
    printf("------Insetion at END--------\n");
    first = insertend(first,98);
    travers(first);
    printf("--------------Insetion at Between-----------\n");
    first = insertbetween(first,880,2);
    travers(first);
    printf("------------Insertion at Begning----------\n");
    first = InsertBegi(first,100);
    travers(first);
    //linkedlisttraversal(fourth);
    //insertbetween(first,78,2);
}
