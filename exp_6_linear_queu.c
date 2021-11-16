#include<stdio.h>
#define MAX 10

int queue[MAX], front=-1,rear=-1;
void insert (void);
int delet_element(void);
void display(void);
int peek(void);


void main(){
    int data,chosen;
    do{
        printf("\n----------------------------------The Main Menu -----------------------------------");
        printf("\n1.Insert an element.\n2.Delete an element.\n3.PEEK\n4.Display the queue.\n5.Exit");
        printf("\nEnter the Chossen Number:");
        scanf("%d",&chosen);
        switch(chosen){
            case 1:
            insert();
            break;

            case 2:
            data =delet_element();
            if(data != -1){
                printf("\n The Number deleted is : %d",data);
            }
            break;

            case 3:
            data = peek();
            if(data!=-1){
                printf("\n The first value in queue is : %d", data);
            }
            break;

            case 4:
            display();
            break;

            default:
            printf("You Enter the Wrong Number");

        }
    }while(chosen!=5);
}


void insert(){
    int data;
    if (rear==MAX-1){
        printf("\n Stack OverFlow");
    }

    else if(front==-1 && rear == -1){
        front=rear=0;
    }
    else{
        rear++;
        printf("\n\tEnter the data you want to push in stack:");
        scanf("%d",&data);
        queue[rear]=data;
    }
}

int delet_element(){
    int data;
    if(front==-1 || front>rear){
        printf("\n Stack UnderFlow");
        return -1;
    }
    else{
        data = queue[front];
        front++;
        if(front>rear){
            front = rear = -1;
            return data;
        }
    }
}


void display(){
    int i=0;
    if(front == -1 || front>rear){
        printf("\n Stack Underflow");
    }
    else{
        for(i=front;i=>rear;i++){
            printf("\t%d",queue[i]);
        }

    }
}


int peek(){
    //int data;
    if(front==-1 || front>rear){
        printf("\n Stack Overflow");
        return -1;
    }

    else{
        return queue[front];
        //data = str[top];
       // printf("\n  The last element in the stack : %d",data); 
    }
}