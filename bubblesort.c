#include<stdio.h>
#include<stdlib.h>

int a[5] ;
int i,j;
int temp;
int n = 5;

void insert()
{
    printf("Enter Elements to sort: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
       
    }
}


void sorta()
{
    printf("\nUnsorted data:");
     for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
        }
    }

    printf("\nData Sorted:");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
}

void sortd()
{
     printf("\nUnsorted data:");
     for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
        }
    }

   
    printf("\nData Sorted:");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
}

void main()
{
    int choice;
    

    while(1)
    {
        printf("\n1. Insert\n");
        printf("2. Sort (Asscending)\n");
        printf("3. Sort (Descending)\n");
        printf("4. EXit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: sorta();
                    break;
            case 3: sortd();
                    break;
            case 4: exit(0);
            default: printf("Enter valid input\n");        
        }
    }

}