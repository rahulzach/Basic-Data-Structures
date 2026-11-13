#include<stdio.h>
#include<stdlib.h>

struct node
{
    int rollno;
    char name[20];
    struct node *next;
} *head = NULL, *current = NULL;

void enqueue();
void dequeue();
void traverse();

void main()
{
    int choice, w;
    do
    {
        printf("1-enqueue\n2-dequeue\n3-traverse\n");
        printf("enter your choice");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: traverse();
                break;
            default: printf("your choice is wrong\n");
                break;
        }
        printf("do you want to continue if yes enter 1");
        scanf("%d", &w);
    } while(w == 1);
}

void enqueue()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the rollno ");
    scanf("%d", &newnode->rollno);
    printf("enter the name ");
    scanf("%s", newnode->name);
    newnode->next = NULL;
    if(head != NULL)
    {
        current->next = newnode;
        current = newnode;
    }
    else
    {
        head = newnode;
        current = newnode;
    }
}

void dequeue()
{
    struct node *ptr;
    if(head != NULL)
    {
        ptr = head;
        printf("dequeued: name-%s rollno-%d\n", ptr->name, ptr->rollno);
        head = head->next;
        free(ptr);
        if(head == NULL)
        {
            printf("now the queue become empty\n");
        }
    }
    else
    {
        printf("the queue is empty\n");
    }
}

void traverse()
{
    struct node *ptr;
    ptr = head;
    if(head != NULL)
    {
        printf("the details of students are\n");
        while(ptr != NULL)
        {
            printf("name-%s\nrollno-%d\n", ptr->name, ptr->rollno);
            ptr = ptr->next;
        }
    }
    else
        printf("empty queue ");
}
