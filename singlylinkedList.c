#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node* next;
};
struct node* head;

void inFirst()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    printf("\nInserted Element is: %d",newnode->data);
}

void inLast()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {   
        temp = head;
        while (temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next=newnode;
    }
    printf("\nInserted Element is: %d",newnode->data);
}

void inPos()
{
    int pos=0,i=1;
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("\nEnter the position:");
    scanf("%d",&pos); 
    temp = head;
    while (i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;  
    printf("\nInserted Element is: %d",newnode->data);
}

void disp()
{
    struct node *temp;
    temp=head;
    printf("\nElements is");

    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }

}

void delFirst()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nNO ELEMENTS");
    }
    else
    {
        temp = head;
        head= head->next;
    }
    printf("\nDELETED Element is: %d",temp->data);
    free(temp);
}

void delLast()
{
    struct node *temp, *prevnode;
    if(head==NULL)
    {
        printf("\nNO ELEMENTS");
    }
    else
    {
        temp = head;
        while(temp->next!=NULL)
        {
            prevnode=temp;
            temp=temp->next;
        }
        prevnode->next=NULL;
    }
    printf("\nDELETED Element is: %d",temp->data);
    free(temp);
}

void delPos()
{
    int i=1,pos=0;
    struct node *temp, *nextnode;
    printf("\nEnter the position:");
    scanf("%d",&pos); 
    temp=head;
    if(pos==1)
    {
        delFirst();
    }
    else
    {
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        printf("\nDELETED Element is: %d",nextnode->data);
        free(nextnode);
    }

}

int main()
{
    int choice;
    printf("Linked List:\n\n");

    do
    {
        printf("ENTER YOUR OPTION:\n1.insertFirst\n2.insertLast\n3.insertPos\n4.delfirst\n5.delLast\n6.delPOS\n7.display\n8.Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: inFirst();
                    break;
            case 2: inLast();
                    break;
            case 3: inPos();
                    break;
            case 4: delFirst();
                    break;
            case 5: delLast();
                    break;
            case 6: delPos();
                    break;
            case 7: disp();
                    break;
            case 8: exit(0);

            default: printf("WRONG INPUT!! TRY AGAIN!!");
        }
    }while(choice!=8);

    return 0;
}