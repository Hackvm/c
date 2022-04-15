#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node * left;
    int data;
    struct node * right;
};
struct node *first=NULL;
void inordertraversal(struct node *first);
void preordertraversal(struct node *first);
void postordertraversal(struct node *first);
struct node *insertelement(struct node *first,int Data);
struct node *largestnode(struct node *first);
struct node *findsmallestnode(struct node *first);



int main(){
    int choice,Data;
    struct node *ptr;
    do{
      printf("\n\n1.Insertelement\n2.InorderTraversal\n3.PreorderTraversal\n4.PostorderTraversal.\n5.Find the samllest Element.\n6.Find the largest Elemant\n");
      printf("Enter the Chosen Number:");
      scanf("%d",&choice);
      switch(choice){  
        case 1:
        printf("Enter the Data:");
        scanf("%d",&Data);
        first=insertelement(first,Data);
        printf("\n------------The element is inserted in tree----------------\n");
        //printf("The circular Link list is Created:\n");
        break;
        
        case 2:
        printf("\n----------------Displaying through inoreder traversal ------------------------\n");
        inordertraversal(first);
        break;

        case 3:
        printf("\n--------------------Displaying through preorder traversal----------------------\n");
        preordertraversal(first);
        
        break;

        case 4:
        printf("\n--------------------dISPLAYING node throug postordertraversal----------------------\n");
        postordertraversal(first);      
        break;

        case 5:
        printf("\n---------------------Smallest Number Found--------------------------\n");
        ptr=findsmallestnode(first);
        printf("%d",ptr->data);
        break;
        case 6:
        printf("\n----------------------Largest Number Found---------------------------\n");
        ptr=largestnode(first);
        printf("%d",ptr->data);
        break;

        default:
        printf("enter the worng Number");
      
       }
    }while(choice!=7);
    return 0;
}

struct node *insertelement(struct node *first,int Data){
    struct node *ptr,*rootnode,*nodeptr;
    ptr=(struct node *)(malloc(sizeof(struct node)));
    ptr->data=Data;
    ptr->left=NULL;
    ptr->right=NULL;
    if(first==NULL){
        first=ptr;
        ptr->left=NULL;
        ptr->right=NULL;

    }

    else{
        rootnode=NULL;
        nodeptr=first;
        while(nodeptr!=NULL){
            rootnode=nodeptr;
            if(Data < rootnode->data){
                nodeptr = nodeptr->left;
            }
            else{
                nodeptr=nodeptr->right;
            }
        }
        if(Data<rootnode->data){
            rootnode->left=ptr;
        }
        else{
            rootnode->right=ptr;
        }
    }
    return first;
}

void preordertraversal(struct node *first){
    if(first!=NULL){
        printf("%d\t",first->data);
        preordertraversal(first->left);
        preordertraversal(first->right);
    }
}

void inordertraversal(struct node *first){
    if(first!=NULL){
        inordertraversal(first->left);
        printf("%d\t",first->data);
        inordertraversal(first->right);
    }
}

void postordertraversal(struct node *first){
    if(first!=NULL){
        postordertraversal(first->left);
        postordertraversal(first->right);
        printf("%d\t",first->data);
    }
}

struct node *findsmallestnode(struct node *first){
    if(first==NULL || first->left==NULL){
        return first;
    }
    else{
        return findsmallestnode(first->left);
    }
}

struct node *largestnode(struct node *first){
    if(first==NULL || first->right==NULL){
        return first;
    }

    else{
        return largestnode(first->right);
    }
}


//20 10 90 5 45 30
//in 5       10      20      30      45      90
//pre 20      10      5       90      45      30
//po 5       10      30      45      90      20