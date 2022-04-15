#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    int data;
    struct node *pre;
};

struct node *first=NULL;

struct node *create_list(struct node *first){
    struct node *p ,*ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter the Data : ");
    scanf("%d",&num);
    while(num!=-1){
        if (first==NULL){
            p = (struct node*)(malloc(sizeof(struct node)));
            p->pre=NULL;
            p->data=num;
            p->next=NULL;
            first=p;
        }
        else {
            ptr=first;
            p=(struct node*)(malloc(sizeof(struct node)));
            p->data=num;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next=p;
            p->pre=ptr;
            p->next=NULL;
        }
        printf("Enter the data: ");
        scanf("%d",&num);
    }
    return first;
}

struct node *display(struct node *first){
   struct node * ptr;
   ptr = first;
   while(ptr != NULL){
       printf("\t%d",ptr->data);
       ptr=ptr->next;
   }
   return first;
}

struct node *insertbeginning(struct node *first){
    struct node * ptr;
    ptr = (struct node *)(malloc(sizeof(struct node)));
    int value;
    printf("Enter the Element you want to insert in the beginning: ");
    scanf("%d",&value);
    ptr->data = value;
    ptr->pre = NULL;
    ptr->next = first;
    first->pre=ptr;
    first = ptr;
    return first;

}

struct node *insertend(struct node *first){
    struct node *p;
    p=(struct node*)(malloc(sizeof(struct node)));
    int value;
    printf("Enter the Element you want to insert in the beginning: ");
    scanf("%d",&value);
    p->data = value;
    struct node *ptr;
    ptr=first;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = p;
    p->pre = ptr;
    p->next = NULL;
    return first;

}

struct node *insertbefore(struct node *fisrt){
    struct node *p ,*ptr;
    p=(struct node*)(malloc(sizeof(struct node)));
    int value,bef;
    printf("Enter the data:");
    scanf("%d",&value);
    printf("Enter the element you want to insert brfore");
    scanf("%d",&bef);
    p->data = value;
    ptr=first;
    while(ptr->data != bef){
        ptr = ptr->next;
    }
    p->next = ptr;
    p->pre = ptr->pre;
    ptr->pre->next=p;
    ptr->pre = p;

    return first;
}

struct node *insertafter(struct node *first){
    struct node *p,*ptr;
    p=(struct node*)(malloc(sizeof(struct node)));
    int value,aft;
    printf("Enter the Data: ");
    scanf("%d",&value);
    printf("Enter the element you want to insert brfore");
    scanf("%d",&aft);
    p->data = aft;
    ptr=first;
    while(ptr->data!=aft){
        ptr = ptr->next;
    }
    p->pre = ptr;
    p->next = ptr->next;
    ptr->next->pre=p;
    ptr->next = p;
    return first;
}

struct node *delet_beg(struct node * first){
    struct node *ptr;
    ptr=first;
    first=first->next;
    first->pre=NULL;
    free(ptr);
    return first;
}

struct node *dele_end(struct node * first){
    struct node *ptr;
    ptr=first;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->pre->next=NULL;
    free(ptr);
    return first;
}

struct node *dele_bef(struct node * first){
    struct node *ptr , *temp;
    int val;
    printf("Enter the value before which the node has to delet:");
    scanf("%d",&val);

    ptr=first;
    while(ptr->data != val){
        ptr=ptr->next;
    }
    temp = ptr->pre;
    if(temp==first){
        first = delet_beg(first);
    }
    else{
        ptr->pre=temp->pre;
        temp->pre->next = ptr;
    }
    free(temp);
    return first;
}

struct node *dele_aft(struct node * first){
    struct node *ptr , *temp;
    int val;
    printf("Enter the value before which the node has to delet:");
    scanf("%d",&val);
    ptr=first;
    while(ptr->data != val){
        ptr=ptr->next;
    }
    temp = ptr->next;
    ptr->next=temp->next;
    temp->next->pre=ptr;
    free(temp);
    return first;
}

struct node * delet_list(struct node * first){
    while(first!=NULL){
        first = delet_beg(first);
    return first;
    }
}


int main(){
    int choice;
    do{
      printf("\n\n1.Create node.\n2.display linked list.\n3.Insert node in the beginning.\n4.Inserting node at the End.\n5.Inserting Before.\n6.Insertion After.\n");
      printf("7.Deleting node Beginning.\n8.Deleting node End.\n9.Deleting node Before.\n10.Deleting node After.\n11.Deleting the Entire Linked list.\n");
      printf("Enter the Chosen Number:");
      scanf("%d",&choice);
      switch(choice){
        case 1:

        first=create_list(first);
        printf("The circular Link list is Created:\n");
        break;
        
        case 2:
        printf("\n----------------display linked list------------------------\n");
        first=display(first);
        break;

        case 3:
        printf("\n--------------------Inserting node in the beginning----------------------\n");
        first = insertbeginning(first);
        
        break;

        case 4:
        printf("\n--------------------Inserting node at the end----------------------\n");
        first=insertend(first);
      
        break;

        case 5:
        printf("\n--------------------insertion before the node----------------------\n");
        first=insertbefore(first);
         break;

        case 6:
        printf("\n--------------------inserting after the node----------------------\n");
        first = insertafter(first);
        break;

        case 7:
        printf("\n--------------------deleting node at the beginning----------------------\n");
        first = delet_beg(first);
        break;

        case 8:
        printf("\n--------------------deleting node at the end----------------------\n");
        first = dele_end(first);
        break;

        case 9:
        printf("\n--------------------deleting node before the particular node----------------------\n");
        first = dele_bef(first);
        break;

        case 10:
        printf("\n--------------------deleting node after the particular node----------------------\n");
        first = dele_aft(first);
        break;

        case 11:
        printf("\n--------------------deleting complet linked list----------------------\n");
        first = delet_list(first);
        printf("the Doubly Linked list is completly deleted -----");
        break;

        default:
        printf("enter the worng Number");
      
       }
    }while(choice!=12);
    return 0;
}