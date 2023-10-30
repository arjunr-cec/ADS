#include<stdio.h>
#include<stdlib.h>

#define maxsize 50

int stack[maxsize];
int top=-1;

void push()
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
void pop()
{
	if(top==-1)
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
	for(int i=top;i>-1;i--)
	{
		printf("\n%d",stack[i]);
		
	}
}	
void search()
{
	int item,flag=0;
	printf("\nenter the element to be searched");
	scanf("%d",&item);
	for(int i=top;i>-1;i--)
	{
		if(stack[i]==item)
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
	printf("\n1:insert element \n2:delete element \n3:display \n4:search \n5:exit");
	printf("\nenter the choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :push();
			break;
			
		case 2 :pop();
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
	
	
