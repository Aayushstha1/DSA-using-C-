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
int isfull(stack*s)
{
  return s->tos==MAX-1;
}
void push(stack*s,char ch)
{
   if(isFull(s))
   {
      printf("Void insertion.");getch();exit(0);
   }
   s->items[++s->tos]=ch;
}
char pop(stack*s)
{
   if(isEmpty(s))
   {
      printf("Void deletion.");getch();exit(0);
   }
   return s->items[s->tos--];
}
char peek(stack*s)
{
   if(isEmpty(s))
   {
     printf("Void access.");getch();exit(0);
   }
   return s->items[s->tos];
}


int get precedence(char ch)
{
    switch(ch)
    {
         case '(': return 0;
    case '+':
    case '-': return 1;
    case '*':
    case '/':
    case '%': return 2;
    case '$': return 3;
    default: return -1;
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
                printf("\ninfix expression: %s",infix);
                printf("\npostfix expression: ")

for(i=0;i<=poststack.tos;i++)
    printf("%c",poststack.items[i]);
  getch();
}




}