#include<stdio.h>
int main()
{
	int a1[50],a2[50],merge[100];
	int m,n,i=0,j=0,k=0;
	printf("enter the limit of both array:");
	scanf("%d%d",&m,&n);
	printf("\n enter the elements of 1st array:");
	for(i=0;i<m;i++)
	scanf("%d",&a1[i]);
	printf("\n enter the elements of 2nd array:");
	for(j=0;j<n;j++)
	scanf("%d",&a2[j]);
	i=0;
	j=0;
	while(i<m&&j<n)
	{
		if(a1[i]<a2[j])
		{
			merge[k]=a1[i];
			i++;
		}
		else
		{
			merge[k]=a2[j];
			j++;
		}
	
	k++;
	}
	while(i<m)
	{
		merge[k]=a1[i];
		i++;
		k++;
	}
	while(j<n)
	{
		merge[k]=a2[j];
		j++;
		k++;
	}
	printf("\n merged array");
	for(i=0;i<m+n;i++)
	printf("%d  ",merge[i]);
	return 0;
	
}
