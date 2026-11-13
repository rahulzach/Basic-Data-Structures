#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

int a[10], max, i;
int top = -1;

void push()
{
    int item;
    if(top == max - 1)
    {
        printf("the stack is full\n");
    }
    else
    {
        printf("enter item to be pushed\n");
        scanf("%d", &item);
        top = top + 1;
        a[top] = item;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d is popped\n", a[top]);
        top = top - 1;
    }
}

void display()
{
    if(top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        for(i = 0; i <= top; i++)
        {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    printf("Enter max size : ");
    scanf("%d", &max);
    while(1)
    {
        printf("Enter choice:\n 1 push\n 2 pop\n 3 display\n 4 exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4: exit(0);
            default: printf("invalid choice\n");
                break;
        }
    }
}
