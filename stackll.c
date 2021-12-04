#include<stdio.h>
#include<stdlib.h>

int value;

struct node 
{
    int data;
    struct node *top;
};

struct node *temp, *head, * newnode;

void push(int value)
{
    temp  = head;
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
      if(head == NULL)
    {
        newnode->data = value;
        newnode->top = head;
        head = newnode;
    }
   else
   {
        while(temp->top != NULL)
        {
            temp = temp -> top;
        }
        temp -> top =  newnode;
        newnode->data = value;
        newnode->top = NULL;
   }
}

void pop()
{
    temp = head;
    struct node *prev;
    while(temp->top != NULL)
    {
        prev = temp;
        temp = temp -> top;
    }
    prev -> top = NULL;
    printf("Deleted %d \n",temp->data);
    free(temp);
}

void display()
{
     temp = head;
    while(temp!=NULL)
    {
        printf(" %d ---> ", temp->data);
        temp = temp->top;
    }
}


void main()
{
    int choice;
    while(1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter Data:");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2:pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);                
        }
    }
}