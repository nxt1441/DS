#include<stdio.h>
#include<stdlib.h>

int value;


struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *temp, *head;

void insertStart(int value)
{

  struct node* newnode = (struct node*) malloc(sizeof(struct node));

  newnode->data = value;
  newnode->next = head;
  head = newnode; 
}
void insertEnd(int value)
{
    temp  = head;
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
     while(temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next =  newnode;
    newnode->data = value;
    newnode->next = NULL;

}

void deleteb()
{
    temp = head;
    head = temp -> next;
    printf("Deleted %d\n" , temp->data);
    free(temp);
}

void deletee()
{
    temp = head;
    struct node *prev;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    printf("Deleted %d \n",temp->data);
    free(temp);
}

void display()
{
    temp = head;
    while(temp!=NULL)
    {
        printf(" %d ---> ", temp->data);
        temp = temp->next;
    }
}

void main()
{
    int choice;
     head = 0;
    while(1)
    {
        
        printf("1. Insert from end\n");
        printf("2. Insert from Start \n");
        printf("3. Delete from Start\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter value: ");
                    scanf("%d",&value);
                    insertEnd(value);
                    break;
            case 2: printf("Enter value: ");
                    scanf("%d",&value);
                    insertStart(value);
                    break;
            case 3: deleteb();
                    break;       
            case 4: deletee();
                    break;         
            case 5:  display();
                    break;
            case 6: exit(0);

        }
    }
}