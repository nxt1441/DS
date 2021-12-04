#include<stdio.h>
#include<stdlib.h>

int value;

struct node
{
    int data;
    struct node* next;
};
 struct node *front, *rear, *newnode, *temp;



void insert(int value)
{
    temp  = front;
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
      if(front == NULL)
    {
        newnode->data = value;
        newnode->next = front;
        front = newnode;
    }
   else
   {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next =  newnode;
        newnode->data = value;
        newnode->next = NULL;
        newnode = rear;
   }
}

void delete()
{
    temp = front;
    front = temp -> next;
    printf("Deleted %d\n" , temp->data);
    free(temp);
}

void display()
{
      temp = front;
    while(temp != rear)
    {
        printf(" %d ---> ", temp->data);
        temp = temp->next;
    }
}


void main()
{
    int choice;
    while(1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter Data:");
                    scanf("%d",&value);
                    insert(value);
                    break;
            case 2:delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);                
        }
    }
}