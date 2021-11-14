/**************** stack usinf linked list **************/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *push(struct node *top,int ele);
struct node *pop(struct node *top);
struct node *display(struct node *top);
//struct node *create(struct node *top);

int main()
{
	 struct node * head=NULL;//intializing empty stack
	int i,ele,ch;
	

while(ch!=4)
{
	printf("\n1:Push");
	printf("\n2:Pop");
	printf("\n3:Display Stack");
	printf("\n4:Exit:");
	printf("\n Select you choice \n->");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			printf("Enter element to be insert:");
			scanf("%d",&ele);
			head=push(head,ele);
			break;
		case 2:
			head=pop(head);
			break;
		case 3:
			head=display(head);
			break;
		case 4:
			return 4;
			break;
		default:
			printf("Enter correct choice..!");
	}
}
return 0;
}

/****************** functions *********************/

struct node *push(struct node *top, int ele)
{
	struct node *temp,*ptr;
	temp=(struct node*)(malloc(sizeof (struct node)));
	//temp->data=ele;
	if(top==NULL){
	   printf("overflow");
		}
	else{
	temp->data=ele;
	temp->next=top;
	top->next=NULL;
	}
	return temp;
}
struct node * pop(struct node *top)
{
	struct node *temp;
	int item;
	if(top==NULL)
	{
		printf("overflow..!");
		//return NULL;
	}
	temp=top;
	item=temp->data;
	printf("Deleted Element:%d",item);
	top=temp->next;
	free(temp);
	return top;
}

struct node * display(struct node *top)
{
   struct node *temp;
    //int a;
// 	while(temp!=NULL)
// 	{
// 		printf("->%d",temp->data);
// 		temp=temp->next;
//	 }
   
   //if(top==NULL)
   
   //{
	//printf("Enter the data for first element:");
	//scanf("%d",&a);
	 //temp->data=a;
     //temp->next = NULL;

	//}
	//else{
	//temp=top;
   
   while(temp->next!=NULL)
   {
   	printf("%d->",temp->data);
   	temp=temp->next;
	}
	 return top;
}










