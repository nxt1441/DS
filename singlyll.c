#include<stdio.h>
#include<stdlib.h>

int value;
int pos;


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
      if(head == NULL)
    {
        newnode->data = value;
        newnode->next = head;
        head = newnode;
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
   }
    

}


int insertacc(int value)
{
    temp  = head;
 
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    if(head == NULL)
    {
        newnode->data = value;
        newnode->next = head;
        head = newnode;
   }
   else
   {
       while(temp->next != NULL)
        {
        if(temp->data <= value)
        {
                newnode->next = temp->next;
                temp->next = newnode;
                newnode->data = value;
                return 0;
        }
        else if(temp->next == NULL)
        {
                temp -> next =  newnode;
                newnode->data = value;
                newnode->next = NULL;
                return 0;
        }
        else
        {
                temp = temp -> next;
        }
        }
   }
     
}

void deleteb()
{
    temp = head;
    head = temp -> next;
    printf("Deleted %d\n" , temp->data);
    free(temp);
}

int deletee()
{
    temp = head;
    struct node *prev;
    printf("Enter position/data:");
    scanf("%d",&pos);
    while(temp->next != NULL)
    {
        if(temp->data == pos)
        {
            prev = temp;
            prev -> next = temp->next;
            printf("Deleted %d \n",prev->data);
            free(prev);
            return 0;
        }
        else
        {
            temp = temp->next;
        }
    }
    
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
        
        printf("\n1. Insert from end\n");
        printf("2. Insert from Start \n");
        printf("3. Insert in ascending order (according to data)\n");
        printf("4. Delete from Start\n");
        printf("5. Delete from End\n");
        printf("6. Display\n");
        printf("7. Exit\n");
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
            case 3: printf("Enter value: ");
                    scanf("%d",&value);
                    insertacc(value);
                    break;       
            case 4: deleteb();
                    break;         
            case 5:  deletee();
                    break;
            case 6: display();
                    break;
            case 7: exit(0);

        }
    }
}