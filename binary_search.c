#include<stdio.h>
#include<stdlib.h>


int a[5];
int n = 5;
int i,j;
int temp;
int first;
int last;
int mid;
int data;  

void insert()
{
	
	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]: ",i);
		scanf("%d",&a[i]);
	}

}



void sort()
{
	for(i=0;i<n;i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("Data is sorted...\n");
	for(i=0; i<n; i++)
	{
		printf(" %d ",a[i]);
	}
}



int search(int data)
{
	first = 0;
	last = n - 1;
	mid = (first + last) / 2;
	
		while(first <= last)
		{
			if(a[mid] < data)
			{
				first = mid + 1;
			}	
			else if(a[mid] == data)
			{
				printf("Found at index %d ", mid);
				return 0;	
			}
			else if(a[mid] > data)
			{
				last = mid - 1;
			}
			mid = (first + last)/2;
		}	
		if (first > last)
			printf("Not found! %d .\n", data);
			return 0;

}






void main()
{
	
	int choice;
	while(1)
	{
		printf("\n1. Insert \n");
		printf("2. Sort \n");
		printf("3. serach \n");
		printf("4. exit \n");

		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert();
					break;
			case 2: sort();
					break;
			case 3: printf("Enter data to search:");
					scanf("%d",&data);
					search(data);
					break;
			case  4: exit(0);
			default: printf("invalid  \n");		
		}

	}
}

