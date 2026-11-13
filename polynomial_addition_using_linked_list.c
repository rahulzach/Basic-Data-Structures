#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int degree;
    struct node *next;
} *head1 = NULL, *head2 = NULL, *head3 = NULL,
  *current1 = NULL, *current2 = NULL, *current3 = NULL;

void main()
{
    int r, i;
    struct node *newnode, *ptr1, *ptr2;
    printf("enter the maximum degree");
    scanf("%d", &r);

    printf("enter the details of first polynomial\n");
    for(i = r; i >= 0; i--)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter the coefficient of degree %d\n", i);
        scanf("%d", &newnode->coeff);
        newnode->degree = i;
        newnode->next = NULL;
        if(i == r)
        {
            head1 = newnode;
            current1 = newnode;
        }
        else
        {
            current1->next = newnode;
            current1 = newnode;
        }
    }

    printf("enter the details of second polynomial\n");
    for(i = r; i >= 0; i--)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter the coefficient of degree %d\n", i);
        scanf("%d", &newnode->coeff);
        newnode->degree = i;
        newnode->next = NULL;
        if(i == r)
        {
            head2 = newnode;
            current2 = newnode;
        }
        else
        {
            current2->next = newnode;
            current2 = newnode;
        }
    }

    ptr1 = head1;
    ptr2 = head2;
    for(i = r; i >= 0; i--)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coeff = ptr1->coeff + ptr2->coeff;
        newnode->degree = i;
        newnode->next = NULL;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(i == r)
        {
            head3 = newnode;
            current3 = newnode;
        }
        else
        {
            current3->next = newnode;
            current3 = newnode;
        }
    }

    ptr1 = head1;
    printf("the sum of polynomial ");
    while(ptr1 != NULL)
    {
        if(ptr1->next != NULL)
        {
            printf("%dx^%d+", ptr1->coeff, ptr1->degree);
            ptr1 = ptr1->next;
        }
        else
        {
            printf("%dx^%d and ", ptr1->coeff, ptr1->degree);
            ptr1 = ptr1->next;
        }
    }

    ptr1 = head2;
    while(ptr1 != NULL)
    {
        if(ptr1->next != NULL)
        {
            printf("%dx^%d+", ptr1->coeff, ptr1->degree);
            ptr1 = ptr1->next;
        }
        else
        {
            printf("%dx^%d is\n", ptr1->coeff, ptr1->degree);
            ptr1 = ptr1->next;
        }
    }

    ptr1 = head3;
    while(ptr1 != NULL)
    {
        if(ptr1->next != NULL)
        {
            printf("%dx^%d+", ptr1->coeff, ptr1->degree);
            ptr1 = ptr1->next;
        }
        else
        {
            printf("%dx^%d", ptr1->coeff, ptr1->degree);
            ptr1 = ptr1->next;
        }
    }
}
