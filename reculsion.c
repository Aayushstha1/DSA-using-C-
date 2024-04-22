#include<stdio.h>
#include<conio.h>
void toh(int n, char source, char temp,char dest)
{
    if(n==1)
    printf("\nMove disk%d from %c to %c",n,source,dest);
else
{
    toh(n-1,source,dest,temp);
    printf("\nMove disk%d from %c to %c",source,dest);
    toh(n-1,temp,source,dest);
}
}
void main()
{
    int n;
    clrscr();
    printf("enter the number od disk");
    scanf("%d, &n");
    toh(n,'A','B','C');
    getch();
}