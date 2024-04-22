int fib (int n)
{
    if(n==1)
    return 0;
else if (n==2)
return 1;
else
return fib(n-2)+fib(n-1);
}
void main()
{
    int i;
    clrscr();
    printf("sequence:\n");
    for(i=1; i<=10; i++)
    printf("%d\t", fib(i));
getch();
}