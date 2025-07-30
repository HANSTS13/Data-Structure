#include<stdio.h>
int array[20],front=-1,rear=-1;
void enqueue(int n,int s)
{
	if(front==-1&& rear==-1)
	{
		front++;
		rear++;
		array[rear]=n;
		printf("Elements in the array:\n");
		for(int i=front;i<=rear;i++)
			printf("\n%d",array[i]);
	}
	else if (rear==s-1)
		printf("Overflow");
	else
	{
		rear++;
		array[rear]=n;
		printf("Elements in the array:\n");
		for(int i=front;i<=rear;i++)
			printf("\n%d",array[i]);
	}
}
void dequeue()
{
	if(front>rear)
	{
		printf("\nUnderflow");
		front=-1;
		rear=-1;
	}
	else if(front==-1&& rear==-1)
		printf("\nUnderflow");
	else
	{
		printf("\nDeleted element: %d",array[front]);
		front++;
		printf("\nElements in the array:\n");
		for(int i=front;i<=rear;i++)
			printf("\n%d",array[i]);
	}
}		
void main()
{
	int size,decision1=1,decision2;
	printf("Enter maximum size of array");
	scanf("%d",&size);
	while(decision1==1)
	{
		printf("\nEnter 1 for enqueue and 2 for dequeue");
		scanf("%d",&decision2);
		int num;
		if(decision2==1)
		{
			printf("\nEnter the number to insert in the array");
			scanf("%d",&num);
			enqueue(num,size);
		}
		else
		{
			dequeue();
		}
	printf("\nDo you want to continue:Enter 1 for Yes and 2 for No");
	scanf("%d",&decision1);
	}	
}
