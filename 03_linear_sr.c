#include<stdio.h>
int main()
{
	int a[10],n,i,item,flag=0;
	printf("enter the limit of array:");
	scanf("%d",&n);
	printf("\n enter the array elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\n enter the elements to be sreach");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
	if(a[i]==item)
	{	
		printf("%d  found at position  %d",item,i+1);
		flag++;
		break;
	}
	}
	if(flag==0)
		printf("\n%d not found in the array",item);
	return 0;
}
