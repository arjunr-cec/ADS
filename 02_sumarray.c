#include<stdio.h>
int main()
{
	int a[10],n,i,s=0;
	printf("enter the limit of array:");
	scanf("%d",&n);
	printf("\n enter the array elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\n array elements ");
	for(i=0;i<n;i++)
	printf("%d  ",a[i]);
	for(i=0;i<n;i++)
	s=s+a[i];
	printf("\n sum of array elements:%d",s);
	return 0;
}
