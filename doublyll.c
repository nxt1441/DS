#include<stdio.h>
#include<stdlib.h>

int value;
int pos;

struct node
{
    struct node *prev; 
    int data;
    struct node *next;
};

struct node *temp , *head, *newnode,*prev_node, *last;

void insertstart(int value)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
   

    if(head == NULL)
  {
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->data = value;
    head = newnode;
    
  }
  else
  {
      newnode->data = value;
      newnode->prev = NULL;
      newnode->next = head;
      head->prev = newnode;
      head = newnode;
  }
}


void insertend(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    temp = head;
     if(head == NULL)
        { 
            newnode->prev = NULL;
            newnode->next = NULL;
            newnode->data = value;
            head = newnode;
        }  
        else
        {
             while(temp->next != NULL)
                {
                    temp = temp -> next;
                }
            temp -> next = newnode;
            newnode->data = value;
            newnode->prev = temp;
            newnode->next = NULL;
            last = newnode;
        }
}
void deletespec()
{
    printf("Enter data/pos:");
    scanf("%d",&pos);
    temp = head;
    while(temp->data != pos)
    {
        temp = temp->next;
    }
    if(temp->next != NULL)
    {
        temp->prev->next = temp ->next;
        temp->next->prev = temp->prev;
        printf("Removed:%d \n",temp->data);
        free(temp);
    }
    else if(temp->prev == head)
    {
        temp->next->prev = head;
        printf("Removed: %d\n",temp->data);
    }
    else if(temp->next == NULL)
    {
        temp->prev->next = NULL;
        printf("Removed: %d",temp->data);
        free(temp);
    }
    else
    printf("Invalid Position \n");
}

void deleteEnd()
{
    temp = last;
    last = last->prev;
    last->next = NULL;
    printf("Removed:%d",temp->data);
    free(temp);
}

void display()
{
    temp = head;
    while(temp != NULL)
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
        printf("\n1. Insert start \n");
        printf("2. Insert End \n");
        printf("3. Delete Specific Node\n");
        printf("4. Delete Last Node \n");
        printf("5. Display\n");
        printf("6. Exit \n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter data:");
                    scanf("%d",&value);
                    insertstart(value);
                    break;
            case 2:
                    printf("Enter data:");
                    scanf("%d",&value);
                    insertend(value);
                    break;
            case 3: deletespec();
                    break;
            case 4: deleteEnd();
                    break;        
            case 5: display();
                    break;
            case 6: exit(0);
        }
    }
}