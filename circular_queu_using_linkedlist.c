#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};


struct node *first=NULL;
struct node * display();
struct node * create();
struct node * addtorear();
struct node * addtofront();
struct node * removefromrear();
struct node * removefromfront();
struct node * peek();
void main(){
    int choice;
    do{
    printf("\n1.Use to Create a Node.\n2.Use to Display Node.\n3.Use  to add in front.\n4.Use to add in raer.\n5.Use to remove from front.\n6.Use to remove from rear.\n7.use to see Peek Value.\n .\n");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:

        first = create(first);
        printf("\nThe Stack is Created\n");
        break;

        case 2:
        printf("\n-----------------------------Displaying Stack-------------------------------\n");
        first = display(first);
        break; 

        case 3:
        printf("\n------------------------------adding from front------------------------\n");
        first=addtofront(first);
        break;

        case 4:
        printf("\n-------------------------------adding from rear--------------------\n");
        first = addtorear(first);
        break;

        case 5:
        printf("\n--------------------------------removing from front-----------------\n");
        first=removefromfront(first);
        break;
        
        case 6:
        printf("\n-----------------------------------removing from rear-------------------\n");
        first=removefromrear(first);
        break;

        case 7:
        printf("\n---------------------------------Peek value in the deque--------------------\n");
        first = peek(first);
        break;

        default:
        printf("\n------------------Enter the wrong choice----------------------\n");
        }
    }while(choice!=8);
}

struct node * create(struct node *first){
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to stop linked list\n");
    printf("Enter the Data:");
    scanf("%d",&num);
    while (num!=-1){
        new_node= (struct node*)(malloc(sizeof(struct node)));
        new_node->data=num;

        if(first==NULL){
            new_node->next=new_node;
            first=new_node;
        }
        else{
            ptr=first;
            while(ptr->next!=first)
                ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=first;
            }
            printf("Enter the data:");
            scanf("%d",&num);
        }
        return first;

}

struct node * display(struct node * first){
    struct node *ptr;
    ptr=first;
    while(ptr->next!=first){
        printf("%d --> ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
    return first;
}

struct node * addtorear(struct node * first){//node inserting in the middle
    struct node *ptr,*p;
    int a;
    printf("Enter the Data:");
    scanf("%d",&a);
    ptr = (struct node *)(malloc(sizeof(struct node)));
    ptr->data=a;
    p=first;
    while(p->next!=first){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=first;
    return ptr;
}

struct node * addtofront(struct node * first){//node inserting at the end
    struct node *ptr,*new_node;
    int a;
    new_node = (struct node *)(malloc(sizeof(struct node)));
    printf("Enter the data:");
    scanf("%d",&a);
    new_node->data=a;
    ptr = first;
    while(ptr->next!=first){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next = first;
    return first;
}

struct node *removefromrear(struct node * first){//node deleting from beginning
    struct node *ptr;
    ptr=first;
    while(ptr->next!=first){
        ptr=ptr->next;
    }
    printf("\nThe Deleted Element from rear : %d\n",first->data);
    ptr->next=first->next;
    free(first);
    first=ptr->next;
    return first;
}

struct node *removefromfront(struct node * first){//deleting node from end
    struct node *ptr,*preptr;
    ptr=first;
    while(ptr->next!=first){
        preptr=ptr;
        ptr=ptr->next;
    }
    printf("\nThe Deleted Elemnt from front  : %d\n",ptr->data);
    preptr->next=ptr->next;
    free(ptr);
    return first;

}
struct node * peek(struct node * first){
    struct node *ptr;
    ptr=first;
    while(ptr->next!=first){
        ptr=ptr->next;
    }
    printf("\nThe peek valuse is %d\n",ptr->data);
    return first;
}