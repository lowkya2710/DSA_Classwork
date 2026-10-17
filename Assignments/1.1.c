#include<stdio.h>
int main()
{
 int arr[20];
 int i,j;
 printf("enter array numbers: ");
 for(i=0;i<20;i++)
 scanf("%d",&arr[i]);
 for(i=0;i<20;i++)
 printf("array numbers: %d \n", arr[i]);
 int n;
 printf("number to be deleted:  ");
 scanf("%d",&n);
 for(i=0;i<20;i++)
 {
   if (n==arr[i])
   {
    j=i;
    while (j<20)
    {
    arr[j]=arr[j+1];
    j++;
    }
 for(i=0;i<19;i++)
 printf("%d", arr[i]);
 }
 }
 }
