#include<stdio.h>
#include<conio.h>
int sum(int n)
{
    if(n<=0)
    return 0;
else 
return n+sum(n-1);

}
void main()
{
    int n;
    clrscr();
    printf("how many number you want to sum:\n");
    scanf("%d",&n);
    printf("Sum of %d number is: %d", n,sum(n));
    getch();
}