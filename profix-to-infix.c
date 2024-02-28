#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define Max 100
#define true 1
#define false 0
type def struct 
{
    char items [Max];
    int tns;

}stack;
int isempty (stack*s)
{
    return s->tns==-1;
}
int isfull(stack)


int get precedence(char ch)
{
    switch(ch)
    {
        case 'c': return 0;
        case '+'
    }
}
void main()
{
    stack opstack, poststack;
    char infix[Max],ch;
    int i;
    opstack.tos=poststack.tos=-1;
    clrscr();
    printf("Enter your infix expression");
    gets(infix);
    for(i=0;i<strlen(infix);i++)
    {
        ch=infix[i];
        if(ch=='(')
        push(&opstack,ch);
        else if (isalnum(ch))
        push (&poststack,ch);
        else if (ch==')')
        {
            while(peek(&opstcak)!='c')
            push ( &poststack, pop(&opstack));
            pop(&opstack);
        }
        else 
        {
            while(getprecedence(peek(&opstack))>=getprecedence(ch))
            push (&popstack,pop(&opstack));
            push(&opstack,ch);

        }
    }
    while(!isempty (&opstack))
                push (&popstack,pop(&opstack));
                printf("\ninfix expression: %s", infix);
                printf("\npostfix expression: )
                



}