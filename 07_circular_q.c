#include<stdio.h>
#include<stdlib.h>

#define maxsize 5

int ciQ[maxsize];
int front=-1;
int rear=-1;

void enQ()
{
	if(top==maxsize-1)
	{
		printf("\nstack overflow");
	}
	else
	{
		int item;
		printf("\nenter the item to be inserted ");
		scanf("%d",&item);
		top++;
		stack[top]=item;
		printf("\nthe item inserted is %d",stack[top]);
	}
}
void deQ ()
{
	if(front==-1)
	{
		printf("\nstack is underflow");
	}
	else
	{
		int item;
		item=stack[top];
		top--;
		printf("\nthe item deleted is %d",item);
	}
}

void display()
{
	printf("\nelements are:");
	for(int i=front;i>rear;i--)
	{
		printf("\n%d",ciQ[i]);
		
	}
}	
void search()
{
	int item,flag=0;
	printf("\nenter the element to be searched");
	scanf("%d",&item);
	for(int i=front;i>rear;i--)
	{
		if(ciQ[i]==item)
		{
			printf("\n%d found in the stack",item);
			flag++;
			break;
		}
	}
	if(flag==0)
	{
		printf("\n %d not found",item);
	}
}

int main()
{
	int choice;
	do
	{
	printf("\nenter the choice");
	printf("\n1:insert element \n1: enqueue \n2:dequeue element \n3:display \n4:search \n5:exit");
	
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :enQ();
			break;
			
		case 2 :deQ();
			break;
			
		case 3 :display();
			break;
			
		case 4: search();
			break;
			
		case 5 : exit(0);
		
		default :printf("\ninvalid entry");
	}
	
	}while(choice!=5);
	return 0;
}	
	
	
