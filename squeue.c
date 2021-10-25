#include<stdio.h>
#include<stdlib.h>

int a[3];
int size = 3;
int front = -1;
int rear = -1;
int data;


int insert(int data)
{
    if(rear == size - 1)
    {
        printf("overflow.....\n");
        return 0;
    }
    else if(front ==  -1)
    {
        front = 0;
    }
    rear = rear + 1;
    a[rear] = data;

}

int delete()
{
    if(rear == -1 && front == -1 )
    {
        printf("underflow....\n");
        return 0;
    }
    else if(front  == rear )
    {
        printf("Removed %d .... \n",a[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Removed %d....\n",a[front]);
        front = front + 1;   
    }
}

void display()
{
    int i;
    for(i = front; i<=rear;i++ )
    {
        printf(" %d ", a[i]);
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
        printf("Enter Choice:");
        scanf("%d", &choice);
         switch(choice)
         {
             case 1: printf("Enter data:");
                     scanf("%d",&data);
                     insert(data);
                     break;
             case 2: delete();
                     break;
             case 3: display();
                     break;
             case 4: exit(0);
             default: printf("Invalid...\n");                                         
         }
    }
}



