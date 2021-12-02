#include<stdio.h>
#include<stdlib.h>

int value;
int flag;


struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *temp, *head;

void insertStart(int value)
{

  struct node* newnode = (struct node*) malloc(sizeof(struct node));
  if(head == NULL)
  {
      head = newnode; 
      newnode->data = value;
      newnode->next = head;
  }
  else
  {
       temp = head;  
            while(temp->next != head) 
            {
                 temp = temp->next;  
            } 
     
            newnode->next = head;   
            temp -> next = newnode;
            newnode->data = value;  
            head = newnode;
  }
 
}
void insertEnd(int value)
{
    temp = head;
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    
     if(head == NULL)
        { 
            head = newnode;
            newnode->data = value;
            newnode->next = head;
        }  
        else
        {
             while(temp->next != head)
                {
                    temp = temp -> next;
                }
            temp -> next =  newnode;
            newnode->data = value;
            newnode->next = head;
        }

}

void insertafter(int value)
{
    flag = 0;
    int x;
    printf("Enter value to insert after: ");
    scanf("%d",&x);
    struct node *newnode = (struct node*) malloc(sizeof(struct node));

    temp = head;
    while(temp->next != head)
    {
       
            if(temp->data == x)
            {
               
                newnode->data = value;
                newnode -> next = temp->next;
                temp -> next = newnode;
            }
            else
            {
               temp = temp -> next;
            }
      
    }
}

void deleteb()
{
  if(head->next == head)
  {
      head = NULL;
      free(head);
      printf("Node Deleted...\n");
  }
  else
  {
      temp = head;
      while(temp->next != head)
      {
          temp = temp->next;
      }
      temp -> next = head -> next;
      printf("Node Deleted \n",head->data);
      free(head);
      head = temp->next;

  }
}

void deletee()
{
    if(head->next == head)
    {
        head = NULL;
        free(head);
        printf("Node Deleted...\n");
    }
    else
    {
        temp = head;
        struct node *prev;
        while(temp->next != head)
        {
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = temp->next;
        printf("Deleted %d \n",temp->data);
        free(temp);
    }
}

void display()
{
    temp = head;
    while(temp -> next != head)
    {
        printf(" %d ---> ", temp->data);
        temp = temp->next;
    }
    printf(" %d --->",temp->data);
}

void main()
{
    int choice;
     head = 0;
    while(1)
    {
        
        printf("\n1. Insert from end\n");
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