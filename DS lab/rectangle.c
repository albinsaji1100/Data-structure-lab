#include<stdio.h>
#include<stdlib.h>
void main()
{
int a,p,l,b;
printf("Enter Length and Breadth");
scanf("%d%d",&l,&b);
a=l*b;
p=2*(l+b);
printf("Area and Perimeter of the rectangle is %d and %d respectively",a,p);
}
