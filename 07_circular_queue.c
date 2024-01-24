#include<stdio.h>
#include<stdlib.h>
	
#define MAX_SIZE 5

int CQUE[MAX_SIZE];
int FRONT=-1;
int REAR=-1;

void enQ()
{
	if((FRONT == 0 && REAR == MAX_SIZE-1 ) || (REAR + 1 == FRONT ))
	{
		printf("\n QUEUE IS FULL");
	}
	else
	{	
		if(FRONT==-1)
		{
			FRONT = 0;
		}
		int item;
		printf("\n ENTER THE ITEM TO BE ADDED TO THE QUEUE:");
		scanf("%d",&item);
		REAR = (REAR+1)%MAX_SIZE;
		CQUE[REAR] = item;
		printf("\n %d  ADDED TO THE QUEUE\n\n",item);
		
	}
}

void deQ()
{
	if(FRONT == -1)
	{
		printf("\n QUEUE IS EMPTY");
	}
	else
	{	
		int item = CQUE[FRONT];
		if(FRONT==REAR)
		{
			FRONT = REAR = -1;
		}
		FRONT = (FRONT+1)%MAX_SIZE;
		printf("\n %d  DELETED FROM THE QUEUE\n\n",item);
		
	}
}


void dispQ() {
    if (FRONT == -1) {
        printf("\n QUEUE IS EMPTY\n");
    }
    else
    {
    int i = FRONT;
    printf("CIRCULAR QUEUE: ");
    do {
        printf("%d ", CQUE[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (REAR + 1) % MAX_SIZE);
    printf("\n");
    }
}

void seaQ()
{	
	int se,flag=0;
	printf("\n ENTER THE  ELEMENT TO BE SEARCHED:");
	scanf("%d",&se);
	int i = FRONT;
    	do {
        if (CQUE[i] == se) {
            printf(" %d FOUND IN THE CIRCULAR QUEUE\n\n", se);
            flag++;
            break;
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != (REAR + 1) % MAX_SIZE);
	if(flag==0)
	{
		printf(" %d NOT FOUND  IN THE CIRCULAR QUEUE\n\n ",se);
	}
}


int main()
{
	int choice;
	do
	{
	printf("\n\nCIRCULAR QUEUE USING ARRAY\nCHOOSE YOUR OPTION:");
	printf("\n'1' FOR ENQUEUE \n'2' FOR DEQUEUE \n'3' FOR DISPLAY \n'4' FOR SEARCHING \n'5' FOR EXIT");  
	scanf("%d",&choice);

		switch (choice)
		{
			case 1: enQ();
				break;
				
			case 2: deQ();
				break;
				
			case 3: dispQ();
				break;
				
			case 4: seaQ();
				break;
				
			case 5: exit(0);
				

    			default: printf("\n INVALID INPUT\n TRY AGAIN!!");
    				break;
    		}
    	}while(choice!=5);
    return 0;
}

