#include <stdio.h>
#define max 10
int queue[max], front = max / 2, rear = max / 2 ;
int q_isEMPTY();
int q_isFULL();
int insert_left(int);
int insert_right(int);
int delete_left();
int delete_right();
int display(); 
void main()
{
    int choice, a = 1;
    while (a = 1)
    {
        printf("\nEnter a number\n1]Insert at Left\n2]Insert at Right\n3]Delete at left\n4]Delete at right\n5]Display\n6]Exit\nYour Choice: ");
        scanf("%d", &choice);
        if (choice == 6)
        {
            break;
        }
        switch (choice)
        {
        case 1:         //insert an element from left
        {
            int x;
            printf("\nEnter the element: \n");
            scanf("%d", &x);
            insert_left(x);
        }
        break;
        case 2:        //insert an element from right
        {
            int x;
            printf("\nEnter the element: \n");
            scanf("%d", &x);
            insert_right(x);
        }
        break;
        case 3:       //delete an element from left
        {
            delete_left();
        }
        break;
        case 4:      //delete an elemnet from right
        {
            delete_right();
        }
        break;
        case 5:
        {
            printf("\nThe Queue is :\n");
            display();
        }
        break;
        default:
        {
            printf("\nBye Bye!");
        }
        }
    }
}
int q_isEMPTY()
{
    if (front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int q_isFULL()
{
    if (front == -1 || rear == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int display()
{
    if (q_isEMPTY())
    {
        printf("The Queue is Empty.");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
        return 1;
    }
}
int insert_left(int x)
{
    if (front == -1)
    {
        printf("\n...Queue overflow...");
        return -1;
    }
    else
    {
        front = front - 1;
        queue[front] = x;
        return x;
    }
}
int insert_right(int x)
{
    if (front == max - 1)
    {
        printf("\n...Queue overflow...");
        return -1;
    }
    else
    {
        rear = rear + 1;
        queue[rear] = x;
        return x;
    }
}
int delete_left()
{
    int x;
    if (q_isEMPTY())
    {
        printf("\n...Queue Underflow...");
        return -1;
    }
    else
    {
        front = front + 1;
        x = queue[front];
        return x;
    }
}
int delete_right()
{
    if (q_isEMPTY())
    {
        printf("\n...Queue Underflow...");
        return -1;
    }
    else
    {
        int x;
        rear = rear - 1 ;
        x = queue[rear];
        return x;
    }
}