#include<stdio.h>
#include<stdlib.h>
void main()
{
int a,b,temp;
printf("Enter Two numbers");
scanf("%d%d",&a,&b);
printf("Before swapping: %d and %d",a,b);
temp=a;
a=b;
b=temp;
printf("\nAfter swapping: %d and %d",a,b);
}
