#include<stdio.h>
#include<conio.h>
int digitSum(int n)
{
    if(n<10)
    return n;
else 
return n%10+digitSum(n/10);

}
void main()
{
    int n;
    printf("Enter the number");
    scanf("%d", &n);
    printf("sum of digit of %d is %d.",n,digitSum(n));
getch();
}