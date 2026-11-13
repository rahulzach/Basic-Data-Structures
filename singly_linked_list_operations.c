#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct node
{
    int data;
    struct node *next;
} *head = NULL, *newnode = NULL, *current = NULL, *temp;

void insert_beginning()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data for Node");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    count++;
}

void insert_end()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data for Node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(head == NULL)
        head = newnode;
    else
    {
        current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = newnode;
    }
    count++;
}

void insert_position()
{
    int pos, i;
    printf("Enter the position to enter the new element\n");
    scanf("%d", &pos);
    if(pos < count)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data for Node: ");
        scanf("%d", &newnode->data);
        current = head;
        for(i = 1; i < pos; i++)
        {
            current = current->next;
        }
        temp = current->next;
        current->next = newnode;
        newnode->next = temp;
        count++;
    }
    else
        printf("Enter a Valid Position");
}

void delete_beginning()
{
    if(count > 0)
    {
        current = head;
        head = current->next;
        free(current);
        count--;
    }
    else
        printf("Linked List is Empty\n");
}

void delete_end()
{
    if(count > 1)
    {
        current = head;
        while(current->next->next != NULL)
            current = current->next;
        free(current->next);
        current->next = NULL;
        count--;
    }
    else
        delete_beginning();
}

void delete_position()
{
    int pos, i;
    printf("Enter the position to delete the element\n");
    scanf("%d", &pos);
    if(pos < count)
    {
        current = head;
        for(i = 1; i < pos; i++)
        {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    else
        printf("Enter a Valid Position\n");
}

void display_LL()
{
    if(count > 0)
    {
        current = head;
        printf("\nThe Elements of the Linked List Are:\n");
        while(current != NULL)
        {
            printf("%d\t", current->data);
            current = current->next;
        }
    }
    else
        printf("Linked List is Empty\n");
}

void main()
{
    int choice;
    while(1)
    {
        printf("\nLinked List Operations-Menu:\n");
        printf("1.Insertion at Beginning\n");
        printf("2.Insertion at End\n");
        printf("3.Insertion at Position\n");
        printf("4.Deletion at Beginning\n");
        printf("5.Deletion at End\n");
        printf("6.Deletion at Position\n");
        printf("7.Display the Linked List\n");
        printf("8.Exit Program\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert_beginning();
                break;
            case 2: insert_end();
                break;
            case 3: insert_position();
                break;
            case 4: delete_beginning();
                break;
            case 5: delete_end();
                break;
            case 6: delete_position();
                break;
            case 7: display_LL();
                break;
            case 8: exit(0);
            default: printf("Wrong Choice Entered\n");
        }
    }
}
