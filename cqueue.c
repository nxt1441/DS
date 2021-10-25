#include<stdio.h>
#include<stdlib.h>

int a[3];
int size = 3;
int front = -1;
int rear = -1;
int data;
int i;


int enqueue(int data)
{
    if((rear == size - 1 && front == 0) || front == rear + 1)
    {
        printf("Overflow.....\n");
        return 0;
    }
    else if(front == -1)
    {
        front = 0;
    }
    else if(front != 0 && rear == size -1)
    {
        rear = 0;
       
    }
   
        rear = rear + 1;
        a[rear] = data;
   
         

}

int dqueue()
{
    if(front == -1)
    {
        printf("Underflow.....\n");
        return 0;
    }
    else if(front == rear)
    {
        printf("Removed %d......\n",a[front]);
        front = -1;
        rear = -1;
    }
    else if(front == size -1 && rear != 0)
    {
        printf("Removed %d......\n",a[front]);
        front = 0;
    }
    else
    {
         printf("Removed %d......\n",a[front]);
        front = front + 1;
    }
   
}


void display()
{
    i = front;
     if(front == -1)
    {
        printf("Underflow.....\n");
    }
    else if(rear >= front)
    {
        while(rear >= i)
        {
           printf(" %d ",a[i]); 
           i++;
        }
    }
    else
    {
        for(i= front; i<size;i++)
        {
            printf(" %d ",a[i]);
        }
         for(i=0;i<=rear;i++)
          {
            printf(" %d ",a[i]);
         }
        
       
    }
}


void main()
{
    int choice;
    while(1)
    {
        printf("\n1. Insert...\n");
        printf("2. Delete...\n");
        printf("3. Display...\n");
        printf("4. Exit...\n");
        printf("front %d \n",front);
        printf("rear %d \n",rear);
        printf("Enter Choice:");
        scanf("%d", &choice);
         switch(choice)
         {
             case 1: printf("Enter data:");
                     scanf("%d",&data);
                     enqueue(data);
                     break;
             case 2: dqueue();
                     break;
             case 3: display();
                     break;
             case 4: exit(0);
             default: printf("Invalid...\n");                                         
         }
    }
}