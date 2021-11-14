#include <stdio.h>
#include <stdlib.h>
struct node{

    int data;
    struct node *next;
};
struct node *first=NULL;

struct node *insetrbig(struct node * first){
    struct node *ptr;
    int value;
    ptr = (struct node*)(malloc(sizeof(struct node)));
    printf("Enter the Value:");
    scanf("%d",&value);
    ptr->data=value;
    struct node *p=first;
    while (p->next!=first){
        p = p->next;
    }
    p->next=ptr;
    ptr->next=first;
    first=ptr;
return first;

}


struct node *insertend(struct node *first){
    struct node *ptr;
    int num;
    printf("Enter the data:");
    scanf("%d",&num);
    ptr=(struct node*)(malloc(sizeof(struct node)));
    ptr->data=num;
    struct node *p=first;
    while (p->next!=first){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=first;
    return first;
}

struct node *deletend(struct node *first){
    struct node *ptr;
    struct node *p=first;
    while(p->next!=first){
        ptr=p;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);

    return first;

}

struct node *deletbegin(struct node * first){
    struct node *p;
    p=first;
    while(p->next!=first){
        p=p->next;
    }
    p->next=first->next;
    free(first);
    first=p->next;

    return first;

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

struct node * display(struct node *first){
    struct node *ptr;
    ptr=first;
    while(ptr->next!=first){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\t",ptr->data);
    return first;
}

int main(){
    int choice;
    do{
      printf("\n\n1.Create node\n2.display linked list\n3.Insert node at begning\n4.insert node at end\n5.deleting node from beeginning\n6.delet node at end\n\n");
      printf("Enter the Chosen Number:");
      scanf("%d",&choice);
      switch(choice){
        case 1:

        first=creat(first);
        printf("The circular Link list is Created:\n");
        break;
        
        case 2:
        printf("\n----------------display linked list------------------------\n");
        first=display(first);
        break;

        case 3:
        printf("\n--------------------Inserting node in the beginning----------------------\n");
        first=insetrbig(first);
        
        break;

        case 4:
        printf("\n--------------------Inserting node at the end----------------------\n");
        first=insertend(first);
      
        break;

        case 5:
        printf("\n--------------------deleting node in the beginning----------------------\n");
        first=deletbegin(first);
         break;

        case 6:
        printf("\n--------------------deleting node at the end----------------------\n");
        first = deletend(first);
        break;
        default:
        printf("enter the worng Number");
      
       }
    }while(choice!=7);
    return 0;
}
