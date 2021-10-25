#include<stdio.h>
#include<stdlib.h>

int a[4];
int size = 4;
int front;
int rear;
int data;
int i;


int insert_front(int data)
{
    if(front == 0 || front == rear + 1)
    {
        printf("Queue is  full.....\n");
        return 0;
    }
    front = front - 1;
    a[front] = data;
}



int insert_rear(int data)
{
    if(rear == size -1 || front == rear + 1 )
    {
        printf("Queue is full....  \n");
        return 0;
    }

    rear = rear + 1;
    a[rear] = data;
}


int delete_front()
{
    if(front == size || rear == -1 )
    {
        printf("Queue is empty.....\n");
        return 0;
    }
     printf("Removed %d....\n",a[front]);
     front  = front + 1;

}


int delete_rear()
{
     if(front == size || rear == -1 )
    {
        printf("Queue is empty.....\n");
        return 0;
    }
     printf("Removed %d....\n",a[rear]);
     rear = rear - 1;
}


void display()
{
     if(front == size || rear == -1 )
    {
        printf("Queue is empty.....\n");
    }
    else
    {
        for(i=0;i<=rear;i++)
        {
            printf(" %d ",a[i]);
        }
        for(i=front;i<size;i++)
        {
            printf(" %d ",a[i]);
        }
    }
}




void main()
{
    int choice;
    front = size;
    rear = -1;
   
    while(1)
    {
        printf("\n1. Insert from back\n");
        printf("2. Insert from front\n");
        printf("3. Delete from front\n");
        printf("4. Delete from back\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Front %d \n Rear %d \n",front , rear);
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                insert_front(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d",&data);
                insert_rear(data);
                break;   
            case 3:
                delete_rear();
                break;
            case 4: 
                delete_front();
                break;
            case 5:
                display();
                break;
            case 6: exit(0);
            default: printf("Invalid choice.....\n");    
        }
    }
}