#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
struct node *first=NULL;



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
struct node * display(struct node *first){
    struct node *ptr;
    ptr=first;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    return first;
}
struct node * InsertBegi(struct node *first){
    struct node * ptr;
    int a;
    printf("Enter the Data:");
    scanf("%d",&a);
    ptr=(struct node *)(malloc(sizeof(struct node)));
    ptr->next=first;
    ptr->data=a;
    return ptr;

}

struct node * insertend(struct node *first){
    struct node* ptr;
    int a;
    printf("Enter the Data:");
    scanf("%d",&a);
    ptr = (struct node *)(malloc(sizeof(struct node)));
    ptr->data=a;
    struct node * p= first;
    while(p->next!=NULL){
        p= p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return first;
    
    }

    struct node * insertbetween(struct node *first){
    struct node* ptr;
    int a,index;
    printf("Enter the Data:");
    scanf("%d",&a);
    printf("Enter the Data:");
    scanf("%d",&index);
    ptr = (struct node *)(malloc(sizeof(struct node)));
    ptr->data=a;
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

  struct node * deletend(struct node *first){
          struct node *ptr,*pp;
          ptr=first;
          while (ptr->next!=NULL){
              pp=ptr;
              ptr=ptr->next;
              
          }
          pp->next=NULL;
          free(ptr);
        return first;
  }
   
   struct node *deletbing(struct node *first){
        struct node *ptr;
            ptr=first;
            first=first->next;
            free(ptr);
            return first;
}



int main(){
    int choice;
    do{
      printf("\n\n1.Create node\n2.display linked list\n3.Insert node at begning\n4.insert node at end\n5.Insret node at between\n6.deleting node at end\n7.delet from beginning\n\n");
      printf("Enter the Chosen Number:");
      scanf("%d",&choice);
      switch(choice){
        case 1:

        first=creat(first);
        printf("The Link is Created:\n");
        break;
        
        case 2:
        printf("\n----------------display linked list------------------------\n");
        first=display(first);
        break;

        case 3:
        printf("\n--------------------Inserting node in the beginning----------------------\n");
        first=InsertBegi(first);
        
        break;

        case 4:
        printf("\n--------------------Inserting node at the end----------------------\n");
        first=insertend(first);
        
        break;

        case 5:
        printf("\n--------------------Inserting node in between two nodes----------------------\n");
       first=insertbetween(first);
      
        break;

        case 6:
        printf("\n--------------------deleting node at the end----------------------\n");
        deletend(first);
        break;

        case 7:
        printf("\n--------------------deleting node in the beginning----------------------\n");
        first=deletbing(first);

        default:
        printf("enter the worng Number");
      
       }
    }while(choice!=8);
    return 0;
}
